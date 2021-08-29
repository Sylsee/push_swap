/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 01:30:27 by spoliart          #+#    #+#             */
/*   Updated: 2021/08/29 01:36:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int *array, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	j = low;
	i = low - 1;
	pivot = array[high];
	while (j < high)
	{
		if (array[j] <= pivot)
			swap(&array[++i], &array[j]);
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static int	*quick_sort_arr(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort_arr(array, low, pivot - 1);
		quick_sort_arr(array, pivot + 1, high);
	}
	return (array);
}

void	prepare_quick_sort(t_env **env)
{
	int		i;
	t_stack	*tmp;

	(*env)->arr = malloc(sizeof(int) * (*env)->size);
	if (!(*env)->arr)
		print_and_exit("Malloc error");
	i = 0;
	tmp = (*env)->a;
	while (tmp)
	{
		(*env)->arr[i++] = tmp->n;
		tmp = tmp->next;
	}
	(*env)->arr = quick_sort_arr((*env)->arr, 0, (*env)->size - 1);
	(*env)->sorted = 0;
	quick_sort(env, 0, (*env)->size);
}
