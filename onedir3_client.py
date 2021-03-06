
#!/usr/bin/env python

'''
Author: Team 3 OneDir, CS 3240 At The University Of Virginia Spring 2014
Ty Dang, Sravan Tumuluri, Piyapath Siratarnsophon, Dylan Doggett
'''

import os, sys, shutil
import optparse
from twisted.internet import reactor, protocol, stdio, defer
from twisted.protocols import basic
from twisted.internet.protocol import ClientFactory
from common import COMMANDS, display_message, validate_file_md5_hash, get_file_md5_hash, read_bytes_from_file, clean_and_split_input

HOST = '127.0.0.1'
PORT = 8123
DIRECTORY = '/home/student/testonedirlocal'

# File transfer code down below
class OnedirProtocol(basic.LineReceiver):
    delimiter = '\n'
    
    def __init__(self, server_ip, server_port, files_path):
        self.server_ip = server_ip
        self.server_port = server_port
        self.files_path = files_path
    
    def connectionMade(self):  
        self.factory = FileTransferClientFactory(self.files_path)
        self.connection = reactor.connectTCP(self.server_ip, self.server_port, self.factory)
        self.factory.deferred.addCallback(self._display_response)
        
    def lineReceived(self, line):
        """ If a line is received, call sendCommand(), else prompt user for input. """
        
        if not line:
            self._prompt()
            return
        
        self._sendCommand(line)
        
    def _sendCommand(self, line):
        """ Sends a command to the server. """
        
        data = clean_and_split_input(line) 
        if len(data) == 0 or data == '':
            return 

        command = data[0].lower()
        if not command in COMMANDS:
            self._display_message('Invalid command')
            return
        
        if command == 'list' or command == 'help' or command == 'quit':
            self.connection.transport.write('%s\n' % (command))

	elif command == 'register':
	    try:
		username = data[1]
		password = data[2]
	    except IndexError:
                self._display_message('Missing username or password')
		return
            self.connection.transport.write('%s %s %s\n' % (command, username, password))

	elif command == 'login':
	    try:
		username = data[1]
		password = data[2]
	    except IndexError:
                self._display_message('Missing username or password')
		return
            self.connection.transport.write('%s %s %s\n' % (command, username, password))

        elif command == 'get':
            try:
                filename = data[1]
            except IndexError:
                self._display_message('Missing filename')
                return
            
            self.connection.transport.write('%s %s\n' % (command, filename))
        elif command == 'put':
            try:
                file_path = data[1]
                filename = data[2]
            except IndexError:
                self._display_message('Missing local file path or remote file name')
                return
            
            if not os.path.isfile(file_path):
                self._display_message('This file does not exist')
                return

            file_size = os.path.getsize(file_path) / 1024
            
            print 'Uploading file: %s (%d KB)' % (filename, file_size)
            
            self.connection.transport.write('PUT %s %s\n' % (filename, get_file_md5_hash(file_path)))
            self.setRawMode()
            
            for bytes in read_bytes_from_file(file_path):
                self.connection.transport.write(bytes)
            
            self.connection.transport.write('\r\n')   
            
            # When the transfer is finished, we go back to the line mode 
            self.setLineMode()
        elif command == 'rename':
            """renames file or directory src to dst and returns True if successful"""
            src = '';
            dst = '';
            input = clean_and_split_input(line)
            if len(input) == 3:
                src = input[1];
                dst = input[2];
            if os.path.isfile(src) or os.path.isdir(src):
                try:
                    os.renames(src,dst)
                    return True
		except OSError, e:
                    print e
                    return False
            else: 
		print "%s does not exist" % src
		return False
        elif command == 'delete':
            src = '';
            input = clean_and_split_input(line)
            if len(input) == 2:
                src = input[1];
            if os.path.isdir(src):	
		try:
                    shutil.rmtree(src)
                    return True
		except OSError, e:
                    print e
                    return False
		except shutil.Error, e:
                    print e
                    return False
            elif os.path.isfile(src):
		try:
                    os.remove(src)
                    return True
		except OSError, e:
                    print e
                    return False
            else:
		print "%s does not exist" % src
		return False
        elif command == 'create':
            src = '';
            input = clean_and_split_input(line)
            if len(input) == 2:
                src = input[1];
            if not os.path.exists(src):
		try:	
                    os.makedirs(src)
                    return True
		except OSError, e: 
                    print e
                    return False
            else:
                print "%s already exists" % src
		return False
        else:
            self.connection.transport.write('%s %s\n' % (command, data[1]))

        self.factory.deferred.addCallback(self._display_response)
        
    def _display_response(self, lines = None):
        """ Displays a server response. """
        
        if lines:
            for line in lines:
                print '%s' % (line)
            
        self._prompt()
        self.factory.deferred = defer.Deferred()
        
    def _prompt(self):
        """ Prompts user for input. """
        self.transport.write('> ')
        
    def _display_message(self, message):
        """ Helper function which prints a message and prompts user for input. """
        
        print message
        self._prompt()    

