/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_stdin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 15:54:24 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 05:24:23 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static int		ft_len_word(const char *s, size_t index, char c)
{
	size_t		j;

	j = 0;
	while (s[index] != c && s[index] != '\0')
	{
		index++;
		j++;
	}
	return (j);
}

static int		cpt_mot(char const *s, char c)
{
	int		i;
	size_t	j;

	i = 0;
	j = (s[0] != c ? 1 : 0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	return (j - 1);
}

static char		**ft_strsplit_m(char const *s, char c)
{
	char		**tab;
	size_t		nb_mot;
	size_t		i;
	size_t		j;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	nb_mot = cpt_mot(s, c);
	tab = (char **)malloc(sizeof(char *) * nb_mot + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (nb_mot--)
	{
		while (s[i] == c && i < len)
			i++;
		tab[j++] = ft_strsub(s, i, ft_len_word(s, i, c));
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_read_stdin(void)
{
	char	*line;
	char	*ret;
	char	*tmp;
	char	**ins;

	ret = ft_memalloc(1);
	while (get_next_line(0, &line))
	{
		tmp = ret;
		ret = ft_strjoin(ret, line);
		free(tmp);
		tmp = ret;
		ret = ft_strjoin(ret, "|");
		free(tmp);
		free(line);
	}
	ins = ft_strsplit_m(ret, '|');
	free(ret);
	return (ins);
}
