NAME = libft.a

SRCS =	ft_atoi.c\
		ft_strsub_free.c\
		ft_strncat_free_s2.c\
		ft_strjoin_free_s1.c\
		ft_strdup_free.c\
		ft_memalloc.c\
		ft_strsplit.c\
		ft_strchar.c\
		ft_chrlen.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_strcpy.c\
		ft_striter.c\
		ft_strmap.c\
		ft_puttab.c\
		ft_strmapi.c\
		ft_strtab.c\
		ft_chrnlen.c\
		ft_strnew.c\
		ft_strtrim.c\
		get_next_line.c\
		ft_bzero.c\
		ft_create_list.c\
		ft_list_len.c\
		ft_memmove.c\
		ft_strnchar.c\
		ft_strchar.c\
		ft_putendl.c\
		ft_putstr.c\
		ft_strdel.c\
		ft_striteri.c\
		ft_isalpha.c\
		ft_memcmp.c\
		ft_memchr.c\
		ft_memset.c\
		ft_create_elem.c\
		ft_putdtab.c\
		ft_putendl_fd.c\
		ft_putstr_fd.c\
		ft_strdup.c\
		ft_strcmp.c\
		ft_isprint.c\
		ft_strjoin.c\
		ft_strncpy.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_putlist.c\
		ft_memdel.c\
		ft_memcpy.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_strclr.c\
		ft_strequ.c\
		ft_push_back.c\
		ft_strlcat.c\
		ft_strnstr.c\
		ft_strlen.c\
		ft_strnequ.c\
		ft_strncmp.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_toupper.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_tolower.c\
		ft_strncat.c\
		ft_strrchr.c\
		ft_memccpy.c\
		ft_strstr.c\
		ft_lstdelone.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstdel.c\
		ft_lstmap.c\
		ft_strsub.c
		
OBJ = $(SRCS:.c=.o)

CC = gcc

INCLUDE = libft.h

CFLAG = -Wall -Werror -Wextra

RM = rm -rf

all :		$(NAME)

$(NAME) :	$(OBJ) $(SRCS)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

%.o: %.c
			$(CC) -c $^ $(CFLAG)

clean :
			$(RM) $(OBJ)

fclean : 	clean
			$(RM) $(NAME)

re :		fclean all

