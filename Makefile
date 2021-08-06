
all:
	gcc -g -c arn/arn.c
	gcc -g -c arn/arn.h
	gcc -g -c ordenacao/bs.c
	gcc -g -c ordenacao/bs.h
	gcc -g -c lista/lista.c
	gcc -g -c lista/lista.h
	gcc -g -c main.c
	gcc -g *.o -o main