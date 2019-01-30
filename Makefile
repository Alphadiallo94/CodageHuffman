# compilateur
CC := gcc
# options de compilation
CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb 

# règle de compilation --- exécutables
LIBS:= -lm
all : main

main : main.o  modelABR.o operations.o listeABR.o listeCode.o
	$(CC) $(CFLAGS) -o $@   $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

# options de compilation
clean:
	rm *.o main
