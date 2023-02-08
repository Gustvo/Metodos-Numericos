CXX = clang++
CXXFLAGS = -Wall -std=c++20 -fPIC
PROG_NAME = algoritimos

SRC_DIR = src
OBJ_DIR = objs
INCLUDE_DIR = include
INCLUDES = $(addprefix -I,$(INCLUDE_DIR))

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

lib$(PROG_NAME).so: $(OBJS)
	$(CXX) -g $(CXXFLAGS) -shared -o $@ $^

clean:
	rm -r $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -g $(CXXFLAGS) -c -o $@ $< $(INCLUDES)

prog: lib$(PROG_NAME).so src/main.cxx
	$(CXX) -Wall -std=c++20 -g src/main.cxx -o prog -L. -Iinclude/ -lalgoritimos
