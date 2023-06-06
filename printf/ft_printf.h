/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:42:47 by seunghy2          #+#    #+#             */
/*   Updated: 2023/06/02 17:46:33 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flag
{
    int hash;
    int space;
    int plus;
    int minus;
    int zero;
    int xx;
    int yy;
}   t_flag;

int	ft_printf(const char *str, ...);
char	*argchanger(va_list arg, char **str);
void    flagstore(t_flag *flag, char *unchange);
int     ft_isflag(int c);

char    *ch_char(char *unchange, int c);
char    *ch_str(char *unchange, char *str);

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
void    *ft_memset(void *b, int c, size_t len);
void    *ft_memcpy(void *dst, const void *src, size_t n);

#endif
