/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 05:15:06 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 05:56:57 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

void	ft_print(t_pile **pile)
{
	t_pile	*tmp;

	tmp = *pile;
	while (tmp)
	{
		ft_printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n__________________________\n");
}
