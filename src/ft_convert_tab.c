/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 18:18:31 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 18:53:09 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static void			ft_swap_tab(int *tab, int a, int b)
{
	int		tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

static void			ft_quick_sort_tab(int *tab, int start, int end)
{
	int		left;
	int		right;
	int		pivot;

	pivot = tab[start];
	left = start - 1;
	right = end + 1;
	if (start >= end)
		return ;
	while (1)
	{
		while (--right && tab[right] > pivot)
			;
		while (++left && tab[left] < pivot)
			;
		if (left < right)
			ft_swap_tab(tab, left, right);
		else
			break ;
	}
	ft_quick_sort_tab(tab, start, right);
	ft_quick_sort_tab(tab, right + 1, end);
}

int					ft_convert_tab(t_pile **a, t_conv *tab)
{
	t_pile		*tmp;
	int			i;

	i = 0;
	tmp = *a;
	tab->len = ft_pile_size(tmp);
	if (!(tab->tab = (int*)malloc(sizeof(int) * (tab->len))))
		return (0);
	while (tmp)
	{
		tab->tab[i++] = tmp->data;
		tmp = tmp->next;
	}
	ft_quick_sort_tab(tab->tab, 0, i - 1);
	return (1);
}
