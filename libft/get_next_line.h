/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:41:06 by iwhana            #+#    #+#             */
/*   Updated: 2022/05/25 21:33:03 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 42

char	*read_in_buffer(int fd, char **ostatok, int *key);
char	*ft_strjoin(char const *s1, char const *s2);
char	*create_buf(long len_buf);
size_t	ft_strlen(const char *s);
int		cheak_file_descriptor_and_buf(long len_buf, int fd);
int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*chek_remain(char *ostatoc, char **result);
char	*ft_strcpy(char *dst, char *src);
int		tern_oper(int read_count, char *ostatok, char *p_n);
char	*lounch_strchar(char **p_n, char *buf);
#endif
