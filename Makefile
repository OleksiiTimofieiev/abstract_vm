NAME	= 	avm
SRC_DIR	= 	./src/
INC_DIR	= 	./inc/
OBJ_DIR	= 	./obj/

FLAGS	= 	-std=c++11 -Wall -Wextra -Werror
SRC		=	Factory.class.cpp \
			main.cpp \
			AbstractVM.class.cpp
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INC		=	-I $(INC_DIR)

all:		$(NAME)

$(NAME):	$(OBJ)
			@clang++ $(FLAGS) $(OBJ) -o $(NAME) $(INC)
			@echo " \033[1;92mDone!\033[0m"

$(OBJ):		| $(OBJ_DIR)

$(OBJ_DIR):	
			@echo "\033[0;92mCompiling sources\033[0m"
			@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				@clang++ -c $< -o $@ $(FLAGS) $(INC)
				@echo "\033[42m  \033[0m\c"

clean:
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[1;91mFCleaned\033[0m"

re:			fclean all