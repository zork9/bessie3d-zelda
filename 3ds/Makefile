ECHO=echo
CXX=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=\
./mesh/mesh3dsobject.cpp \
./mesh/mesh3ds.cpp \
./chunk/chunk.cpp \
./chunk/file.cpp \
./light/light3ds.cpp \
./light/light3dsobject.cpp \
./material/material3ds.cpp \
./material/material3dsobject.cpp \
./scene3ds.cpp \

OBJECTS=$(SOURCES:.cpp=.o)
LIBRARY=lib3ds.so


all: $(SOURCES) $(OBJECTS) $(LIBRARY)
	
clean:
	rm -f *.o *.so *.a

$(LIBRARY): $(OBJECTS) 
	ar rcu lib3ds.a *.o ./chunk/*.o ./light/*.o material/*.o ./mesh/*.o
	ranlib lib3ds.a

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@
