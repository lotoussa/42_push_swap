/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_rra.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 21:04:15 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:18:07 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int			ft_sort_rra(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;

	(void)b;
	if (!*a || ft_pile_size(*a) < 2)
		return (1);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_recreate_elem((*a)->data, conv);
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	return (1);
}
