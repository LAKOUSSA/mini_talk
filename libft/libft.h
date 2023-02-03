/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:37:59 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/26 13:21:58 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_strlen(char *s);
char				*ft_strchr(char *s, int find);
char				*ft_strrchr(char *s, int find);
int					ft_strncmp(char *s1, char *s2, int n);
char				*ft_strnstr(char *str, char *to_find, int len);
int					ft_atoi(char *str);

#endif
