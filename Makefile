NAME = minishell

FLAGS = -Wall -Wextra -Werror

LIBS = minishlib.a libft/libft.a

$(NAME) : libft minishlib
	gcc $(FLAGS) $(LIBS) -o $(NAME)

BUILTINS =	change_dir.c echo.c env.c \
			export.c ft_pwd.c unset.c

MINISHFCT = env_tool.c ft_perrorc.c btree_delete.c btree_node_new.c \
			process_container.c eval_node.c run_process.c \
			try_path.c build_path.c \
			process_tools.c

ALL_SRCS = $(MINISHFCT) $(addprefix builtins/,$(BUILTINS))

OBJS = $(BUILTINS:.c=.o) $(MINISHFCT:.c=.o)

.PHONY: libft all
.SILENT: libft clean fclean re minishlib $(NAME)

all: $(NAME)

# $(NAME)

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
