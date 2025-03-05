/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:58:56 by mfelida           #+#    #+#             */
/*   Updated: 2025/03/05 20:10:32 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"
#include "libft.h"

#include <stdlib.h>

t_dynarr	*dynarr_new(size_t capacity, size_t elem_size)
{
	t_dynarr	*res;

	if (elem_size == 0)
		return (NULL);
	res = malloc(sizeof(t_dynarr));
	if (!res)
		return (NULL);
	res->elem_size = elem_size;
	res->size = 0;
	if (capacity > 0)
		res->cap = capacity;
	else
		res->cap = FTDYNARR_DEFAULT_SIZE;
	res->data = malloc(res->cap * res->elem_size);
	if (!res->data)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

t_dynarr	*dynarr_copy(t_dynarr *src)
{
	t_dynarr	*res;

	res = dynarr_new(src->size, src->elem_size);
	if (!res)
		return (NULL);
	ft_memcpy(res->data, src->data, src->size * src->elem_size);
	res->cap = src->cap;
	res->elem_size = src->elem_size;
	res->size = src->size;
	return (res);
}

void	dynarr_free(t_dynarr **v)
{
	free((*v)->data);
	free(*v);
	*v = NULL;
}
