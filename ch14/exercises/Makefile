.PHONY: all clean

CPPFLAGS := -std=c++0x
BINARIES := ex1 ex3

all: $(BINARIES)

ex1: ex1.cpp wine.cpp
ex3: ex3.cpp worker.cpp

clean:
	-rm *~ $(BINARIES) *.o
