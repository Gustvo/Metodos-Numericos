CXX = clang++
CXXFLAGS = -Wall -std=c++20
PROG_NAME = algoritimos

SRC_DIR = src
OBJ_DIR = objs
INCLUDE_DIR = include
INCLUDES = $(addprefix -I,$(INCLUDE_DIR))

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(PROG_NAME): $(OBJS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean:
	rm -r $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -g $(CXXFLAGS) -c -o $@ $< $(INCLUDES)
