gflags=gcc -Wall -Werror -Wextra

all: door_struct list_test
door_struct: door_struct.h dmanager_module.c
	$(gflags) dmanager_module.c -o ../build/Quest_1

list_test: door_struct.h list.c list.h
	$(gflags) list.c list_test.c -o ../build/Quest_2

clean:
	rm ../build/*

rebuild: clean all
