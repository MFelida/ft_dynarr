/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:02:09 by mfelida           #+#    #+#             */
/*   Updated: 2024/10/12 12:39:00 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"

void	*dynarr_at(t_dynarr *v, size_t pos)
{
	if (!v || pos >= v->size)
		return (NULL);
	return (v->data + pos * v->elem_size);
}

void	*dynarr_front(t_dynarr *v)
{
	if (!v || v->size == 0)
		return (NULL);
	return (v->data);
}

void	*dynarr_back(t_dynarr *v)
{
	if (!v || v->size == 0)
		return (NULL);
	return (dynarr_at(v, v->size - 1));
}
