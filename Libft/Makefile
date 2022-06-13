NAME 	= libft.a

CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -c

SOURCES =	sources/ft_atoi.c			\
			sources/ft_bzero.c			\
			sources/ft_calloc.c			\
			sources/ft_isalnum.c		\
			sources/ft_isalpha.c		\
			sources/ft_isascii.c		\
			sources/ft_isdigit.c		\
			sources/ft_isprint.c		\
			sources/ft_isspace.c		\
			sources/ft_itoa.c			\
			sources/ft_llabs.c			\
			sources/ft_lstadd_back.c	\
			sources/ft_lstadd_front.c	\
			sources/ft_lstclear.c		\
			sources/ft_lstdelone.c		\
			sources/ft_lstiter.c		\
			sources/ft_lstlast.c		\
			sources/ft_lstmap.c			\
			sources/ft_lstnew.c			\
			sources/ft_lstsize.c		\
			sources/ft_memccpy.c		\
			sources/ft_memchr.c			\
			sources/ft_memcmp.c			\
			sources/ft_memcpy.c			\
			sources/ft_memmove.c		\
			sources/ft_memset.c			\
			sources/ft_putchar_fd.c		\
			sources/ft_putnbr_fd.c		\
			sources/ft_putendl_fd.c		\
			sources/ft_putstr_fd.c		\
			sources/ft_split.c			\
			sources/ft_strchr.c			\
			sources/ft_strdup.c			\
			sources/ft_strjoin.c		\
			sources/ft_strlcat.c		\
			sources/ft_strlcpy.c		\
			sources/ft_strlen.c			\
			sources/ft_strlen.c			\
			sources/ft_strmapi.c		\
			sources/ft_strncmp.c		\
			sources/ft_strnstr.c		\
			sources/ft_strrchr.c		\
			sources/ft_strtrim.c		\
			sources/ft_substr.c			\
			sources/ft_tolower.c		\
			sources/ft_toupper.c		\
			sources/ft_ulltoabase.c		\

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
		@$(CC) $(CFLAGS) -o $@ -c $<

all: 	$(NAME)

bonus: 	all

$(NAME): $(OBJECTS)
		@ar cr $@ $(OBJECTS)

clean:
		@rm -f $(OBJECTS)

fclean: clean
		@rm -f $(NAME)

re: 	fclean all
