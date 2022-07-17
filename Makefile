CFLAGS= -Wall -Werror -Wextra

CC= cc

SRCS= so_long.c parsing.c Mapping/mapping.c Mapping/map_errors.c \
		Mapping/mapping_utils.c Display/display.c Display/display_tiles.c \
		ft_init.c ft_close.c moves.c handlers.c Display/display_player.c

OBJS= $(SRCS:.c=.o)

NAME= so_long

%.o : %.c
	$(CC) -g3 $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	make -s -C ./minilibx
	make -s -C ./libftprintf
	$(CC) -g3 -o $(NAME) $(OBJS) -Lminilibx -lmlx -lX11 -lXext -Llibftprintf -lftprintf

re : fclean all

clean :
	rm -f $(OBJS)
	make clean -C libftprintf
	make clean -C minilibx

fclean : clean
	rm -f $(NAME)
	make fclean -C libftprintf

.PHONY : all clean fclean re
