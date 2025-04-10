/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:46:43 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/03/21 21:41:53 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int nbr)
{
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar3('-');
		return (ft_convert(nbr, "0123456789", 0) + 1);
	}
	return (ft_convert(nbr, "0123456789", 0));
}

int	ft_convert(size_t nbr, char *base, char type)
{
	int		len;
	int		i;
	char	size[50];

	if (nbr == 0)
		return (ft_putchar3('0'));
	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	len = ft_strlen3(base);
	i = 50;
	size[--i] = '\0';
	while (nbr > 0)
	{
		size[--i] = base[nbr % len];
		nbr /= len;
	}
	return (ft_putstr3(size + i));
}
