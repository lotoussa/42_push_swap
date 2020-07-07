/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 16:29:38 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:26:02 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

void			ft_pile_del(t_pile **pile)
{
	t_pile		*tmp;
	t_pile		*ret;

	ret = *pile;
	while (ret)
	{
		tmp = ret->next;
		free(ret);
		ret = tmp;
	}
	*pile = NULL;
}

static int		ft_reset_main_error(t_pile **a, t_pile **b)
{
	ft_pile_del(a);
	if (*b)
		ft_pile_del(b);
	ft_putendl_fd("Error", 2);
	return (0);
}

static int		ft_reset_main(t_pile **a, t_pile **b, t_conv *conv)
{
	ft_pile_del(a);
	if (*b)
		ft_pile_del(b);
	if (conv)
		free(conv->tab);
	return (0);
}

int				second_main(t_pile **a, t_pile **b, t_conv *conv)
{
	if (ft_check_sort(*a, *b))
	{
		ft_reset_main(a, b, conv);
		return (0);
	}
	if (!(ft_convert_tab(a, conv)))
	{
		ft_reset_main(a, b, conv);
		return (0);
	}
	ft_fill_index(a, conv);
	if (conv->len < 4)
		ft_little_sort(*a, conv);
	else if (conv->len < 6)
		ft_try_sort(*a, *b, conv);
	else
		ft_recursive(*a, *b, conv);
	ft_reset_conv(conv);
	return (1);
}

int				main(int argc, char **argv)
{
	t_pile		*a;
	t_pile		*b;
	t_conv		conv;

	b = NULL;
	if (argc < 2)
		return (0);
	if (!(ft_fill_a(&a, argc, argv)))
	{
		ft_reset_main_error(&a, &b);
		return (0);
	}
	second_main(&a, &b, &conv);
	return (0);
}
