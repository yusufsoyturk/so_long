/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:09:01 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/03/21 21:42:33 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *text, ...);
int	ft_putchar3(char c);
int	ft_strlen3(const char *c);
int	ft_putstr3(char *c);
int	ft_nbr(int nbr);
int	ft_convert(size_t nbr, char *base, char type);

#endif
