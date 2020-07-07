/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_sb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:09:55 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:37:35 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_sb_r(t_pile **a, t_pile **b)
{
	t_pile	*tmp;
	int		swap;

	(void)a;
	if (!(*b) || !((*b)->next))
		return (1);
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	swap = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = swap;
	return (1);
}
