.PHONY: all clean

CPPFLAGS := -std=c++0x

BINARIES := use-tv nested

all: $(BINARIES)

use-tv: use-tv.cpp tv.cpp
nested: nested.cpp

clean:
	-rm $(BINARIES) *~ *.o
