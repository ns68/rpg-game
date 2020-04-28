CXX=g++
CFLAGS=-W -Wall -pedantic -std=c++17 -O2 
LDFLAGS=
EXEC=rpg.app
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@ echo [CXX] $^ $(CFLAGS)
	@ $(CXX) -o $@ $^ $(LDFLAGS)

#main.o: hello.h

%.o: %.cpp
	@ echo [link] $< $(CFLAGS)
	@ $(CXX) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o $(EXEC)

mrproper: clean
	rm -rf $(EXEC)