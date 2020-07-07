/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_a.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 10:56:53 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 04:03:17 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static t_pile	*ft_create(const char *argv)
{
	t_pile		*pile;
	long		n;
	int			check;

	check = 0;
	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	n = ft_atol(argv, &check);
	if (check)
		return (NULL);
	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	pile->data = (int)n;
	pile->next = NULL;
	return (pile);
}

static int		ft_check_double(t_pile **pile)
{
	t_pile		*tmp;
	t_pile		*list;

	list = *pile;
	while (list)
	{
		tmp = list;
		while ((tmp = tmp->next))
			if (tmp->data == list->data)
				return (0);
		list = list->next;
	}
	return (1);
}

static int		ft_split_arg(char *argv, t_pile **pile)
{
	t_pile		*tmp;
	char		**split;
	int			i;

	i = 0;
	split = ft_strsplit(argv, ' ');
	while (split[i])
	{
		if (!(tmp = ft_create(split[i])))
			return (0);
		tmp->next = *pile;
		*pile = tmp;
		i++;
	}
	i = 0;
	while (split[i])
		ft_strdel(&split[i++]);
	free(split);
	return (1);
}

static int		ft_first_fill(char *argv, t_pile **pile)
{
	if (ft_strchr(argv, ' '))
	{
		if (!(ft_split_arg(argv, pile)))
			return (0);
	}
	else
	{
		if (!(*pile = ft_create(argv)))
			return (0);
	}
	return (1);
}

int				ft_fill_a(t_pile **pile, int argc, char **argv)
{
	t_pile		*tmp;
	int			i;

	i = 1;
	if (!(ft_first_fill(argv[i], pile)))
		return (0);
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!(ft_split_arg(argv[i], pile)))
				return (0);
		}
		else
		{
			if (!(tmp = ft_create(argv[i])))
				return (0);
			tmp->next = *pile;
			*pile = tmp;
		}
	}
	if (!(ft_check_double(pile)))
		return (0);
	return (1);
}
