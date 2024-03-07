EXEC_NAME = test
OBJ_FILES = main.o maClasse.o
CFLAGS = -Wall -ggdb
LIBS = -lSDL2


all: $(EXEC_NAME)


$(EXEC_NAME): $(OBJ_FILES)
g++ $(OBJ_FILES) -o $(EXEC_NAME) $(LIBS)


main.o: main.cpp maClasse.h
g++ $(CFLAGS) -c main.cpp

Carte.o: src/Carte.cpp src/Case.h
g++ $(CFLAGS) -c obj/Carte.o

Monde.o: src/Monde.cpp src/Carte.h
g++ $(CFLAGS) -c obj/Monde.o

Deplacement.o: src/Deplacement.cpp src/Monde.h
g++ $(CFLAGS) -c obj/Deplacement.o

Personnage.o: src/Personnage.cpp
g++ $(CFLAGS) -c obj/Personnage.o


clean:
rm $(OBJ_FILES)
