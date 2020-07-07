/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_sort.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 21:29:25 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 12:16:58 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_check_sort(t_pile *a, t_pile *b)
{
	if (b)
		return (0);
	if (ft_pile_size(a) < 2)
		return (1);
	while (a->next)
	{
		if (a->data < a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
