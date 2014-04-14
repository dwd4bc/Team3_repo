__author__ = 'Dylan Doggett'

import sqlite3 as lite
import sys

# run -- sqlite3 onedir.db < ondir_create_table -- in shell

def print_version_demo():
    con = None

    try:
        # connect() returns a connection object
        con = lite.connect('onedir.db')
        # cursor() returns a cursor object
        # cursor is used to traverse the records from the result set
        cur = con.cursor()
        cur.execute('SELECT SQLITE_VERSION()')
        # fetchone gets the next row of the query result set
        data = cur.fetchone()
        # print data
        print "SQLite version: %s" % data

    except lite.Error, e:

        print "Error %s:" % e.args[0]
        sys.exit(1)

    finally:
        # closes connection to database
        if con:
            con.close()

def register_user(u,p):
    returnValue = ' '
    u = (u + ' ').strip()
    p = (p + ' ').strip()

    con = lite.connect('onedir.db')

    with con:
	
	con.row_factory = lite.Row
        cur = con.cursor()

        #cur.execute("DROP TABLE IF EXISTS onedir_login")
        cur.execute("CREATE TABLE IF NOT EXISTS onedir_login(username TEXT, password TEXT)")

	sql_cmd =  "SELECT * FROM onedir_login"
        cur.execute(sql_cmd)
        rows = cur.fetchall()

        does_not_exist_flag = True
        for row in rows:
            username = (row["username"] + ' ').strip()
            if row is None: 
                break
            if (username == u):
                does_not_exist_flag = False
                break
	# if the username does not exists
        if does_not_exist_flag == True:
            returnValue = "user %s has been created" % u
            sql_cmd = "INSERT INTO onedir_login VALUES(?, ?)"
            cur.execute(sql_cmd, (u, p))
	else:
	    returnValue = "user %s already exists" % u	    

    return returnValue



def retrieve_login_info():
    con = lite.connect("onedir.db")
    with con:
        # select a dictionary cursor
        # this allows you to access records by names of columns
        con.row_factory = lite.Row
        cur = con.cursor()
        cur.execute("SELECT * FROM onedir_login")
        rows = cur.fetchall()
        print rows, "\n"
        for row in rows:
            print "%s %s" % (row["username"], row["password"])

def login(u,p):
    returnValue = ' '
    u = (u + ' ').strip()
    p = (p + ' ').strip()
   # u = u[:-1]

    con = lite.connect("onedir.db")
    with con:
        # select a dictionary cursor
        # this allows you to access records by names of columns
        con.row_factory = lite.Row
        cur = con.cursor()


        sql_cmd =  "SELECT * FROM onedir_login"
        cur.execute(sql_cmd)
        rows = cur.fetchall()
        flag = False
        for row in rows:
            username = (row["username"] + ' ').strip()
            if row is None:
                returnValue = "username not found"
                flag = True
                break
            if (username == u and row["password"] == p):
                returnValue = "Logged In"
                flag = True
                break
            if (username == u and row["password"] != p):
                returnValue = "invalid password"
                flag = True
                break
        if flag == False:
            returnValue = "username not found"

    return returnValue

def main():
    print register_user("dwd4bc", "1")
    retrieve_login_info()
    #print login("dwd4bc", "1")

if __name__ == '__main__':
    main()
