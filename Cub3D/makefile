NAME = cub3d

SRCS = cub3d.c parsing1.c parsing2.c parsing3.c parsing4.c utils.c graphic.c init_all.c raycasting.c raycasting1.c utils_color.c render3d.c moves.c moves_sec.c textures.c

OBJS = $(SRCS:.c=.o)

CC = cc


# CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

%.o : %.c  cub3d.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) cub3d.h
	cd libft && make
	cd ..
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	cd libft && make fclean
	$(RM) $(NAME)

re: fclean all

