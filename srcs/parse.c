/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:45:08 by spoliart          #+#    #+#             */
/*   Updated: 2021/07/30 04:28:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->n == tmp->n)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

static int	check_arg(char *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!s || !s[i] || ft_isspace(s[i]))
		return (-1);
	while (s[i] && (ft_isdigit(s[i]) || ft_isspace(s[i]) || s[i] == '-'
			|| s[i] == '+'))
	{
		if (i > 0 && ft_isspace(s[i - 1])
			&& (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+'))
			ret++;
		i++;
	}
	if (s[i])
		return (-1);
	return (ret);
}

static t_stack	*get_lst(t_stack **lst, char **tab, int len)
{
	t_stack	*tmp;

	if (!tab)
		return (NULL);
	while (len >= 0)
	{
		tmp = ps_new_node(lst, tab[len]);
		if (!tmp)
			return (0);
		*lst = tmp;
		len--;
	}
	return (*lst);
}

static int	create_lst(char *av, t_stack **lst)
{
	int		status;
	char	**tab;
	t_stack	*tmp;

	status = check_arg(av);
	if (status == -1)
		return (0);
	else if (status == 0)
	{
		tmp = ps_new_node(lst, av);
		if (!tmp)
			return (0);
		*lst = tmp;
	}
	else if (status > 0)
	{
		tab = ft_split(av, "\t\n\v\f\r ");
		tmp = get_lst(lst, tab, status);
		ft_free_tab(tab);
		if (!tmp)
			return (0);
		*lst = tmp;
	}
	return (1);
}

t_stack	*ps_parse(int ac, char **av)
{
	t_stack	*lst;

	lst = NULL;
	while (--ac)
	{
		if (!(create_lst(av[ac], &lst)))
		{
			ps_free_lst(lst);
			return (NULL);
		}
	}
	if (is_duplicate(lst))
	{
		ps_free_lst(lst);
		return (NULL);
	}
	return (lst);
}
