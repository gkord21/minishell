/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:43:17 by iwhana            #+#    #+#             */
/*   Updated: 2022/04/08 01:27:14 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE 10000
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;

typedef struct s_index
{
	size_t	i;
	int		j;
	int		*ptr_j;
}	t_index;

size_t	ft_strlen(const char *str);
void	*ft_memset(void *buf, int ch, size_t count);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	ft_bzero(void *buf, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strrchr(const char *str, int ch);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		get_next_line(const int fd, char **line);
int		ft_printf(const char *format, ...);
int		ft_wdcounter(char const *str, char c);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
char	*ft_strcat(char *restrict str1, const char *restrict str2);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_putchar(int c);
void	ft_putstr(char *s, int *ptr_j);
void	ft_putnbr(int n, int *ptr_j);
void	ft_putunsignednbr(unsigned int n, int *ptr_j);
void	ft_putlowhexnbr(unsigned int n, int *ptr_j);
void	ft_putuphexnbr(unsigned int n, int *ptr_j);
void	ft_puthexptr(unsigned long long int n, int *ptr_j);
void	ft_putptr(void *ptr, int *ptr_j);
int		ft_printf(const char *fmt, ...);
int		ft_putchar1(char c, int *ptr_j);

#endif
