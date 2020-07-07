/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_sa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/13 16:40:23 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:34:50 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_sa(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;
	int		swap;
	int		in;

	(void)b;
	(void)conv;
	if (!(*a) || !((*a)->next))
		return (1);
	tmp = *a;
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
