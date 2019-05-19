PUSH_SWAP = push_swap

CHECKER = checker

LIBF = libft.a

CODE_SOURCES  =	code_source/ft_push_swap.c\
				code_source/ft_tool_swap.c\
				code_source/main.c\
				code_source/ft_tool_swap_1.c\
				code_source/ft_operateur.c\
				code_source/ft_operateur_1.c\
				code_source/ft_find_error.c\
				code_source/ft_sort.c\
				code_source/ft_opti.c\
				code_source/ft_algo_sort.c\
				code_source/ft_tool_ope.c\
				code_source/ft_mediane.c\
				code_source/ft_algo_sort_a.c\
				code_source/ft_help_qsort.c\
				code_source/ft_instruct.c\
				code_source/ft_redirection.c\
				code_source/ft_check_error.c\
				code_source/ft_qsort.c\
				code_source/ft_sort_list.c

CODE_CHECKER = 	code_source/ft_checker.c\
				code_source/operateur_checker_1.c\
				code_source/operateur_checker.c\
				code_source/ft_operateur.c\
				code_source/main_checker.c\
				code_source/ft_find_error.c\
				code_source/ft_tool_swap.c\
				code_source/ft_tool_ope.c\
				code_source/ft_check_error.c\
				code_source/ft_instruct.c\
				code_source/ft_operateur_1.c

#OB_PATH = objet

#OBJ_NAME = $(notdir $(CODE_SOURCES:.c=.o))

#OBJ = $(addprefix $(OB_PATH)/,$(OBJ_NAME))

OBJ = $(CODE_SOURCES:.c=.o)

OBJ_CHECKER = $(CODE_CHECKER:.c=.o)

OBJ_LIB = $(LIBFT:.c=.o)

CC = gcc

PATH_LIBFT = -Llibft

LIBFT = -lft

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iinclude

CFLAG = -Wall -Werror -Wextra

all :			$(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) :	$(LIBF) $(OBJ)
				$(CC) $(LIBFT) $(PATH_LIBFT) $(OBJ) -o $(PUSH_SWAP)

$(CHECKER) :	$(LIBF) $(OBJ_CHECKER)
				$(CC) $(LIBFT) $(PATH_LIBFT) $(OBJ_CHECKER) -o $(CHECKER)

%.o:			$(CODE_SOURCES)/%.c
				#@mkdir $(OB_PATH) 2> /dev/null || true
				$(CC) $(CFLAG) $(INCLUDE) -o $@ -c $<

$(LIBF) :		
				@make -C libft/

clean :
				$(RM) $(OBJ) $(OBJ_CHECKER)
				make -C libft/ clean -f Makefile
				#rm -rf $(OB_PATH)

fclean : 		clean
				$(RM) $(PUSH_SWAP) $(CHECKER)
				$(RM) libft/libft.a

re :			fclean all
