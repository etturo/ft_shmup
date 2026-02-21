NAME = ft_shmup

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -I include
LDFLAGS = -lncurses

SRC_DIR = src
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

run: re
	clear && ./bin/ft_shmup

.PHONY: all clean fclean re run