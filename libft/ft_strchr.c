/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:24:28 by ysoyturk          #+#    #+#             */
/*   Updated: 2024/11/01 19:11:12 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int a)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)a)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)a)
		return ((char *)(s + i));
	return (NULL);
}
