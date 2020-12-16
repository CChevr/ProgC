CC=gcc
CFLAGS=-ansi -Wall
LIBS=-lreadline
OBJ=Main.o Lecture.o Operations.o Outils.o Pile.o

dc: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)
Main.o: Main.c Pile.h Lecture.h Operations.h
	$(CC) -c $< $(CFLAGS)
Operations.o: Operations.c Operations.h  Lecture.h Pile.h Outils.h
	$(CC) -c $< $(CFLAGS)
Lecture.o: Lecture.c Lecture.h
	$(CC) -c $< $(CFLAGS)
Pile.o: Pile.c Pile.h
	$(CC) -c $< $(CFLAGS)
Outils.o: Outils.c Outils.h
	$(CC) -c $< $(CFLAGS)
	
clean:
	rm -f *.o

mrproper: clean
	rm -f dc