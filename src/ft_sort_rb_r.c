/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_rb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 21:02:56 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:35:38 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_rb_r(t_pile **a, t_pile **b)
{
	t_pile	*last;
	t_pile	*new;

	(void)a;
	if (!*b || ft_pile_size(*b) < 2)
		return (1);
	last = *b;
	while (last->next)
		last = last->next;
	new = ft_recreate_elem_r(last->data);
	new->next = *b;
	*b = new;
	last = *b;
	while (last->next->data != (*b)->data)
		last = last->next;
	free(last->next);
	last->next = NULL;
	return (1);
}
