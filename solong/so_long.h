/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:38:27 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/11 16:38:54 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

# define ERR_PLAN 42

typedef struct s_img
{
    void    *ptr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    char    *addr;
}   t_img;

typedef struct s_map
{
    char    *plan;
    size_t  garo;
    size_t  sero;
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   *empty;
    t_img   *wall;
    t_img   *exit;
    t_img   *collect;
    t_img   *player;
    void    *map_ptr;
    char    *addr;
    int     mapwidth;
    int     mapheight;
}   t_map;

void    plancheck(t_map *map, char *mapname);

void    errorend(t_map *map, int freecode, char *str);
void    undefinederror(char *str);
void    definederror(void);

int     ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
