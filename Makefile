CPP := g++
EXE := bin/kranzky
SRC := $(wildcard src/*.cpp)
OBJ := $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
LIB := -lbox2d -lzmq -framework Gosu
INC := -I include

$(EXE): $(OBJ)
	@mkdir -p bin
	$(CPP) $^ -o $(EXE) $(LIB)

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CPP) -g -Wall -MMD $(INC) -c -o $@ $<

clean:
	-rm -fR bin obj

.PHONY: clean

-include $(OBJ:.o=.d)
