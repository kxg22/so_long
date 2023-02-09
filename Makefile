NAME = so_long
SRC = so_long.c get_map.c check_map.c check_items_utils.c create_mlxMap.c
OBJ = $(SRC:.c=.o)
CC	= cc
RM	= rm -rf
FLAGS	= -Wall -Wextra -Werror -g3
MINILIBX = minilibx-linux/libmlx.a
LIBFT_LIB = libft/libft.a
#-fsanitize=address,undefined
all : $(NAME)

$(LIBFT_LIB) : 
		make -C libft so_long

$(MINILIBX) :
		make -C minilibx-linux

$(NAME) : $(OBJ) $(LIBFT_LIB) $(MINILIBX) 
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(MINILIBX) -lXext -lX11 -I/minilibx-linux

clean :
		make -C libft fclean 
		make -C libft fclean 
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)