CPP := g++
EXE := bin/kranzky
SRC := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
LIB := -lbox2d -lczmq -framework gosu
INC := -I include

all: run

$(EXE): $(OBJ)
	@mkdir -p bin
	$(CPP) $^ -o $(EXE) $(LIB)

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CPP) -g -Wall -MMD $(INC) -c -o $@ $<

run: $(EXE)
	$(EXE)

clean:
	-rm -fR bin obj

.PHONY: clean

-include $(OBJ:.o=.d)
