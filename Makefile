OBJ_FILES = Monde.o Deplacement.o winTxt.o JeuTxt.o mainTxt.o
OBJ_AFF = Monde.o Deplacement.o Jeu.o mainJeu.o GestionImage.o
CFLAGS = -Wall -ggdb
LIBS = -lSDL2

all: mainTest aff

mainTest: $(OBJ_FILES)
	g++ obj/winTxt.o obj/Monde.o obj/Deplacement.o obj/JeuTxt.o obj/mainTxt.o -o bin/mainTest

aff: $(OBJ_AFF)
	g++ obj/Monde.o obj/Deplacement.o obj/GestionImage.o obj/Jeu.o obj/mainJeu.o -o bin/mainAff -lSDL2 -lSDL2_image

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

GestionImage.o : src/GestionImage.cpp src/GestionImage.h
	g++ $(CFLAGS) -c src/GestionImage.cpp -o obj/GestionImage.o
	
Jeu.o : src/Jeu.cpp src/Jeu.h
	g++ $(CFLAGS) -c src/Jeu.cpp -o obj/Jeu.o	

mainJeu.o : src/mainJeu.cpp obj/Jeu.o
	g++ $(CFLAGS) -c src/mainJeu.cpp -o obj/mainJeu.o


clean:
	rm $(OBJ_FILES) $(OBJ_AFF)