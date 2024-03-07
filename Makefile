OBJ_FILES = mainTestDeplacement.o Monde.o Deplacement.o
CFLAGS = -Wall -ggdb
LIBS = -lSDL2

all: mainTest

mainTest: $(OBJ_FILES)
	g++ obj/mainTestDeplacement.o obj/Monde.o obj/Deplacement.o -o bin/mainTest

mainTestDeplacement.o: src/mainTestDeplacement.cpp Monde.o Deplacement.o
	g++ $(CFLAGS) -c src/mainTestDeplacement.cpp -o obj/mainTestDeplacement.o

Carte.o: src/Carte.cpp src/Case.h
	g++ $(CFLAGS) -c src/Carte.cpp -o obj/Carte.o

Monde.o: src/Monde.cpp src/Carte.h
	g++ $(CFLAGS) -c src/Monde.cpp -o obj/Monde.o

Deplacement.o: src/Deplacement.cpp src/Monde.h
	g++ $(CFLAGS) -c src/Deplacement.cpp -o obj/Deplacement.o

Personnage.o: src/Personnage.cpp
	g++ $(CFLAGS) -c src/Personnage.cpp -o obj/Personnage.o


clean:
	rm $(OBJ_FILES)
