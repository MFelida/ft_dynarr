/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:28:30 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/01 14:15:33 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>

# define FTVECTOR_DEFAULT_SIZE  (1024)
typedef struct s_vector
{
	size_t	size;
	size_t	cap;
	size_t	elem_size;
	void	*data;
}	t_vector;

// create_delete.c
t_vector	*vector_new(size_t	size, size_t elem_size);
void		vector_free(t_vector **v);
// modify.c
size_t		vector_pushback(t_vector *v, void *d);
size_t		vector_insert(t_vector *v, size_t pos, void *d);
void		*vector_popback(t_vector *v);
void		*vector_erase(t_vector *v, size_t pos);
// access.c
void		*vector_at(t_vector *v, size_t pos);
void		*vector_front(t_vector *v);
void		*vector_back(t_vector *v);

#endif // !FT_VECTOR_H
