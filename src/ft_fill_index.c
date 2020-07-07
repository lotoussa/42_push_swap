/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_index.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 18:21:33 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 00:41:16 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

void		ft_fill_index(t_pile **a, t_conv *conv)
{
	t_pile		*tmp;
	int			i;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < conv->len)
		{
			if (tmp->data == conv->tab[i++])
			{
				tmp->index = i - 1;
				break ;
			}
		}
		tmp = tmp->next;
	}
}
