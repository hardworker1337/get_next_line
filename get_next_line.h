#ifndef	GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 42 
#endif
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char	*dst, const char *src);
char	*allocate_ptr_mem(char **ptr, unsigned int size);
void	initialize_ptr(char **holder, char **get_chars, char **line_founded);
int	ft_strlen(const char *str);
char	*ft_strjoin(char  *s1, char  *s2, int size);
char 	*get_next_line(int fd);
#endif
