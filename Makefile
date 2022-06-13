CC			= gcc

CPPFLAGS	= -I/Users/$(USER)/.brew/opt/readline/include

INC			= -I./Libft -I./includes

CFLAGS		= $(CPPFLAGS) -Wall -Werror -Wextra

LFLAGS		= -ltermcap -L libft/ -lft -lreadline

NAME		= minishell
LIB_PATH	= ./Libft
LIBFT_NAME	= ./Libft/libft.a

SOURCES =	sources/main.c																\
			sources/parser/parser.c														\
			sources/parser/parse_redirections.c											\
			sources/parser/parse_redirections_2.c										\
			sources/parser/parse_endstring.c											\
			sources/parser/parse_endcommand.c											\
			sources/parser/parse_asterix.c												\
			sources/parser/check_input.c												\
			sources/parser/check_input_2.c												\
			sources/parser/parse_endcommand_2.c											\
			sources/utilities/utilities_list.c											\
			sources/utilities/utilities_list_2.c										\
			sources/utilities/utilities_string.c										\
			sources/execute/execute.c													\
			sources/utilities/utils.c													\
			sources/execute/cmd_find.c													\
			sources/signals/signals.c													\
			sources/builtins/echo.c														\
			sources/builtins/cd.c														\
			sources/builtins/env.c														\
			sources/builtins/exit.c														\
			sources/builtins/export.c													\
			sources/builtins/unset.c													\
			sources/builtins/pwd.c														\
			sources/builtins/false.c													\
			sources/builtins/true.c														\
			sources/execute/execute_utils.c												\
			sources/execute/execute_utils_2.c											\
			sources/env/env_utils.c														\
			sources/execute/redirect.c													\
			sources/execute/manage_main.c


OBJECTS 	= $(SOURCES:.c=.o)
%.o: %.c
			@$(CC) -Wall -Wextra -Werror $(CPPFLAGS) $(INC) -o $@ -c $<


all:		$(NAME)

$(NAME): 	$(LIBFT_NAME) $(OBJECTS)
			@$(CC) $(OBJECTS) $(CFLAGS) $(LFLAGS) -o $@

$(LIBFT_NAME):

			@make -C $(LIB_PATH) | fmt -c $$(tput cols)

clean:

			@rm -f $(OBJECTS)
			@make fclean -C $(LIB_PATH)

fclean:

			@make clean
			@rm -f $(NAME)
			@make fclean -C $(LIB_PATH)

re: 		fclean all

val:
			docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -ti -v $(PWD):/test memory-test:0.1 bash && cd test
