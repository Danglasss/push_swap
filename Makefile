PUSH_SWAP = push_swap

CHECKER = checker

LIBF = libft.a

CODE_SOURCES  =	code_source/ft_push_swap.c\
				code_source/ft_tool_swap.c\
				code_source/main.c\
				code_source/ft_tool_swap_1.c\
				code_source/ft_operateur.c\
				code_source/ft_operateur_1.c\
				code_source/ft_dechet_test.c\
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
				code_source/ft_dechet_test.c\
				code_source/ft_tool_swap.c\
				code_source/ft_tool_ope.c\
				code_source/ft_check_error.c\
				code_source/ft_instruct.c\
				code_source/ft_operateur_1.c

LIBFT = libft/ft_strlen.c\
		libft/ft_strjoin.c\
		libft/ft_strjoin_free_s1.c\
		libft/get_next_line.c\
		libft/ft_bzero.c\
		libft/ft_create_list.c\
		libft/ft_lstadd.c\
		libft/ft_strdel.c\
		libft/ft_memdel.c\
		libft/ft_strdup_free.c\
		libft/ft_strncat_free_s2.c\
		libft/ft_strsub_free.c\
		libft/ft_puttab.c\
		libft/ft_strnew.c\
		libft/ft_putstr.c\
		libft/ft_putchar.c\
		libft/ft_putendl.c\
		libft/ft_strncmp.c\
		libft/ft_strsplit.c\
		libft/ft_strtab.c\
		libft/ft_strsub.c\
		libft/ft_itoa.c\
		libft/ft_putnbr.c\
		libft/ft_strcpy.c\
		libft/ft_strdup.c\
		libft/ft_chrlen.c\
		libft/ft_strchar.c\
		libft/ft_strcmp.c\
		libft/ft_atoi.c

OBJ = $(CODE_SOURCES:.c=.o)

OBJ_CHECKER = $(CODE_CHECKER:.c=.o)

OBJ_LIB = $(LIBFT:.c=.o)

CC = gcc -g

INCLUDE =	libft/libft.a

HEADER 	=	include/assembly.h

CFLAG = -Wall -Werror -Wextra

RM = rm -rf

all :			$(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) :	$(LIBF) $(OBJ) $(OBJ_LIB) $(CODE_SOURCES)
				$(CC) $(OBJ) -o $(PUSH_SWAP) $(INCLUDE)

$(CHECKER) :	$(LIBF) $(OBJ_CHECKER) $(OBJ_LIB) $(CODE_CHECKER)
				$(CC) $(OBJ_CHECKER) -o $(CHECKER) $(INCLUDE)

$(LIBF) :
				@ cd libft ; $(MAKE) -f Makefile

%.o: %.c		$(CC) -c $^ $(CFLAG) -I $(INCLUDE)

clean :
				$(RM) $(OBJ) $(OBJ_CHECKER)
				@ cd libft ; $(MAKE) clean -f Makefile

fclean : 		clean
				$(RM) $(PUSH_SWAP) $(CHECKER) $(INCLUDE)

re :			fclean all
