/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_ss.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:14:08 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:20:36 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_sort_ss(t_pile **a, t_pile **b, t_conv *conv)
{
	ft_sort_sa(a, b, conv);
	ft_sort_sb(a, b, conv);
	return (1);
}
