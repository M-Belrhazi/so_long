CFLAGS= -Wall -Werror -Wextra

CC= cc

SRCS= so_long.c parsing.c Mapping/mapping.c Mapping/map_errors.c \
		Mapping/mapping_utils.c Display/display.c Display/display_tiles.c \
		ft_init_tiles.c ft_close.c Moves/moves.c Moves/move_events.c handlers.c \
		Display/display_player.c Mapping/ft_write_errors.c

OBJS= $(SRCS:.c=.o)

NAME= so_long

%.o : %.c
	$(CC) -g3 $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	make -s -C libs/minilibx
	make -s -C libs/libftprintf
	$(CC) -g3 -o $(NAME) $(OBJS) -L libs/minilibx -lmlx -lX11 -lXext -L libs/libftprintf -lftprintf

re : fclean all

clean :
	rm -f $(OBJS)
	make clean -C libs/libftprintf
	make clean -C libs/minilibx

fclean : clean
	rm -f $(NAME)
	make fclean -C libs/libftprintf

.PHONY : all clean fclean re
