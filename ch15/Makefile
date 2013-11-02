.PHONY: all clean

CPPFLAGS := -std=c++0x

BINARIES := use-tv nested error1

all: $(BINARIES)

use-tv: use-tv.cpp tv.cpp
nested: nested.cpp
error1: error1.cpp

clean:
	-rm $(BINARIES) *~ *.o
