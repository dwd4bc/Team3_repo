import os, sys, shutil

def rename(src,dst):
	"""renames file or directory src to dst and returns True if successful"""
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

def move(src,dst):
	"""moves the file or directory src to the directory dst and returns True if successful"""
	#if os.access
	try:
		shutil.move(src,dst)
		return True
	except OSError, e:
		print e
        	return False
	except shutil.Error, e:
		print e
		return False

def copy(src,dst):
	if os.path.isfile(src):
		try:
			shutil.copy2(src,dst)
			return True
		except OSError, e:
			print e
			return False
		except shutil.Error, e:
			print e
			return False

	elif os.path.isdir(src):
		if os.path.isfile(dst) or os.path.isdir(dst):
			print "Destination path already exists -- cannot overwrite directory"
			return False
		else:
			try:
				shutil.copytree(src,dst)
				return True
			except OSError, e:
				print e
				return False
			except shutil.Error, e:
				print e
				return False
	else:
		print "%s does not exist" % src
		return False

def delete(path):
	if os.path.isdir(path):	
		try:
			shutil.rmtree(path)
			return True
		except OSError, e:
			print e
		        return False
		except shutil.Error, e:
			print e
			return False

	elif os.path.isfile(path):
		try:
			os.remove(path)
			return True
		except OSError, e:
			print e
		        return False

	else:
		print "%s does not exist" % path
		return False


def create(path): 
	if not os.path.exists(path):
		try:	
			os.makedirs(path)
			return True
		except OSError, e: 
			print e
			return False
	else:
		print "%s already exists" % path
		return False

def clean_and_split_input(input):
    """ Removes carriage return and line feed characters and splits input on a single whitespace. """
    
    input = input.strip()
    input = input.split(' ')
        
    return input

COMMANDS = {
            'rename': ('rename <source path> <new name>', 'renames <source path> with <new path name>'),
            'move': ('move <source path> <destination path>', 'moves <source path> to the directory <destination path>'),
            'copy': ('copy <source path> <destination path>', 'copies <source path> to the directory <destination path>'),
            'delete': ('delete <path>', 'deletes the file or directory given by <path>'),
            'create': ('create <path>', 'creates the file or directory given by <path>'),
	    'done' : ('done', 'exits directory management'),
	    'help' : ('help', 'lists available operations'),
	    
}

def main():

	print "Type help for list of available commands"
	while(True):
		
		src_path = '';
		dst_path = '';
		input = raw_input("Enter a command: ")
		input = clean_and_split_input(input)

		# return if data is empty
		if len(input) == 0 or input == '':
			return 
		elif len(input) == 2:
			src_path = input[1]
		elif len(input) == 3:
			src_path = input[1]
			dst_path = input[2]
		else:
			pass
		

		# convert to lowercase
		command = input[0].lower()

		if not command in COMMANDS:
			print('Invalid command')

		
		if command == 'done':
			return
		elif command == 'help':
			for key, value in COMMANDS.iteritems():
				print('%s - %s' % (value[0], value[1]))
		elif command == 'rename':
			rename(src_path, dst_path)
		elif command == 'move':
			move(src_path, dst_path)
		elif command == 'copy':
			copy(src_path, dst_path)
		elif command == 'delete':
			delete(src_path)
		elif command == 'create':
			create(src_path)



if __name__ == '__main__':
	main()






