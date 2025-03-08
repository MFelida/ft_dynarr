/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:24:03 by mfelida           #+#    #+#             */
/*   Updated: 2025/03/08 13:14:51 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"
#include "libft.h"
#include <stdlib.h>

static size_t	_dynarr_extend(t_dynarr *v)
{
	void	*new;

	if (!v || !v->me)
		return (0);
	new = ft_realloc(v->data, 2 * v->cap * v->elem_size,
			v->size * v->elem_size);
	if (new == v->data)
		return (v->cap);
	v->data = new;
	v->cap *= 2;
	return (v->cap);
}

size_t	dynarr_pushback(t_dynarr *v, void *d)
{
	if (!v || !v->me)
		return (0);
	if (!d)
		return (v->size);
	if (v->size == v->cap && v->cap >= _dynarr_extend(v))
		return (v->size);
	ft_memmove(v->data + v->size * v->elem_size, d, v->elem_size);
	return (++v->size);
}

size_t	dynarr_insert(t_dynarr *v, size_t pos, void *d)
{
	if (!v || !v->me)
		return (0);
	if (!d || pos > v->size
		|| (v->size == v->cap && v->cap >= _dynarr_extend(v)))
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

	if (!v || !v->me)
		return (NULL);
	ret = dynarr_back(v);
	--v->size;
	return (ret);
}

void	*dynarr_erase(t_dynarr *v, size_t pos)
{
	if (!v || !v->me)
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
