/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recreate_elem.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:24:37 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:34:01 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int			ft_pile_size(t_pile *pile)
{
	int			size;

	size = 0;
	while (pile)
	{
		pile = pile->next;
		size++;
	}
	return (size);
}

t_pile		*ft_recreate_elem_r(int data)
{
	t_pile		*pile;

	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	pile->data = data;
	pile->next = NULL;
	return (pile);
}
