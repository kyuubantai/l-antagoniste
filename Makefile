EXEC_NAME = nom_de_l_executable
OBJ_FILES = main.o maClasse.o
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include
LIBS = -L./extern/lib -luneLib


all: $(EXEC_NAME)


$(EXEC_NAME): $(OBJ_FILES)
g++ $(OBJ_FILES) -o $(EXEC_NAME) $(LIBS)


main.o: main.cpp maClasse.h
g++ $(CFLAGS) $(INCLUDES) -c main.cpp


maClasse.o: maClasse.cpp maClasse.h
g++ $(CFLAGS) $(INCLUDES) -c maClasse.cpp


clean:
rm $(OBJ_FILES)
