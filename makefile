TARGET= add-nbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGET): main.o
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

claen:
	rm -f $(TARGET)
	rm -f *.o
