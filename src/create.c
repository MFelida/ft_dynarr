/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:25:10 by mifelida          #+#    #+#             */
/*   Updated: 2025/09/19 23:59:26 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"
#include "libft.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void	*dynarr_new(size_t capacity, size_t element_size)
{
	t_dynarr_header	*header;

	header = malloc(sizeof(t_dynarr_header) + capacity * element_size);
	if (!header)
		return (NULL);
	header->capacity = capacity;
	header->element_size = element_size;
	header->size = 0;
	return (header + 1);
}

void	*dynarr_copy(void *src)
{
	t_dynarr_header	*header;
	t_dynarr_header	*new;

	if (!src)
		return (NULL);
	header = &((t_dynarr_header *) src)[-1];
	new = malloc(sizeof(t_dynarr_header) + header->capacity * header->element_size);
	if (!new)
		return (NULL);
	*new = *header;
	ft_memmove(&new[1], &header[1], header->capacity * header->element_size);
	return (new + 1);
}
