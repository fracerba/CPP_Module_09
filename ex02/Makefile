NAME = PmergeMe

SRCS = main.cpp \
	PmergeMe.cpp \

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

CC = c++

OBJ = $(SRC:.cpp=.o)

.cpp.o: 
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
