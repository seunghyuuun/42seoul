/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:38:27 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/13 17:04:18 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

# define ERR_PLAN 42
# define BUFFER_SIZE 42
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_map
{
	char	*plan;
	size_t	garo;
	size_t	sero;
	void	*mlx;
	void	*win;
	void	*empty;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*enemy;
	void	*player1;
	void	*player2;
	size_t	collection;
	int		pnum;
}	t_map;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t	i2d(t_map *map, size_t g, size_t s);

void	plancheck(t_map *map, int fd);
void	pathcheck(t_map *map);
void	planset(t_map *map);
int		key_hook(int keycode, t_map *map);

void	errorend(t_map *map, int freecode, char *str);
void	undefinederror(char *str);
void	definederror(void);

char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
