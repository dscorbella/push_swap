CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
NAME		= push_swap
BONUS_NAME	= checker

SRC_PATH		= src/
OBJ_PATH		= obj/
BONUS_PATH		= bonus/
BONUS_OBJ_PATH	= bonusobj/

SRC		= push_swap.c ft_checker.c ft_stacks.c \
		ft_play.c ft_position.c ft_move.c \
		ft_swap.c ft_push.c ft_rotate.c ft_revrot.c \

BONUS   = ft_bonus.c ft_checker_bonus.c \
		  ft_stacks_bonus.c gnl.c \
		  ft_push_bonus.c ft_rotate_bonus.c \
		  ft_swap_bonus.c ft_revrot_bonus.c \

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
BONUSS		= $(addprefix $(BONUS_PATH), $(BONUS))
OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
BONUS_OBJS	= $(addprefix $(BONUS_OBJ_PATH), $(BONUS_OBJ))
INC			= ./includes/push_swap.h
BONUS_INC	= ./includes/checker.h
INCS		= -I ./includes/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(BONUS_OBJ_PATH)%.o: $(BONUS_PATH)%.c $(BONUS_INC)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(BONUS_OBJ_PATH):
	mkdir $(BONUS_OBJ_PATH)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(BONUS_INC)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

bonus: $(BONUS_OBJ_PATH) $(BONUS_NAME)

clean:
	rm -rf $(OBJ_PATH) $(BONUS_OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
