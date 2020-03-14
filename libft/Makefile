NAME = libft.a

FLAGS = -Wall -Wextra -Werror

CONV =	ft_atoi.c arrondi.c ft_bintoa.c ft_ftoa.c \
		ft_itoa.c ft_itoabase.c ft_lltoa_base.c \
		ft_lltoa.c ft_llutoa.c ft_llutoa_base.c \
		ft_ltoa_base.c ft_uitoa_base.c ft_uitoa.c \
		ft_ultoa_base.c ft_ultoa.c

STR =	ft_strchr.c ft_strrchr.c \
		ft_strcmp.c ft_strncmp.c \
		ft_strjoinplus.c ft_strlcpy.c \
		ft_strlcat.c ft_strnstr.c \
		ft_strjoin.c ft_strtrim.c \
		ft_strdup.c ft_substr.c ft_strlen.c \
		ft_strmapi.c ft_strdel.c ft_strcat.c \
		ft_strcpy.c ft_strlenn.c ft_strnew.c \
		ft_strndup.c ft_strncpy.c ft_strrev.c \
		ft_strncut.c

MEM = 	ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c

SRCS =  ft_bzero.c \
		ft_index.c ft_indexr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c ft_lstadd_back.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_tablen.c ft_tabfree.c ft_tabdup.c ft_tabpush.c ft_tabindex.c \
		ft_tabdelete.c ft_tabdeletem.c \
		get_next_line.c

FPRINTF =	create_seg.c \
			find_format.c \
			ft_fprintf.c \
			ft_manageflag.c \
			ft_print_base.c \
			ft_print_csp.c \
			ft_print_d.c

ALL_SRCS = $(addprefix srcs/,$(SRCS)) $(addprefix ft_printf/,$(FPRINTF)) $(addprefix mem/,$(MEM)) $(addprefix str/,$(STR)) $(addprefix conv/,$(CONV))

HEADER = libft.h ft_printf/ft_fprintf.h

OBJS = $(SRCS:.c=.o) $(FPRINTF:.c=.o) $(MEM:.c=.o) $(STR:.c=.o) $(CONV:.c=.o)

.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME)

$(NAME): $(ALL_SRCS) $(HEADER)
		gcc $(FLAGS) -c $(ALL_SRCS) -I./
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all


norme:
	norminette $(SRCS) $(HEADER)
