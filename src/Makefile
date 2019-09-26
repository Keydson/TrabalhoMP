IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=../obj
#LDIR =../lib

_DEPS = velha.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_Velha = velha.o main.o 
OBJ1 = $(patsubst %,$(ODIR)/%,$(_Pilha))

_Testa_Velha = pilha.o testa_velha.o 
OBJ2 = $(patsubst %,$(ODIR)/%,$(_Testa_Pilha))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Vleha: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

Testa_Velha: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
