/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_pa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:16:58 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:25:22 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static int			ft_del_elem(t_pile **pile)
{
	t_pile		*tmp;
	t_pile		*prev;
	int			size;

	prev = *pile;
	size = (ft_pile_size(prev) - 2);
	if (size < 0)
	{
		free(*pile);
		*pile = NULL;
		return (1);
	}
	while (size-- > 0)
		prev = prev->next;
	tmp = prev->next;
	prev->next = NULL;
	free(tmp);
	return (1);
}

int					ft_sort_pa(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*last;
	t_pile	*tmp;

	if (!*b)
		return (1);
	last = ft_last(*b);
	if (!*a)
		*a = ft_recreate_elem(last->data, conv);
	else
	{
		tmp = ft_last(*a);
		tmp->next = ft_recreate_elem(last->data, conv);
	}
	return (ft_del_elem(b));
}
