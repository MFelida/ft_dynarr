/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:02:09 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/01 14:11:51 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*vector_at(t_vector *v, size_t pos)
{
	if (!v || pos >= v->size)
		return (NULL);
	return (v->data + pos * v->elem_size);
}

void	*vector_front(t_vector *v)
{
	if (!v || v->size == 0)
		return (NULL);
	return (v->data);
}

void	*vector_back(t_vector *v)
{
	if (!v || v->size == 0)
		return (NULL);
	return (vector_at(v, v->size - 1));
}
