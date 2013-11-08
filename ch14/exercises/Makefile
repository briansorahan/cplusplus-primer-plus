.PHONY: all clean

CPPFLAGS := -std=c++0x
BINARIES := ex1 ex3 ex4 # I am excluding ex5 because MI is evil

all: $(BINARIES)

ex1: ex1.cpp wine.cpp
ex3: ex3.cpp worker.cpp
ex4: ex4.cpp person.hpp queue.hpp
ex5: ex5.cpp emp.hpp

clean:
	-rm *~ $(BINARIES) *.o
