NAME		:= fractol
CFLAGS		:=  -Wall -Wextra -Werror

LIBFT		:= ./lib/libft/libft.a
LIBFT_PATH	:= ./lib/libft/

LIBMLX		:= ./lib/MLX42
LIBMLX_F	:= $(LIBMLX)/build/libmlx42.a

HEADERS		:= -I ./includes -I $(LIBMLX)/include -I $(LIBFT_PATH)/includes
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS		:= $(shell find ./src -iname "*.c")

SRCS_PATH	:= src/
SRCS_FILES	:= 	actions.c colors.c fractals.c \
				hooks.c inits.c main.c \
				parser.c utils.c 
SRCS		:= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS		:= ${SRCS:.c=.o}

all: $(LIBMLX_F) $(LIBFT) ./includes/fractol.h $(NAME)

$(LIBMLX_F):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@make -sC $(LIBFT_PATH)

%.o: %.c ./includes/fractol.h
	@$(CC) $(CFLAGS) -I ./includes -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS) ./includes/fractol.h
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -sC $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME)
	@rm -f $(LIBFT)

re: clean all

.PHONY: all, clean, fclean, re, libmlx