NAME = ft_shmup

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I include -I include/core -I include/entities -I include/world
LDFLAGS = -lncurses

SRC_DIRS = src/core src/entities src/world
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJS = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/core/%.o: src/core/%.cpp
	@mkdir -p $(OBJ_DIR)/core
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/entities/%.o: src/entities/%.cpp
	@mkdir -p $(OBJ_DIR)/entities
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/world/%.o: src/world/%.cpp
	@mkdir -p $(OBJ_DIR)/world
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

run: re
	clear && ./bin/ft_shmup

valgrind: re
	clear && valgrind --leak-check=full --show-leak-kinds=all --log-file=.valgrind --suppressions=ncurses.supp ./bin/ft_shmup

.PHONY: all clean fclean re run valgrind