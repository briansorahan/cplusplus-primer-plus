.PHONY: all clean

CPPFLAGS := -std=c++0x

BINARIES := use-tv nested error1 error2 error3 error4 error5 newexcp use_sales

all: $(BINARIES)

use-tv: use-tv.cpp tv.cpp
use_sales: use_sales.cpp sales.cpp

clean:
	-rm $(BINARIES) *~ *.o
