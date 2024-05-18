/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:39:26 by nafia             #+#    #+#             */
/*   Updated: 2024/05/17 15:54:47 by nafia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char  *s1, char  *s2, int size)
{
	char	*tmp;
	int		i;
	int		j;

	if (!allocate_ptr_mem(&tmp, ft_strlen(s1) + ft_strlen(s2) + 1))
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < size)
	{
		tmp[i + j] = s2[j];
		j++;
	}
	free(s1);
	tmp[i + j] = '\0';
	return (tmp);
}

char	*clean_buffer(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (buffer);
}
void	initialize_ptr(char **holder, char **get_chars, char **line_founded)
{
	*holder = NULL;
	*get_chars = NULL;
	*line_founded = NULL;
}

char	*allocate_ptr_mem(char **ptr, unsigned int size)
{
	*ptr = (char *)malloc(size);
	if (!(*ptr))
		return (NULL);
	ft_bzero(*ptr, size);
	return (*ptr);	
}
char	*get_line(char **holder, char **get_chars, int fd, int *read_value )
{
//	int	read_value;
	
	*read_value = 1;
	while (!ft_strchr(*holder, '\n') && *read_value > 0)
	{
		if (!allocate_ptr_mem(get_chars, BUFFER_SIZE + 1))
		{
			*holder = clean_buffer(*holder);
			return (NULL);
		}
		*read_value = read(fd, *get_chars, BUFFER_SIZE);
		if (*read_value == -1)
			return (NULL);
		if (*read_value > 0)
		{
			*holder = ft_strjoin(*holder, *get_chars, *read_value);
			if (!holder)
				return (NULL);
		}
		*get_chars = clean_buffer(*get_chars);
	}
	return (*holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*get_chars;
	char		*line_founded;
	int		read_value;

	initialize_ptr(&holder, &get_chars, &line_founded);
	if (fd >= 0)
	{
	if (!allocate_ptr_mem(&holder, 1))
		return (NULL);
	if (!get_line(&holder, &get_chars, fd, &read_value))
		return (NULL);	
	if (!allocate_ptr_mem(&line_founded, strlen(holder) + 1))
	{
		holder = clean_buffer(holder);
		return (NULL);
	}
	if (read_value == 0 && holder[0] == '\0')
		return (NULL);
	else
		ft_strcpy(line_founded, holder);
	holder = clean_buffer(holder);
}
	return (line_founded);
}

