NAME = fractol
SRC = drawing.c julia.c main.c mandelbrot.c msg_helper.c tools.c tools2.c tools3.c
OBJ = $(SRC=.c:.o)
HEADER = fractol.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< Successfully!"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean