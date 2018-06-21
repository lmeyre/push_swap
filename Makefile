NAME_PUSH = push_swap

NAME_CHECK = checker

FLAGS = -Wall -Werror -Wextra

VPATH = $(PUSH_SRCS_DIR)/base\
		$(PUSH_SRCS_DIR)/main_algo\
		$(PUSH_SRCS_DIR)/fusion\
		$(CHECK_DIR)/srcs\

SRC_PUSH =	 lst_three_util.c sort_list_one_b.c moove_reverse_rotate.c	sort_list_three.c util_main.c\
			moove_rotate.c sort_list_three_special.c initialize.c moove_swap_push.c algo.c\
			sort_lst_four.c little_lst.c sort_lst_two.c lst_one_util.c sort_list.c start_push.c\
			lst_three_special_util.c sort_list_one_a.c util.c nelsonac.c nelson_loop.c init.c\
			print_list.c sort_lst_numbers.c sort_lst_util.c sort_list_one_a_util.c sort_list_one_b_util.c\

SRC_CHECK =	start_check.c initialize_check.c init_check.c moove_rotate_check.c moove_reverse_rotate_check.c moove_swap_push_check.c\

BIN_PUSH = $(SRC_PUSH:.c=.o)

BIN_CHECK = $(SRC_CHECK:.c=.o)

LIB = libft/libft.a

HEADER_PUSH = push_swap_dir/includes/push_swap.h

HEADER_CHECK =  checker_dir/includes/checker.h

LIBDIR = libft/

PUSH_SRCS_DIR = push_swap_dir/srcs/

PUSH_DIR = push_swap_dir/

CHECK_DIR = checker_dir/

MAKE = Makefile

.PHONY: all clean fclean re

all: $(NAME_PUSH)

$(NAME_PUSH): $(BIN_PUSH) $(BIN_CHECK) $(LIB)  $(HEADER_PUSH) $(HEADER_CHECK) $(MAKE)
	@ gcc $(FLAGS) -o $(NAME_PUSH) $(BIN_PUSH) -I $(LIBDIR) -I $(PUSH_DIR) $(LIB)
	@ gcc $(FLAGS) -o $(NAME_CHECK) $(BIN_CHECK) -I $(LIBDIR) -I $(CHECK_DIR) $(LIB)

%.o: %.c
	@ gcc $(FLAGS) -o $@ -c $< -I $(PUSH_DIR)/includes
	

$(LIB):
	@ make -C $(LIBDIR)

clean:
	@ rm -f $(BIN_PUSH) $(BIN_CHECK)
	@ make clean -C $(LIBDIR)

fclean: clean
	@ rm -f $(NAME_PUSH) $(NAME_CHECK)
	@ make fclean -C $(LIBDIR)

re: fclean all
