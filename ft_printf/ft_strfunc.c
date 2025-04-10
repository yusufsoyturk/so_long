/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:46:39 by ysoyturk          #+#    #+#             */
/*   Updated: 2024/12/06 21:31:49 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar3(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen3(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_putstr3(char *c)
{
	if (!c)
		return (write(1, "(null)", 6));
	return (write(1, c, ft_strlen3(c)));
}
