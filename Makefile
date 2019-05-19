PUSH_SWAP = push_swap

CHECKER = checker

LIBF = libft.a

CODE_SOURCES  =	ft_push_swap.c\
				ft_tool_swap.c\
				main.c\
				ft_tool_swap_1.c\
				ft_operateur.c\
				ft_operateur_1.c\
				ft_find_error.c\
				ft_sort.c\
				ft_opti.c\
				ft_algo_sort.c\
				ft_tool_ope.c\
				ft_mediane.c\
				ft_algo_sort_a.c\
				ft_help_qsort.c\
				ft_instruct.c\
				ft_redirection.c\
				ft_check_error.c\
				ft_qsort.c\
				ft_sort_list.c

CODE_CHECKER = 	ft_checker.c\
				operateur_checker_1.c\
				operateur_checker.c\
				ft_operateur.c\
				main_checker.c\
				ft_find_error.c\
				ft_tool_swap.c\
				ft_tool_ope.c\
				ft_check_error.c\
				ft_instruct.c\
				ft_operateur_1.c

OB_PATH = objet

SRC_PATH = code_source

O_NAME = $(CODE_SOURCES:.c=.o)

O_NAME_CHECKER = $(CODE_CHECKER:.c=.o)

OBJ = $(addprefix $(OB_PATH)/,$(O_NAME))

OBJ_CHECKER = $(addprefix $(OB_PATH)/,$(O_NAME_CHECKER))

OBJ_LIB = $(LIBFT:.c=.o)

CC = gcc

PATH_LIBFT = -Llibft

LIBFT = -lft

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iinclude

CFLAG = -Wall -Werror -Wextra

all :			$(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) :	$(OBJ)
				@make -C libft/
				$(CC) $(LIBFT) $(PATH_LIBFT) $(OBJ) -o $(PUSH_SWAP)

$(CHECKER) :	$(OBJ_CHECKER)
				@make -C libft/
				$(CC) $(LIBFT) $(PATH_LIBFT) $(OBJ_CHECKER) -o $(CHECKER)

$(OB_PATH)/%.o:	$(SRC_PATH)/%.c
				@mkdir $(OB_PATH) 2> /dev/null || true
				$(CC) $(CFLAG) $(INCLUDE) -o $@ -c $<

clean :
				$(RM) $(OBJ) $(OBJ_CHECKER)
				make -C libft/ clean -f Makefile
				rm -rf $(OB_PATH) || true

fclean : 		clean
				$(RM) $(PUSH_SWAP) $(CHECKER)
				$(RM) libft/libft.a

re :			fclean all
