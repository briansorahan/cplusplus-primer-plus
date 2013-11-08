.PHONY: all clean

CXXFLAGS := -std=c++0x

BINARIES := ex1 ex3 ex4 ex5 ex6 ex7

all: $(BINARIES)

ex1: ex1.cpp vect.cpp vect.hpp
ex3: ex3.cpp vect.cpp vect.hpp
ex4: ex4.cpp mytime3.cpp mytime3.hpp
ex5: ex5.cpp stonewt.cpp stonewt.hpp
ex6: ex6.cpp stonewt1.cpp stonewt1.hpp
ex7: ex7.cpp complex0.cpp complex0.hpp

clean:
	-rm $(BINARIES) *~ *.o