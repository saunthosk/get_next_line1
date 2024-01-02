/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuneer <smuneer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:24 by smuneer           #+#    #+#             */
/*   Updated: 2023/11/21 14:59:37 by smuneer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
char	*ft_line_static(char *full_str);
#endif