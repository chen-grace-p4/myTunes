all: main.o myTunes.o tunesList.o
	gcc -o program main.o myTunes.o tunesList.o
main.o: main.c myTunes.h tunesList.h
	gcc -c main.c
myTunes.o: myTunes.c myTunes.h
	gcc -c myTunes.c
tunesList.o: tunesList.c tunesList.h
  gcc -c tunesList.c
run:
	./program 
clean:
	rm *.o