NAME        	=   cub3D
NAME_BONUS		=	cub3D_bonus

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
SRC_BONUS_DIR	=	$(shell find srcs_bonus -type d)
LIBFT		=	./libft 
MLX		=	./mlx
OBJ_DIR			=	.obj
OBJ_DIR_BONUS	=	.obj_bonus

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
vpath %.c $(foreach dir, $(SRC_BONUS_DIR), $(dir):)

# library -----------------------------------------------------------

SRC			= 	main.c game_utils.c loop_mlx.c player_move.c	\
				raycasting_utils.c raycasting.c					\
				textures_utils.c textures.c init_data.c			\
				init_map.c init_mlx.c check_rgb.c				\
				element_parsing.c element_parsing_utils.c		\
				check_map.c check_around_space.c				\
				get_player_pos.c map_parsing.c open_file.c		\
				read_file.c clean_exit.c free_utils.c			\
				check_map_utils.c								\
				
SRC_BONUS	=	main_bonus.c game_utils_bonus.c loop_mlx_bonus.c				\
				textures_utils_bonus.c textures_bonus.c init_data_bonus.c		\
				init_map_bonus.c init_mlx_bonus.c check_rgb_bonus.c				\
				element_parsing_bonus.c element_parsing_utils_bonus.c			\
				check_map_bonus.c check_around_space_bonus.c					\
				get_player_pos_bonus.c map_parsing_bonus.c open_file_bonus.c	\
				read_file_bonus.c clean_exit_bonus.c free_utils_bonus.c			\
				player_move_bonus.c	raycasting_utils_bonus.c raycasting_bonus.c	\
				check_map_utils_bonus.c \
			
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror

IFLAGS		=	-I ./include -I ./libft/includes -I ./mlx -I /usr/include

IFLAGS_B	=	-I ./include_bonus -I ./libft/includes -I ./mlx -I /usr/include

LFLAGS		=	-lmlx -lm -lX11 -lXext

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

$(OBJ_DIR)/%.o : %.c include/cub3d.h 
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(_GREEN)DONE$(_WHITE)"

$(OBJ_DIR_BONUS)/%.o : %.c include_bonus/cub3d_bonus.h
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(IFLAGS_B) -c $< -o $@ 
	@echo "$(_GREEN)DONE$(_WHITE)"dP

all: libft/libft.a mlx/libmlx.a $(NAME)

libft/libft.a:
	@make -C $(LIBFT)

mlx/libmlx.a:
	@make -C $(MLX)

bonus: libft/libft.a mlx/libmlx.a $(NAME_BONUS)

$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	$(CC) $(CFLAGS) $(OBJ) $(IFLAGS) libft/libft.a -L./mlx $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"
	@echo "      ,gggg,                           ad888888b,  ,gggggggggggg,   "
	@echo "    ,88\"\"\"Y8b,             ,dPYb,     d8\"     \"88 dP\"\"\"88\"\"\"\"\"\"Y8b, "
	@echo "   d8\"     \`Y8             IP'\`Yb             a88 Yb,  88       \`8b,"
	@echo "  d8'   8b  d8             I8  8I            ,88P  \`\"  88        \`8b"
	@echo " ,8I    \"Y88P'             I8  8'          aad8\"       88         Y8"
	@echo " I8'           gg      gg  I8 dP           \"\"Y8,       88         d8"
	@echo " d8            I8      8I  I8dP   88gg       \`88b      88        ,8P"
	@echo " Y8,           I8,    ,8I  I8P    8I          \"88      88       ,8P'"
	@echo " \`Yba,,_____, ,d8b,  ,d8b,,d8b,  ,8I  Y8,     a88      88______,dP' "
	@echo "   \`\"Y8888888 8P'\"Y88P\"\`Y88P'\"Y88P\"'   \"Y888888P'     888888888P\"   "

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	$(CC) $(CFLAGS) $(IFLAGS_B) $(OBJ_BONUS) libft/libft.a -L./mlx $(LFLAGS) -o $(NAME_BONUS)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@make clean -C $(MLX)
	@make clean -C $(LIBFT)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re:	fclean all

.PHONY: all bonus re clean flcean
