/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghy2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:55:52 by seunghy2          #+#    #+#             */
/*   Updated: 2023/07/04 20:29:42 by seunghy2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_idata
{
	int				data;
	struct s_idata	*next;
	struct s_idata	*back;
}	t_idata;

typedef struct s_stack
{
	t_idata	*atop;
	t_idata	*abottom;
	t_idata	*btop;
	t_idata	*bbottom;
}	t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ps_swap(t_stack *abstack, int c);
void	ps_push(t_stack *abstack, int c);
void	ps_rotate(t_stack *abstack, int c);
void	ps_revrotate(t_stack *abstack, int c);
size_t	stacksize(t_idata *top);
void	stackout(t_stack *abstack, t_idata *node, int c);
void	stacktop(t_stack *abstack, t_idata *node, int c);
void	stackbottom(t_stack *abstack, t_idata *node, int c);

void	initialset(t_stack *abstack, char **argv, int argc);
size_t	endcheck(t_stack *abstack);
void	errorend(t_stack *abstack);
void	allstackfree(t_stack *abstack);
void	twodfree(char **strs);

t_list	*commandset(int *errorcheck);
void	commanddo(t_stack *abstack, t_list *comlst);

char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);

#endif
