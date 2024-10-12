/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:28:30 by mfelida           #+#    #+#             */
/*   Updated: 2024/10/12 12:37:55 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYNARR_H
# define FT_DYNARR_H

# include <stdlib.h>

# define FTDYNARR_DEFAULT_SIZE  (1024)

typedef struct s_dynarr
{
	size_t	size;
	size_t	cap;
	size_t	elem_size;
	void	*data;
}	t_dynarr;

// create_delete.c
t_dynarr	*dynarr_new(size_t	size, size_t elem_size);
void		dynarr_free(t_dynarr **v);
// modify.c
size_t		dynarr_pushback(t_dynarr *v, void *d);
size_t		dynarr_insert(t_dynarr *v, size_t pos, void *d);
void		*dynarr_popback(t_dynarr *v);
void		*dynarr_erase(t_dynarr *v, size_t pos);
// access.c
void		*dynarr_at(t_dynarr *v, size_t pos);
void		*dynarr_front(t_dynarr *v);
void		*dynarr_back(t_dynarr *v);

#endif // !FT_DYNARR_H
