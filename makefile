all:
	gcc -o control controller.c

run: all
	./control -c 6
	./control -v
	./control -r

gdb: all
	gdb control

clean:
	rm *~
	clear

cleanall:
	rm control
	rm *~
	clear
