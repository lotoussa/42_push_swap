/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 17:29:57 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:08:00 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

void		ft_pile_del(t_pile **pile)
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

static int	ft_reset_main_error(t_pile **a, t_pile **b, char **ins)
{
	int		i;

	i = 0;
	ft_pile_del(a);
	if (*b)
		ft_pile_del(b);
	if (ins)
	{
		while (ins[i])
			ft_strdel(&ins[i++]);
		free(ins);
	}
	ft_putendl_fd("Error", 2);
	return (0);
}

static int	ft_reset_main(t_pile **a, t_pile **b, char **ins)
{
	int		i;

	i = 0;
	ft_pile_del(a);
	if (*b)
		ft_pile_del(b);
	if (ins)
	{
		while (ins[i])
			ft_strdel(&ins[i++]);
		free(ins);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	char	**ins;

	b = NULL;
	ins = NULL;
	if (argc < 2)
		return (0);
	if (!(ft_fill_a(&a, argc, argv)))
	{
		ft_reset_main_error(&a, &b, ins);
		return (0);
	}
	ins = ft_read_stdin();
	if (!(ft_exec_ins(ins, &a, &b)))
	{
		ft_reset_main_error(&a, &b, ins);
		return (0);
	}
	ft_printf(ft_check_sort(a, b) ? "OK\n" : "KO\n");
	ft_reset_main(&a, &b, ins);
	return (0);
}
