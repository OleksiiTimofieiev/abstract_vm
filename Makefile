NAME 			= avm

SRCS 			= CPU.cpp Parser.cpp Lexer.cpp Exception.cpp Factory.cpp eOperand.cpp main.cpp

CFLAGS 			= -std=c++11 -Wall -Werror -Wextra

OBJECTS 		= $(SRCS:.cpp=.o)

COMPILER 		= clang++

# COLOR MASCSS
LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m
	
all: $(NAME)

%.o: %.cpp %.hpp
	@$(COMPILER) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@echo "$(LOG_CYAN)Compilation started => [ $(NAME) ]$(LOG_NOCOLOR)$(LOG_GREEN) ✓$(LOG_NOCOLOR)"
	@$(COMPILER) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(LOG_YELLOW)Compilation finished => [ $(NAME) ]$(LOG_NOCOLOR)$(LOG_GREEN) ✓$(LOG_NOCOLOR)"

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "$(LOG_RED)Deleted => [ $(NAME) ]$(LOG_NOCOLOR)$(LOG_GREEN) ✓$(LOG_NOCOLOR)"

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)
	@echo "$(LOG_RED)Fully deleted => [ $(NAME) ]$(LOG_NOCOLOR)$(LOG_GREEN) ✓$(LOG_NOCOLOR)"

re: fclean all
	@echo "$(LOG_VIOLET)Redone => [ $(NAME) ]$(LOG_NOCOLOR)$(LOG_GREEN) ✓$(LOG_NOCOLOR)"

.PHONY: all clean fclean re
