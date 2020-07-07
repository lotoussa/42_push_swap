/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_sb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:09:55 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:35:04 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_sb(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;
	int		swap;
	int		in;

	(void)a;
	(void)conv;
	if (!(*b) || !((*b)->next))
		return (1);
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	in = tmp->index;
	swap = tmp->data;
	tmp->index = tmp->next->index;
	tmp->data = tmp->next->data;
	tmp->next->index = in;
	tmp->next->data = swap;
	return (1);
}
