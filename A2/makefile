IDIR =./include 
CXX=g++ 
CC=gcc
CXXFLAGS= -I$(IDIR) -std=c++14 -w -O3

SRCDIR=./src
ODIR=./obj
TARGET=./main

_DEPS = game.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = auxiliary.o validmoves.o game.o performmoves.o eval.o evaluation.o allvalidmoves.o ai.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	@echo "\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS) 


.PHONY: clean

clean:
	@echo "Cleaning ....";
	rm -f $(ODIR)/*.o main
