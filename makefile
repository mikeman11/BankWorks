#--------------------------------------------------------------

CC=gcc
FLAGS=-Wall -g
AR=ar

#--------------------------------------------------------------

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o:
	$(CC) $(FLAGS) -c  myBank.c

main.out: main.o libmyBank.a 
	$(CC) $(FLAGS) main.o libmyBank.a -o main.out

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o 

#--------------------------------------------------------------

.PHONY: myBanks main all clean

# Creating static library
myBanks: myBank.o  libmyBank.a

all: main.out 
    
clean:
	rm myBank.o libmyBank.a main.o main.out

#------------------------------------------------------------