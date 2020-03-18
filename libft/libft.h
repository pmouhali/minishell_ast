/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:29:48 by pmouhali          #+#    #+#             */
/*   Updated: 2020/03/18 11:50:57 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ft_printf/ft_dprintf.h"
# include <linux/limits.h>

# define true  1
# define false 0

# define BUFFER_SIZE 30

# define BASE_16_MIN	"0123456789abcdef"
# define BASE_16_MAJ	"0123456789ABCDEF"
# define BASE_10 		"0123456789"
# define BASE_BIN		"01"
# define BASE_8			"01234567"

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putstr(const char *str);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));
int				ft_index(const char *s, int c);
int				ft_indexr(const char *s, int c);
void			ft_tabfree(void **tab);
void			ft_tabprint(const void *tab[], void (*print)(const void *));
int				ft_tablen(const void *tab[]);
void			**ft_tabdup(const void *tab[], void *(*dup)(const void *));
void			**ft_tabpush(void *tab[], const void *elem, int index, void *(*dup)(const void *));
int				ft_tabindex(const void *tab[], const void *e, int (*cmp)(const void *, const void *));
void			**ft_tabdelete(void *tab[], const void *e, int (*cmp)(const void *, const void *), void *(*dup)(const void*));
void			**ft_tabdeletem(void *tab[], const void *e, int (*cmp)(const void *, const void*));
int				ft_tabsort(void *tab[], int (*cmp)(const void *, const void *));
int				get_next_line(int fd, char **line);
char			*ft_strjoinplus(char *s1, char *s2, int c);
void			*ft_memalloc(size_t size);
void			ft_strdel(char **as);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);
void			ft_memdel(void **ap);
char			*arrondi(char *str, size_t prec);
char			*ft_llutoa_base(unsigned long long n, char *base);
char			*ft_ltoa_base(long n, char *base);
char			*ft_ftoa(long double n, size_t prec);
char			*ft_lltoa(long long n);
char			*ft_ultoa_base(unsigned long n, char *base);
char			*ft_lltoa_base(long long n, char *base);
char			*ft_llutoa(unsigned long long n);
char			*ft_uitoa(unsigned int n);
char			*ft_ultoa(unsigned long n);
char			*ft_bintoa(void *obj, size_t t);
char			*ft_uitoa_base(unsigned int n, char *base);
size_t			ft_strlenn(const char *str, char c);
char			*ft_strnew(size_t size);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strrev(char *str);
char			*ft_strncut(char *dest, int n, int d);

#endif
