NAME		= so_long

FILES = so_long map get_next_line ft_split error move \
		put_img check move_utils check_utils

PROJECT_H	= ./Incl/so_long.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = Src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
MLX         =   libmlx.dylib
LIBFT       =   libft/libft.a
FT_PRINTF   =   ft_printf/libftprintf.a

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)src
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -s -C ./libft
	@make -s -C ./mlx
	@make -s -C ./ft_printf
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(MLX) $(LIBFT) $(FT_PRINTF)

all: $(NAME)

clean:
	@make clean -s -C libft
	@make clean -s -C ft_printf
	@rm -rf $(addprefix $(OBJS_DIR), $(SRCS_DIR))

fclean: clean
	@rm -f $(NAME)

fclean.all: fclean
			@make fclean -s -C libft
			@make clean -s -C mlx
			@make fclean -s -C ft_printf

re: fclean all

.PHONY:		all clean fclean re
