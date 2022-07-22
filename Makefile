CFLAGS= -Wall -Werror -Wextra

CC= cc

SRCS= so_long.c parsing.c Mapping/mapping.c Mapping/map_errors.c \
		Mapping/mapping_utils.c Display/display.c Display/display_tiles.c \
		Init/ft_init_tiles.c ft_close.c Moves/moves.c Moves/move_events.c handlers.c \
		Display/display_player.c Mapping/ft_write_errors.c Init/ft_init_tiles_continue.c \
		Init/ft_init_player_tiles.c

OBJS= $(SRCS:.c=.o)

SRCS_bonus= so_long.c parsing.c Mapping/mapping.c Mapping/map_errors.c \
		Mapping/mapping_utils.c Display/display_bonus.c Display/display_tiles.c \
		Init/ft_init_tiles.c ft_close.c Moves/moves_enemy_bonus.c Moves/move_events.c handlers.c \
		Display/display_player.c Mapping/ft_write_errors.c Moves/moves_bonus.c \
		Display/display_enemies_bonus.c Init/ft_init_tiles_continue.c Init/ft_init_player_tiles.c

OBJS_bonus= $(SRCS_bonus:.c=.o)

NAME= so_long

%.o : %.c
	$(CC) -g3 $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) so_long.h
	make -s -C libs/minilibx
	make -s -C libs/libftprintf
	$(CC) -g3 -o $(NAME) $(OBJS) -L libs/minilibx -lmlx -lX11 -lXext -L libs/libftprintf -lftprintf

bonus : so_long_bonus

so_long_bonus : $(OBJS_bonus) so_long.h
	make -s -C libs/minilibx
	make -s -C libs/libftprintf
	$(CC) -g3 -o so_long_bonus $(OBJS_bonus) -L libs/minilibx -lmlx -lX11 -lXext -L libs/libftprintf -lftprintf

re : fclean all

clean :
	rm -f $(OBJS) $(OBJS_bonus)
	make clean -C libs/libftprintf
	make clean -C libs/minilibx

fclean : clean
	rm -f $(NAME) so_long_bonus
	make fclean -C libs/libftprintf

.PHONY : all clean fclean re
