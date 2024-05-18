/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:09:15 by nafia             #+#    #+#             */
/*   Updated: 2024/05/17 11:17:05 by nafia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*tmp;

	tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i++;
	}
	if (tmp[i] == (char)c)
		return (&tmp[i]);
	return (NULL);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char *ret = dst;

	while ((*dst++ = *src++));
	return ret;
}
