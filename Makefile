.PHONY: all clean

CXX = g++

FLIDE_SRC = $(shell find src -name '*.cpp')
FLIDE_OBJ = $(FLIDE_SRC:.cpp=.o)

all: flide

clean:
	rm -f flide $(FLIDE_OBJ)

flide: $(FLIDE_OBJ)
	$(CXX) $(FLIDE_OBJ) -o $@ 
