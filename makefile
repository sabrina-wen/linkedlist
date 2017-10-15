all: my_linked_list.c
	gcc -o mll my_linked_list.c

run: all
	./mll
