/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:58:56 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/02 19:17:41 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

#include <stdlib.h>

t_vector	*vector_new(size_t capacity, size_t elem_size)
{
	t_vector	*res;

	if (elem_size == 0)
		return (NULL);
	res = malloc(sizeof(t_vector));
	if (!res)
		return (NULL);
	res->elem_size = elem_size;
	res->size = 0;
	if (capacity > 0)
		res->cap = capacity;
	else
		res->cap = FTVECTOR_DEFAULT_SIZE;
	res->data = malloc(res->cap * res->elem_size);
	if (!res->data)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

void	vector_free(t_vector **v)
{
	free((*v)->data);
	free(*v);
	*v = NULL;
}
