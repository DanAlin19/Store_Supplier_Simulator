# Declaratiile de variabile
CC = gcc
CFLAGS = -g -Wall -lm -std=c11
 
# Regula de compilare
all: build

build: tema3.c
	$(CC) tema3.c function.c -o tema3 $(CFLAGS) 

# Regulile de "curatenie" (se folosesc pentru stergerea fisierelor intermediare si/sau rezultate)
.PHONY : clean
clean :
	rm -f tema3
	rm -f *.out