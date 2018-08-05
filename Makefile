NAME		=	avm
FLAGS		= 	-Wall -Werror -Wextra
COMPILER	=	clang++ -std=c++11

DIR_INC		=	./includes/
DIR_SRC		=	./source/
DIR_OBJ		= 	./obj/

#-------------------------- Header files ---------------------------------------
HEAD_AVM	=	CPU.hpp\
				eOperand.hpp\
				Exception.hpp\
				Factory.hpp\
				includes.hpp\
				IOperand.hpp\
				Lexer.hpp\
				Parser.hpp

#-------------------------- Source files ---------------------------------------
SRC_AVM		=	CPU.cpp\
				eOperand.cpp\
				Exception.cpp\
				Factory.cpp\
				Lexer.cpp\
				Parser.cpp\
				main.cpp

INC_PATH 	= 	$(addprefix $(DIR_INC), $(HEAD_AVM))

OBJ 		= 	$(addprefix $(DIR_OBJ), $(SRC_AVM:.cpp=.o))
INC 		= 	$(addprefix -I, $(DIR_INC))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

#-------------------------- Compil Block ---------------------------------------
$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(OBJ)
	@echo "Compiling" [ $(NAME) ]

#-------------------------- Link Block -----------------------------------------
#source
$(DIR_OBJ)%.o: $(DIR_SRC)%.cpp $(INC_PATH)
	@$(COMPILER) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files avm ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files avm ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all
