prog: main.c event.so focmath.so
	gcc main.c event.so focmath.so -lSDL2 -lm -o prog

event.so: event.c event.h
	gcc -c event.c -lSDL2 -o event.so

focmath.so: focmath.c focmath.h
	gcc -c focmath.c -lSDL2 -lm -o focmath.so

lancer: prog
	./prog