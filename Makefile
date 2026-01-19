NAME		:= Game
CFLAGS		:=  -Wall -Werror -Wextra

LIBMLX		:= ./lib/MLX42

LIBFT_PATH	:= ./lib/libft/
LIBFT		:= ./lib/libft/libft.a

HEADERS		:= -I ./includes -I $(LIBMLX)/include -I ./lib/libft/includes
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS		:= $(shell find ./src -iname "*.c")
SRC_PATH	:= src/
SRC_FILES		:= colors.c fractals.c hooks.c \
			   image.c init.c main.c parse_args.c utils.c 
SRCS		:= $(addprefix  $(SRC_PATH), $(SRC_FILES))
OBJS		:= ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME) 

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@make -sC $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
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