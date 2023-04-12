# el compilador a utilizar
COMPILADOR = g++
#/opt/homebrew/Cellar/sdl2/2.26.1 
LIBRERIAS_PATH = /opt/homebrew

#folder de los archivos fuente
SRC = src


# banderas del procesador y los includes de las librerias
CFLAGS = -std=c++17 -O3 -I$(LIBRERIAS_PATH)/include/SDL2 
CFLAGSDEBUG = -std=c++17 -g -I$(LIBRERIAS_PATH)/include/SDL2 
# banderas del linker y la librerias
LDFLAGS = -L$(LIBRERIAS_PATH)/lib `pkg-config --static --libs --cflags sdl2 SDL2_ttf`

MACROS =# -D RECTANGULOS

# nombre del programa
TARGET = main

# reglas, obtener todos los archivos .cpp y .hpp
CPP_SOURCE = $(wildcard *.cpp) $(wildcard $(SRC)/*.cpp) $(wildcard $(SRC)/*/*.cpp) $(wildcard $(SRC)/*/*/*.cpp)
CPP_HEADERS = $(wildcard *.hpp) $(wildcard $(SRC)/*.hpp) $(wildcard $(SRC)*/*.hpp) $(wildcard $(SRC)/*/*/*.hpp)

# compilar
$(TARGET): $(CPP_SOURCE) $(CPP_HEADERS)
	$(COMPILADOR) $(CFLAGS) $(MACROS) -o $(TARGET) $(CPP_SOURCE) $(LDFLAGS)

debug: $(CPP_SOURCE) $(CPP_HEADERS)
	$(COMPILADOR) $(CFLAGSDEBUG) -o $(TARGET) $(CPP_SOURCE) $(LDFLAGS)

# borrar el programa del folder
clean:
	rm -f $(TARGET)