/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:24:03 by mfelida           #+#    #+#             */
/*   Updated: 2024/10/12 13:13:10 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"
#include "libft.h"
#include <stdlib.h>

static size_t _dynarr_extend(t_dynarr *v)
{
	void	*new;

	if (!v)
		return (0);
	new = malloc(2 * v->cap * v->elem_size);
	if (!new)
		return (v->cap);
	ft_memcpy(new, v->data, v->size);
	free(v->data);
	v->data = new;
	v->cap *= 2;
	return (v->cap);
}

size_t	dynarr_pushback(t_dynarr *v, void *d)
{
	if (!v)
		return (0);
	if (!d)
		return (v->size);
	if (v->size == v->cap && _dynarr_extend(v) <= v->size)
		return (v->size);
	ft_memmove(v->data + v->size * v->elem_size, d, v->elem_size);
	return (++v->size);
}

size_t	dynarr_insert(t_dynarr *v, size_t pos, void *d)
{
	if (!v)
		return (0);
	if (!d || pos > v->size
		|| (v->size == v->cap && _dynarr_extend(v) <= v->size))
		return (v->size);
	ft_memmove(v->data + (pos + 1) * v->elem_size,
			v->data + pos * v->elem_size, (v->size - pos) * v->elem_size);
	if (d >= v->data + (pos * v->elem_size)
		&& d < v->data + (v->size * v->elem_size))
		d += v->elem_size;
	ft_memmove(v->data + pos * v->elem_size, d, v->elem_size);
	return (++v->size);
}

void	*dynarr_popback(t_dynarr *v)
{
	void	*ret;

	if (!v)
		return (NULL);
	ret = dynarr_back(v);
	--v->size;
	return (ret);
}

void	*dynarr_erase(t_dynarr *v, size_t pos)
{
	if (!v)
		return (NULL);
	if (pos >= v->size)
		return (NULL);
	if (pos == v->size - 1)
		--v->size;
	else
		ft_memmove(dynarr_at(v, pos),
			dynarr_at(v, pos + 1), (--v->size - pos) * v->elem_size);
	return (dynarr_at(v, pos));
}
