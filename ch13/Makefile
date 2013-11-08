.PHONY: all clean

BINARIES := usett1 usett0 usebrass1 usebrass2 usebrass3 usedma

CXXFLAGS := -std=c++0x

all: $(BINARIES)

usett1: usett1.cpp tabletennis1.cpp
usett0: usett0.cpp tabletennis0.cpp
usebrass1: usebrass1.cpp brass.cpp brass.hpp
usebrass2: usebrass2.cpp brass.cpp brass.hpp
usebrass3: usebrass3.cpp acctabc.cpp acctabc.hpp
usedma: usedma.cpp dma.cpp dma.hpp

clean:
	-rm $(BINARIES) *.o *~