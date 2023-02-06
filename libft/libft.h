/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:16:10 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/16 19:34:10 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_issign(char c);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
size_t		ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nitems, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
int			ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_printf(const char *str, ...);
int			ft_format(va_list args, char c);
int			ft_putstr(char *str);
int			ft_putptr(unsigned long long p);
void		ft_putnbr(unsigned int value, int *l, int unsig);
void		ft_puthex(unsigned int value, int *l, int c);
void		ft_puthex_ptr(unsigned long long value, int *l);
char		*ft_read(int fd, char *str);
char		*ft_line(char *str);
char		*ft_str_without_line(char *str);
char		*get_next_line(int fd);
void		handle_errors(char *error_msg);
int			error(char *error_msg);
int			ft_strend_cmp(char *name, char *end);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
