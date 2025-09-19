/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:44:55 by mifelida          #+#    #+#             */
/*   Updated: 2025/09/19 23:52:35 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"
#include <stddef.h>
#include <stdlib.h>

size_t	dynarr_size(void *dynarr)
{
	return (((t_dynarr_header *)dynarr)[-1].size);
}

size_t	dynarr_capacity(void *dynarr)
{
	return (((t_dynarr_header *)dynarr)[-1].capacity);
}

size_t	dynarr_extend(void **dynarr)
{
	t_dynarr_header	*header;
	t_dynarr_header	*new;

	header = &(*(t_dynarr_header **) dynarr)[-1];
	new = malloc(sizeof(t_dynarr_header) + header->capacity * header->element_size * 2);
	new->capacity = header->capacity * 2;
	new->element_size = header->element_size;
	new->size = header->size;
	free(header);
	*dynarr = &new[1];
	return (new->capacity);
}
