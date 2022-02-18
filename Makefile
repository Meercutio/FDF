NAME		= fdf
CFLAGS 		= -Wall -Wextra -Werror -g
INC			= ./includes/fdf.h
CC			= gcc

SRC_NAME 	= main.c read_file.c draw.c \
			button_hand.c graf_proc.c instr.c

OBJ_NAME 	= $(SRC_NAME:.c=.o)
OBJ 		= $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIB_DIR 	= libft/
MLX_DIR		= -Lmlx -lmlx -framework OpenGL -framework AppKit
SRC_DIR 	= src/
OBJ_DIR 	= obj/

all:		$(NAME)

$(NAME):	$(OBJ) libft/libft.a
	@$(CC) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft $(MLX_DIR)
	@echo "##### fdf compiling finished! #####"

libft/libft.a:
	@make -C $(LIB_DIR) --silent

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ)
	@echo "##### Removed object files #####"

fclean:		clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re:			fclean all

.PHONY:		all clean fclean re