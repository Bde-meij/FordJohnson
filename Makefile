NAME = fordjohnson
CC	= c++
SRC = main.cpp FordJohnson.cpp vectCode.cpp listCode.cpp
HDRS = FordJohnson.hpp

OBJFILES = $(SRC:%.cpp=%.o)
CFLAGS = -Wall -Wextra -Werror

all	: $(NAME)

$(NAME) : $(OBJFILES)
	@$(CC) $(CFLAGS) $(OBJFILES) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all