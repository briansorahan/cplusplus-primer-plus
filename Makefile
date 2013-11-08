.PHONY: all clean

BINARIES := carrots convert getinfo myfirst ourfunc sqrt

all: $(BINARIES)

clean:
	-rm $(BINARIES) *~ *.o