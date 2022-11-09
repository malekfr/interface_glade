prog:gestionbv.o main.o
	gcc gestionbv.o main.o -o prog
main.o:main.c
	gcc -c main.c
gestionbv.o:gestionbv.c
	gcc -c gestionbv.c

