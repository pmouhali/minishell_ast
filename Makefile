NAME = minishell

FLAGS = -Wall -Wextra -Werror

LIBS = minishlib.a libft/libft.a

PROMPT_AND_PARSE = the_prompt.c

BUILTINS =	change_dir.c echo.c env.c \
			export.c ft_pwd.c unset.c

MINISHFCT = env_tool.c ft_perrorc.c

ALL_SRCS = $(MINISHFCT) $(addprefix builtins/,$(BUILTINS)) $(addprefix prompt_and_parse/,$(PROMPT_AND_PARSE))

OBJS = $(BUILTINS:.c=.o) $(MINISHFCT:.c=.o) $(PROMPT_AND_PARSE:.c=.o)

.PHONY: libft all
.SILENT: libft clean fclean re minishlib $(NAME)

all: $(NAME)

$(NAME) : libft minishlib
	gcc $(FLAGS) minishell.c $(LIBS) -o $(NAME)

libft:
	cd libft/ && make -s && make -s clean

minishlib : libft
	gcc $(FLAGS) -c $(ALL_SRCS) -I./
	ar rc minishlib.a $(OBJS)
	ranlib minishlib.a
	make -s clean

clean:
		rm -f $(OBJS)
		cd libft/ && make -s clean

fclean: clean
		rm -f $(NAME)
		rm -f minishlib.a
		cd libft/ && make -s fclean

re: fclean all
