/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_rrr.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 21:12:24 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:18:39 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_rrr(t_pile **a, t_pile **b, t_conv *conv)
{
	ft_sort_rra(a, b, conv);
	ft_sort_rrb(a, b, conv);
	return (1);
}
