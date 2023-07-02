
#include "push_swap_bonus.h"

void	ft_free(char *str)
{
	if (str)
		free (str);
}

char	*allfree(char *a, char *b, char *c)
{
	ft_free(a);
	ft_free(b);
	return (c);
}

int	onelinetaker(char **result, char **store, int ready)
{
	char	*storebaby;
	char	*temp;
	char	*baby;

	baby = 0;
	if (!ready)
		*result = ft_strdup("");
	if (!(*store))
		return (0);
	storebaby = ft_strchr(*store, '\n');
	if (storebaby)
	{
		*storebaby = '\0';
		if (*(storebaby + 1))
			baby = ft_strdup(storebaby + 1);
	}
	temp = *result;
	*result = ft_strjoin(temp, *store);
	allfree(temp, *store, 0);
	*store = baby;
	return ((storebaby != 0));
}

void	storejoinbuff(char **store, char *buff, int letters)
{
	char	*temp;

	buff[letters] = '\0';
	if (!(*store))
		*store = ft_strdup("");
	temp = ft_strjoin(*store, buff);
	ft_free(*store);
	*store = temp;
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*result;
	char		*buff;
	int			letters;

	if (onelinetaker(&result, &store, 0) && !(read(fd, store, 0)))
		return (allfree(result, 0, ft_strjoin(result, "\n")));
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (allfree(result, 0, 0));
	letters = read(fd, buff, BUFFER_SIZE);
	if (letters <= 0)
		store = allfree(store, 0, 0);
	while (letters)
	{
		if (letters < 0)
			return (allfree(result, buff, 0));
		storejoinbuff(&store, buff, letters);
		if (onelinetaker(&result, &store, 1))
			return (allfree(buff, result, ft_strjoin(result, "\n")));
		letters = read(fd, buff, BUFFER_SIZE);
	}
	if (!(ft_strlen(result)))
		return (allfree(buff, result, 0));
	return (allfree(buff, 0, result));
}
