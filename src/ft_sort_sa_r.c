/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_sa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/13 16:40:23 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:37:21 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_sa_r(t_pile **a, t_pile **b)
{
	t_pile	*tmp;
	int		swap;

	(void)b;
	if (!(*a) || !((*a)->next))
		return (1);
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	swap = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = swap;
	return (1);
}
