NAME = ft_shmup

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I include
LDFLAGS = -lncurses

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

run: re
	clear && ./bin/ft_shmup

valgrind: re
	clear && valgrind --leak-check=full --show-leak-kinds=all --log-file=.valgrind --suppressions=supp_extra.supp ./bin/ft_shmup

.PHONY: all clean fclean re run valgrind