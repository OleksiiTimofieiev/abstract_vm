NAME		=	avm
FLAGS		= 	-Wall -Werror -Wextra
COMPILER	=	clang++ -std=c++11

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/

#-------------------------- Header  ------------------------------------------

HPP	=			CPU.hpp\
				eOperand.hpp\
				Exception.hpp\
				Factory.hpp\
				includes.hpp\
				IOperand.hpp\
				Lexer.hpp\
				Parser.hpp

#-------------------------- Source  -------------------------------------------

SRC		=		CPU.cpp\
				eOperand.cpp\
				Exception.cpp\
				Factory.cpp\
				Lexer.cpp\
				Parser.cpp\
				main.cpp

INC_PATH 	= 	$(addprefix $(DIR_INC), $(HPP))
OBJ 		= 	$(addprefix $(DIR_OBJ), $(SRC:.cpp=.o))
INC 		= 	$(addprefix -I, $(DIR_INC))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

#-------------------------- Compilation  ---------------------------------------

$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(OBJ)

#-------------------------- Linking  -------------------------------------------

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(INC_PATH)
	@echo "\033[0;33mCompiling: \033[0;32m[OK] \033[0m       \033[0m" $<
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<

clean:
	@rm -rf $(DIR_OBJ)
	@echo "\033[0;31mDeleted => [ $(NAME) ]\033[0m"

fclean:
	@rm -rf $(DIR_OBJ)
	@rm -f $(NAME)
	@echo "\033[0;31mFully Deleted => [ $(NAME) ]\033[0m"

re: fclean all
	@echo "\033[94mRedone => [ $(NAME) ]\033[0m"
