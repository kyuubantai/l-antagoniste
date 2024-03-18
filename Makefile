OBJ_FILES = Monde.o Deplacement.o winTxt.o JeuTxt.o mainTxt.o
CFLAGS = -Wall -ggdb
LIBS = -lSDL2

all: mainTest

mainTest: $(OBJ_FILES)
	g++ obj/winTxt.o obj/Monde.o obj/Deplacement.o obj/JeuTxt.o obj/mainTxt.o -o bin/mainTest

Carte.o: src/Carte.cpp src/Case.h
	g++ $(CFLAGS) -c src/Carte.cpp -o obj/Carte.o

Monde.o: src/Monde.cpp src/Carte.h
	g++ $(CFLAGS) -c src/Monde.cpp -o obj/Monde.o

Deplacement.o: src/Deplacement.cpp src/Monde.h
	g++ $(CFLAGS) -c src/Deplacement.cpp -o obj/Deplacement.o

JeuTxt.o: src/JeuTxt.cpp src/Deplacement.h src/winTxt.h
	g++ $(CFLAGS) -c src/JeuTxt.cpp -o obj/JeuTxt.o

winTxt.o: src/winTxt.cpp 
	g++ $(CFLAGS) -c src/winTxt.cpp -o obj/winTxt.o

mainTxt.o: src/mainTxt.cpp obj/JeuTxt.o obj/winTxt.o
	g++ $(CFLAGS) -c src/mainTxt.cpp -o obj/mainTxt.o


clean:
	rm $(OBJ_FILES)
