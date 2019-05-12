TARGET=test
CC = g++
IDIR = ../h
ODIR = obj
CFLAGS = -I$(IDIR)
LDIR = ../lib
_DEPS = sorts.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ = sorts.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET):$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(TARGET) *.o