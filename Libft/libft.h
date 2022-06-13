/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcloud <dcloud@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:39:43 by dcloud            #+#    #+#             */
/*   Updated: 2022/04/16 21:39:45 by dcloud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Includes
*/
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*
** Structs
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** Functions
*/

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t num, size_t size);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

char			*ft_itoa(int n);
char			*ft_ulltoabase(unsigned long long num, const char *set);
long long		ft_llabs(long long num);

void			ft_lstadd_back(t_list **lst, t_list *toadd);
void			ft_lstadd_front(t_list **lst, t_list *toadd);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(void *ptr, int value, size_t n);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

char			**ft_split(const char *s, char c);
char			*ft_strchr(char *str, int chr);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *str1, const char *str2, size_t n);
char			*ft_strrchr(const char *str, int chr);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_substr(const char *s, unsigned int start, size_t len);

int				ft_tolower(int c);
int				ft_toupper(int c);
#endif
