# sqlite-execute-module

Brain-dead simple sqlite execute module to aid in the RCE in SQLite instances that allow load_extension SQL function under Linux.

Once loaded you you will have the "execute" function available in SQL that will pass along any command you specify as parameter to a stdlib's os.system() call. This can be change to whatever you want but serves the purpose to demostrate how easy is to do it.

To be able to use this you need to:

1. Be able to upload arbitraty files or place where the sqlite process can access it (this compiled module)
2. Have a working SQL injection vulnerability


For security reasons, and by default, [SQLite does NOT allow to use the function load_extension in SQL](https://www.sqlite.org/c3ref/load_extension.html). 
If you somehow manage to find an instance that does allow it and you can put this file somewhere were the process using the SQLite DB can reach, then you can load it with and injection, like:


```SQL
UNION SELECT 1,load_extension('/path/to/sql-execute-module.so');--

```

You can name the compiled module whatever you like, extension does not matter.


After you load it you can for example (you get to figure out what to do and how to inject it):

```SQL
select execute("ls");

```

Beware that this is  SQL function, so if you use it in an injection it might execute numerous times, be careful. 
Also, this is just a very lame and simple PoC that I did for a small part of a pentest, and using it will be very visible in logs, this can be easily converted to include a reverse shell payload or whatever you like. As always, be nice.



