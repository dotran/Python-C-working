CC = g++
LINKER = g++

CFLAGS = -Wall -O3
ifeq ($(CC), gcc)
	CFLAGS += -std=c99
endif
INCLUDE_FLAGS = # -I$JAVA_HOME/include

SOURCES  = C-src/myhello.cpp \
           C-src/mycalc.cpp \
           C-src/mygreeting.cpp \
           C-src/CwrapCpp.cpp \

OBJECTS  = $(SOURCES:.cpp=.o)
DYNALIBS = libmyCfuncs.so

all: $(SOURCES) $(DYNALIBS)

$(DYNALIBS): $(OBJECTS)
	$(LINKER) -shared -Wl,-soname,$(DYNALIBS) -o $@  $(OBJECTS)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -fPIC $(INCLUDE_FLAGS) -o $@

clean:
	-rm -f $(OBJECTS) $(DYNALIBS)

