/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_ra.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 20:11:18 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 00:59:49 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_ra(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*last;
	t_pile	*new;

	(void)b;
	if (!*a || ft_pile_size(*a) < 2)
		return (1);
	last = *a;
	while (last->next)
		last = last->next;
	new = ft_recreate_elem(last->data, conv);
	new->next = *a;
	*a = new;
	last = *a;
	while (last->next->data != (*a)->data)
		last = last->next;
	free(last->next);
	last->next = NULL;
	return (1);
}
