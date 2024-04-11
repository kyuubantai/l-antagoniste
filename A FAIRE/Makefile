OBJ_FILES = mainTest.o Competence.o Ennemi.o Combat.o
CFLAGS = -Wall -ggdb
all: test

test: $(OBJ_FILES)
	g++ obj/mainTest.o  obj/Competence.o  obj/Ennemi.o obj/Combat.o -o bin/test


Competence.o: AFAIRE/Competence.cpp AFAIRE/Competence.h
	g++ $(CFLAGS) -c AFAIRE/Competence.cpp -o obj/Competence.o

Ennemi.o: AFAIRE/Ennemi.cpp AFAIRE/Personnage.h
	g++ $(CFLAGS) -c AFAIRE/Ennemi.cpp -o obj/Ennemi.o

Combat.o: AFAIRE/Combat.cpp AFAIRE/Heros.h AFAIRE/Ennemi.h AFAIRE/Competence.h
	g++ $(CFLAGS) -c AFAIRE/Combat.cpp -o obj/Combat.o

mainTest.o: AFAIRE/mainTest.cpp AFAIRE/Heros.h AFAIRE/Combat.h
	g++ $(CFLAGS) -c AFAIRE/mainTest.cpp -o obj/mainTest.o

clean:	
	rm $(OBJ_FILES)
