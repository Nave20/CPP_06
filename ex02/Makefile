NAME = identify
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -g3
OBJ_DIR = objs/
SRC_DIR = .
INC_DIR = include

SRC_FILES = src/main.cpp src/A.cpp src/B.cpp src/C.cpp src/Base.cpp
INC_FILES = inc/A.hpp inc/B.hpp inc/C.hpp inc/Base.hpp

OBJS = $(addprefix $(OBJ_DIR),$(SRC_FILES:.cpp=.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INC_DIR) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)