class FileTransferProtocol(basic.LineReceiver):
    delimiter = '\n'

    def connectionMade(self):
        self.buffer = []
        self.file_handler = None
        self.file_data = ()
        
        print 'Connected to the server'
        
    def connectionLost(self, reason):
        self.file_handler = None
        self.file_data = ()
        
        print 'Connection to the server has been lost'
        reactor.stop()
    
    def lineReceived(self, line):
        if line == 'ENDMSG':
            self.factory.deferred.callback(self.buffer)
            self.buffer = []
        elif line.startswith('HASH'):
            # Received a file name and hash, server is sending us a file
            data = clean_and_split_input(line)

            filename = data[1]
            file_hash = data[2]
            
            self.file_data = (filename, file_hash)
            self.setRawMode()
        else:
            self.buffer.append(line)
        
    def rawDataReceived(self, data):
        filename = self.file_data[0]
        file_path = os.path.join(self.factory.files_path, filename)
        
        print 'Receiving file chunk (%d KB)' % (len(data))
        
        if not self.file_handler:
            self.file_handler = open(file_path, 'wb')
            
        if data.endswith('\r\n'):
            # Last chunk
            data = data[:-2]
            self.file_handler.write(data)
            self.setLineMode()
            
            self.file_handler.close()
            self.file_handler = None
            
            if validate_file_md5_hash(file_path, self.file_data[1]):
                print 'File %s has been successfully transfered and saved' % (filename)
            else:
                os.unlink(file_path)
                print 'File %s has been successfully transfered, but deleted due to invalid MD5 hash' % (filename)
        else:
            self.file_handler.write(data)

class FileTransferClientFactory(protocol.ClientFactory):
    protocol = FileTransferProtocol
    
    def __init__(self, files_path):
        self.files_path = files_path
        self.deferred = defer.Deferred()

if __name__ == "__main__":
    if len(sys.argv) > 1:
        HOST = sys.argv[1]
    print "Connecting to (HOST, PORT): ", (HOST, PORT)
    print "Welcome to Team 3's OneDir! How may we help you?"

    parser = optparse.OptionParser()
    parser.add_option('--ip', action = 'store', type = 'string', dest = 'ip_address', default = HOST, help = '137.54.12.144')
    parser.add_option('-p', '--port', action = 'store', type = 'int', dest = 'port', default = PORT, help = 'server port')
    parser.add_option('--path', action = 'store', type = 'string', dest = 'path', default = DIRECTORY, help = 'directory where the incoming files are saved')
    
    (options, args) = parser.parse_args()

    print 'Client started, incoming files will be saved to %s' % (options.path)
    
    stdio.StandardIO(OnedirProtocol(options.ip_address, options.port, options.path))
    reactor.run()
