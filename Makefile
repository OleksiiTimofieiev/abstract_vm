NAME		=	avm
FLAGS		= 	-Wall -Werror -Wextra
COMPILER	=	clang++ -std=c++11

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/

#-------------------------- Header files ------------------------------------------

HPP	=			CPU.hpp\
				eOperand.hpp\
				Exception.hpp\
				Factory.hpp\
				includes.hpp\
				IOperand.hpp\
				Lexer.hpp\
				Parser.hpp

#-------------------------- Source files -------------------------------------------

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

#-------------------------- Compilation Block ---------------------------------------

$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Linking Block -------------------------------------------

$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(INC_PATH)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<

clean:
	@rm -rf $(DIR_OBJ)

fclean:
	@rm -rf $(DIR_OBJ)
	@rm -f $(NAME)

re: fclean all
