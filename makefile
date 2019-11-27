CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_BANK=myBank.o
FLAGS= -Wall -fPIC

all: mybankd mybanks mains maind
mains: $(OBJECTS_MAIN) mybanks
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) mybanks
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./mybankd
mybankd: $(OBJECTS_BANK)
	$(CC) -shared -o mybankd $(OBJECTS_BANK)
mybanks: $(OBJECTS_BANK)
	$(AR) -rcs mybanks $(OBJECTS_BANK)
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maind mybankd mybanks
