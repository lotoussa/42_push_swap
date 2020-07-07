/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recreate_elem.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:24:37 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 01:00:03 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

t_pile		*ft_recreate_elem(int data, t_conv *conv)
{
	t_pile		*pile;
	int			in;
	int			i;

	i = 0;
	while (i < conv->len)
		if (conv->tab[i++] == data)
			break ;
	in = i - 1;
	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	pile->data = data;
	pile->index = in;
	pile->next = NULL;
	return (pile);
}
