TARGET = out

SRC = bin/raylib-lua-sol.cpp
 
INCLUDE = -I ./include -I ./build/_deps/sol-src/include -I ./lib/lua/include -I ./build/_deps/raylib-build/src
LIBS = -L ./lib -L ./lib/lua -l:lua53.lib
LIBS += -lraylib -lopengl32 -lgdi32 -lwinmm -lpthread  #<-this is windows-specific

CXX = gcc
# FLAGS = -Wall

OBJ = $(patsubst %.c, %.o, $(SRC))
DEPS = $(wildcard *.h)

%.o : %.c $(DEPS)
	$(CXX) $(INCLUDE) $(FLAGS) -c $< -o $@ $(LIBS)


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(INCLUDE) $(FLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)

run:
	@./$(TARGET)