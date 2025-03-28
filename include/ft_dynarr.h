/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:28:30 by mfelida           #+#    #+#             */
/*   Updated: 2025/03/12 15:45:26 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYNARR_H
# define FT_DYNARR_H

# include <stdlib.h>

# define FTDYNARR_DEFAULT_SIZE  1024

typedef struct s_dynarr
{
	void	*data;
	size_t	size;
	size_t	cap;
	size_t	elem_size;
	void	*_me;
}	t_dynarr;

// create_delete.c
t_dynarr	*dynarr_new(size_t	size, size_t elem_size);
t_dynarr	*dynarr_copy(t_dynarr *src);
void		*dynarr_free(t_dynarr *v);
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
