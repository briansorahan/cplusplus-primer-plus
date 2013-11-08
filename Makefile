CHAPTERS := $(wildcard ch*)

.PHONY: all clean

all:
	for d in $(CHAPTERS); do \
		$(MAKE) -C $$d; \
	done

clean:
	for d in $(CHAPTERS); do \
		$(MAKE) -C $$d clean; \
	done
