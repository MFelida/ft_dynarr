/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:42:23 by mifelida          #+#    #+#             */
/*   Updated: 2025/09/19 23:44:29 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dynarr.h"

#include <stdlib.h>

void	dynarr_free(void *dynarr)
{
	free(&((t_dynarr_header*)dynarr)[-1]);
}
