/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:23:56 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/11 18:23:58 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    undefinederror(char *str)
{
    write(2, str, ft_strlen(str));
    exit(-1);
}

void    definederror(void)
{
    perror("Error\n");
    exit(-1);
}

void    errorend(t_map *map, int freecode, char *str)
{
    free(map->plan);
    if (freecode == ERR_PLAN)
        undefinederror(str);
}