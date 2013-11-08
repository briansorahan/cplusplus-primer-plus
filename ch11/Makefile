.PHONY: all clean

BINARIES := randwalk stone1 stone usetime0 usetime1 usetime2

all: $(BINARIES)

randwalk: randwalk.cpp vect.cpp vect.hpp
stone1: stone1.cpp stonewt1.cpp stonewt1.hpp
stone: stone.cpp stonewt.cpp stonewt.hpp
usetime0: usetime0.cpp mytime0.cpp mytime0.hpp
usetime1: usetime1.cpp mytime1.cpp mytime1.hpp
usetime2: usetime2.cpp mytime2.cpp mytime2.hpp

clean:
	-rm $(BINARIES) *~ *.o