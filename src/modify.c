/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:24:03 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/02 18:22:05 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

static size_t _vector_extend(t_vector *v)
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

size_t	vector_pushback(t_vector *v, void *d)
{
	if (!v)
		return (0);
	if (!d)
		return (v->size);
	if (v->size == v->cap && _vector_extend(v) <= v->size)
				return (v->size);
	ft_memmove(v->data + v->size * v->elem_size, d, v->elem_size);
	return (++v->size);
}

size_t	vector_insert(t_vector *v, size_t pos, void *d)
{
	if (!v)
		return (0);
	if (!d || pos >= v->size
		|| (v->size == v->cap && _vector_extend(v) <= v->size))
		return (v->size);
	ft_memmove(v->data + (pos + 1) * v->elem_size, v->data + pos * v->elem_size, v->elem_size);
	return (++v->size);
}

void	*vector_popback(t_vector *v)
{
	void	*ret;

	if (!v)
		return (NULL);
	ret = vector_back(v);
	--v->size;
	return (ret);
}

void	*vector_erase(t_vector *v, size_t pos)
{
	if (!v)
		return (NULL);
	if (pos >= v->size)
		return (NULL);
	if (pos == v->size - 1)
		--v->size;
	else
		ft_memmove(vector_at(v, pos), vector_at(v, pos + 1), (--v->size - pos) * v->elem_size);
	return (vector_at(v, pos));
}
