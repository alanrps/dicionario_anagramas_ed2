
all:
	gcc -g -c auxiliares/auxiliares.c
	gcc -g -c arn/arn.c
	gcc -g -c ordenacao/bs.c
	gcc -g -c lista/lista.c
	gcc -g -c main.c
	gcc -g *.o -o main