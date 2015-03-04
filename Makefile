CC = gcc


all:
	$(CC) ext.c main.c -std=c99 -ldl -o ext_skel

ext:
	$(CC) myext.c -shared -fPIC -o myext.so
