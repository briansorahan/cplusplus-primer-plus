.PHONY: all clean

CXXFLAGS := -std=c++0x

BINARIES := bank placenew1 placenew2 sayings1 sayings2

all: $(BINARIES)

bank: bank.cpp queue.cpp queue.hpp
sayings1: sayings1.cpp string1.cpp string1.hpp
sayings2: sayings2.cpp string1.cpp string1.hpp

clean:
	-rm $(BINARIES) *~ *.o