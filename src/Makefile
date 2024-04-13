OBJ_FILES = mainTest.o Competence.o Ennemi.o Combat.o
CFLAGS = -Wall -ggdb
all: test

test: $(OBJ_FILES)
	g++ obj/mainTest.o  obj/Competence.o  obj/Ennemi.o obj/Combat.o -o bin/test


Competence.o: src/Competence.cpp src/Competence.h
	g++ $(CFLAGS) -c src/Competence.cpp -o obj/Competence.o

Ennemi.o: src/Ennemi.cpp src/Personnage.h
	g++ $(CFLAGS) -c src/Ennemi.cpp -o obj/Ennemi.o

Combat.o: src/Combat.cpp src/Heros.h src/Ennemi.h src/Competence.h
	g++ $(CFLAGS) -c src/Combat.cpp -o obj/Combat.o

mainTest.o: src/mainTest.cpp src/Heros.h src/Combat.h
	g++ $(CFLAGS) -c src/mainTest.cpp -o obj/mainTest.o

clean:	
	rm $(OBJ_FILES)
