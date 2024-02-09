NAME = btc

SRCS = main.cpp \
	BitcoinExchange.cpp \

HEADER = BitcoinExchange.hpp

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

CC = c++

OBJ = $(SRCS:.cpp=.o)

.cpp.o: 
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
