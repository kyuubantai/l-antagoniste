EXEC_NAME = test
OBJ_FILES = main.o maClasse.o
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include
LIBS = -L./extern/lib -luneLib


all: $(EXEC_NAME)


$(EXEC_NAME): $(OBJ_FILES)
g++ $(OBJ_FILES) -o $(EXEC_NAME) $(LIBS)


main.o: main.cpp maClasse.h
g++ $(CFLAGS) $(INCLUDES) -c main.cpp

Carte.o: src/Carte.cpp src/Case.h
g++ $(CFLAGS) $(INCLUDES) -c obj/Carte.o

Monde.o: src/Monde.cpp src/Carte.h
g++ $(CFLAGS) $(INCLUDES) -c obj/Monde.o

Deplacement.o: src/Deplacement.cpp src/Monde.h
g++ $(CFLAGS) $(INCLUDES) -c obj/Deplacement.o

Personnage.o: src/Personnage.cpp
g++ $(CFLAGS) $(INCLUDES) -c obj/Personnage.o


clean:
rm $(OBJ_FILES)
