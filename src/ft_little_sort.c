/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_little_sort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 04:59:59 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:34:18 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int				ft_little_sort(t_pile *a, t_conv *conv)
{
	if (conv->len == 2)
		ft_printf("sa\n");
	else if (a->index < a->next->index && a->next->index < ft_last(a)->index)
		ft_printf("ra\nsa\n");
	else if (ft_last(a)->data > a->data && a->data > a->next->data)
		ft_printf("ra\n");
	else if (ft_last(a)->data < a->data && a->data < a->next->data)
		ft_printf("sa\nra\n");
	else if (ft_last(a)->data < a->next->data && a->next->data > a->data)
		ft_printf("rra\n");
	else if (a->data > a->next->data && a->next->data < ft_last(a)->data)
		ft_printf("sa\n");
	ft_pile_del(&a);
	return (1);
}
