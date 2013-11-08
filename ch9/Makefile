.PHONY: all clean

CXXFLAGS := -std=c++0x

BINARIES := external file1 newplace static support twofile1 usenmsp

all: $(BINARIES)

external: external.cpp support.cpp
file1: file1.cpp coordin.cpp coordin.hpp
support: support.cpp external.cpp
twofile1: twofile1.cpp twofile2.cpp
usenmsp: usenmsp.cpp namesp.cpp namesp.hpp

clean:
	-rm $(BINARIES) *~ *.o