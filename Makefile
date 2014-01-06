.PHONY: all clean

CXX = g++

FLIDE_SRC = $(shell find src -name '*.cpp')
FLIDE_OBJ = $(FLIDE_SRC:.cpp=.o)

LIBS = sdl2
CFLAGS = $(shell pkg-config --cflags $(LIBS))
LDFLAGS = $(shell pkg-config --libs $(LIBS))

all: flide

clean:
	rm -f flide $(FLIDE_OBJ)

flide: $(FLIDE_OBJ)
	$(CXX) $(LDFLAGS) $(FLIDE_OBJ) -o $@ 

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@
