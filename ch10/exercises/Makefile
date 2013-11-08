.PHONY: all clean

CXXFLAGS := -std=c++0x

BINARIES := ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8

all: $(BINARIES)

ex1: ex1.cpp bank.cpp bank.hpp
ex2: ex2.cpp person.cpp person.hpp
ex3: ex3.cpp golf.cpp golf.hpp
ex4: ex4.cpp sales.cpp sales.hpp
ex5: ex5.cpp stack.cpp stack.hpp
ex6: ex6.cpp move.cpp move.hpp
ex7: ex7.cpp plorg.cpp plorg.hpp
ex8: ex8.cpp list.cpp list.hpp

clean:
	-rm $(BINARIES) *~ *.o