.PHONY: all clean

BINARIES := stacker usestock usestock01 usestock02

all: $(BINARIES)

stacker: stacker.cpp stack.cpp stack.hpp
usestock01: usestock01.cpp stock01.cpp stock01.hpp
usestock02: usestock02.cpp stock02.cpp stock02.hpp
usestock: usestock.cpp stock00.cpp stock00.hpp

clean:
	-rm $(BINARIES) *~ *.o