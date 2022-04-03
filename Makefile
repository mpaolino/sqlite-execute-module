all: sqlite-execute-module

sqlite-execute-module:
	gcc -s -g -fPIC -shared sqlite-execute-module.c -o sqlite-execute-module.so

