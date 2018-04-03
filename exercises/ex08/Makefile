# CC = gcc
# CFLAGS = -g -Wall -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
# LIBS = lglib-2.0
#
#
# ex_compile: ex_compile.c
# 	$(CC) ex_compile.c -o ex_compile
# word_count: word_count.c
# 	$(CC) word_count.c -o word_count

all: ex_compile word_count
ex_compile: ex_compile.c
	gcc ex_compile.c -Wall -o ex_compile `pkg-config --cflags --libs glib-2.0`
word_count: word_count.c
	gcc word_count.c -Wall -o word_count `pkg-config --cflags --libs glib-2.0`
