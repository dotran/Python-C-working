CC = gcc
LINKER = gcc

CFLAGS = -Wall -O3
ifeq ($(CC), gcc)
	CFLAGS += -std=c99
endif
INCLUDE_FLAGS = # -I$JAVA_HOME/include

SOURCES  = C-src/myhello.c \
           C-src/mycalc.c \
#	   C-src/mygreeting.c \

OBJECTS  = $(SOURCES:.c=.o)
DYNALIBS = libmyCfuncs.so

all: $(SOURCES) $(DYNALIBS)

$(DYNALIBS): $(OBJECTS)
	$(LINKER) -shared $(OBJECTS) -o $@ -Wl,-soname

.c.o:
	$(CC) -c $(CFLAGS) $< -fPIC $(INCLUDE_FLAGS) -o $@

clean:
	-rm -f $(OBJECTS) $(DYNALIBS)

