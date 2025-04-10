/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:35:08 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/03/21 21:41:21 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_write_line(char *letter);
char	*ft_after_line(char *letter);
size_t	ft_strlen2(char *str);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);

#endif