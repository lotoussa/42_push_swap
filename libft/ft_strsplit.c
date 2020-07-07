/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 03:28:21 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
	int			i;
	size_t		j;

	i = 0;
	j = (s[0] != c ? 1 : 0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
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
