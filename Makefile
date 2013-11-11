
CC := clang
CCFLAGS := -Wall
SOURCES = main.c nstringarray.c nstring.c
OBJECTS = $(subst c,o,$(SOURCES))
DEPEND = .depend
EXE = main

%.o: %.c
	$(CC) -c $(CCFLAGS) $<

$(EXE): $(OBJECTS)

clean:
	rm $(OBJECTS) $(DEPEND) $(EXE)

$(DEPEND): $(SOURCES)
	$(CC) -M $(CCFLAGS) $^ > $@

include $(DEPEND)

