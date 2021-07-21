NAME = my_mastermind
FLAGS = -Wall -Wextra -Werror
SRC = src/*.c
INC = inc/mastermind.h

all: $(NAME)

$(NAME): $(SRC)
	gcc -g $(FLAGS) $(INC) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(NAME)

re: clean all