/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:21:17 by saich             #+#    #+#             */
/*   Updated: 2021/12/08 17:21:19 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1024

int					get_next_line(int fd, char **line);
int					has_return(char *str);
size_t				ft_strlen(const char *s);
char				*join_str(const char *s1, const char *s2);

#endif
