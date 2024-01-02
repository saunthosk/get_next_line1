/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuneer <smuneer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:50:08 by smuneer           #+#    #+#             */
/*   Updated: 2023/11/21 14:59:46 by smuneer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen( const char *s );
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*get_one_line(int fd, char *st_line);
char	*ft_rest_str(char *full_str);
char	*get_one_line(int fd, char *st_line);
char	*ft_line_static(char *full_str);
#endif