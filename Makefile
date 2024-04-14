OBJ_FILES = Monde.o Deplacement.o winTxt.o JeuTxt.o mainTxt.o
OBJ_AFF = Monde.o Deplacement.o Jeu.o mainJeu.o GestionImage.o
OBJ_VS = mainTestCombat.o Competence.o Ennemi.o Heros.o Combat.o
CFLAGS = -Wall -ggdb
LIBS = -lSDL2 -lSDL2_image

all: mainTxt aff testCombat

mainTxt: $(OBJ_FILES)
	g++ obj/winTxt.o obj/Monde.o obj/Deplacement.o obj/JeuTxt.o obj/mainTxt.o -o bin/mainTxt

aff: $(OBJ_AFF)
	g++ obj/Monde.o obj/Deplacement.o obj/GestionImage.o obj/Jeu.o obj/mainJeu.o -o bin/mainAff $(LIBS)

testCombat: $(OBJ_VS)
	g++ obj/mainTestCombat.o obj/Competence.o obj/Ennemi.o obj/Heros.o obj/Combat.o -o bin/testCombat

Carte.o: src/Carte.cpp src/Case.h
	g++ $(CFLAGS) -c src/Carte.cpp -o obj/Carte.o

Monde.o: src/Monde.cpp src/Carte.h
	g++ $(CFLAGS) -c src/Monde.cpp -o obj/Monde.o

Deplacement.o: src/Deplacement.cpp src/Monde.h
	g++ $(CFLAGS) -c src/Deplacement.cpp -o obj/Deplacement.o

Competence.o: src/Competence.cpp src/Competence.h
	g++ $(CFLAGS) -c src/Competence.cpp -o obj/Competence.o

Ennemi.o: src/Ennemi.cpp src/Personnage.h
	g++ $(CFLAGS) -c src/Ennemi.cpp -o obj/Ennemi.o

Heros.o: src/Heros.cpp src/Heros.h
	g++ $(CFLAGS) -c src/Heros.cpp -o obj/Heros.o

Combat.o: src/Combat.cpp src/Heros.h src/Ennemi.h src/Competence.h
	g++ $(CFLAGS) -c src/Combat.cpp -o obj/Combat.o

mainTestCombat.o: src/mainTestCombat.cpp src/Heros.h src/Combat.h
	g++ $(CFLAGS) -c src/mainTestCombat.cpp -o obj/mainTestCombat.o

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