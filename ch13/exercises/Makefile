.PHONY: all clean

CXXFLAGS := -std=c++0x

BINARIES := ex3 ex4

all: $(BINARIES)

ex3: ex3.cpp dma.cpp dma.hpp
ex4: ex4.cpp port.cpp port.hpp

clean:
	-rm $(BINARIES) *~ *.o
