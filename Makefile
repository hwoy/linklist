cc = gcc
CFLAGS = -O2 -std=c89 -pedantic -Wall
bin = test
lib = linklist
.PHONY: $(bin) clean

all: $(bin)
$(bin):	main.o $(lib).a
	$(cc) -o $(bin) main.o $(lib).a
main.o:	main.c
	$(cc) -c $(CFLAGS) -o main.o main.c
	
$(lib).a:	linklistx.o linklisty.o linklistc.o
	ar rc $(lib).a linklistx.o linklisty.o linklistc.o
linklistx.o:	linklistx.c
	$(cc) -c $(CFLAGS) -o linklistx.o linklistx.c
	
linklisty.o:	linklisty.c
	$(cc) -c $(CFLAGS) -o linklisty.o linklisty.c
	
linklistc.o:	linklistc.c
	$(cc) -c $(CFLAGS) -o linklistc.o linklistc.c
clean:
	rm -f *.o $(bin) *.a
