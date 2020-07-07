/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_backtracking_sort.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 20:26:12 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 04:39:26 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static void	ft_init_p(t_back *back)
{
	back->p[0] = &ft_sort_sa;
	back->p[1] = &ft_sort_ra;
	back->p[2] = &ft_sort_rra;
	back->type[0] = ft_strdup("sa");
	back->type[1] = ft_strdup("ra");
	back->type[2] = ft_strdup("rra");
	back->save = ft_strnew(1);
}

int			ft_try_backtraking(t_pile *a, t_back *back, t_conv *conv, int hit)
{
	t_pile		*b;
	int			i;

	i = 0;
	b = NULL;
	if (ft_check_sort(a, b) && hit < 2)
		return (1);
	if (hit > 1)
		return (0);
	while (i < 3)
	{
		back->p[i](&a, &b, conv);
		if (ft_try_backtraking(a, back, conv, (hit + 1)))
		{
			back->save = ft_strjoin(back->save, back->type[i]);
			back->save = ft_strjoin(back->save, "\n");
			return (1);
		}
		else
			i++;
	}
	return (0);
}

int			ft_backtracking_sort(t_pile *a, t_pile *b, t_conv *conv)
{
	t_back		back;
	char		**split;
	int			j;

	j = 0;
	ft_init_p(&back);
	ft_try_backtraking(a, &back, conv, 0);
	split = ft_strsplit_m(back.save, '\n');
	ft_strdel(&back.save);
	ft_pile_del(&a);
	while (j < 3)
	{
		back.p[j] = NULL;
		ft_strdel(&back.type[j++]);
	}
	j = 0;
	while (split[j] && ft_printf("%s\n", split[j]))
		ft_strdel(&split[j++]);
	return (0);
}
