/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:43:58 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/02 19:43:24 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include "tests.h"

int	capacity_invalid(t_vector *v, size_t target_capacity)
{
	if (v->cap != target_capacity)
		return (1);
	return 0;
}

int	size_invalid(t_vector *v, size_t target_size)
{
	if (v->size != target_size)
		return (1);
	return (0);
}

void	test_vector_new(void)
{
	t_vector	*v;

	v = vector_new(0, sizeof(int));
	if (capacity_invalid(v, FTVECTOR_DEFAULT_SIZE))
		exit_test(v, "Capacity does not equal default size.");
	vector_free(&v);
	v = vector_new(1, sizeof(int));
	if (capacity_invalid(v, 1))
		exit_test(v, "Capactity does not equal given size.");
	if (size_invalid(v, 0))
		exit_test(v, "Size not 0 of new vector.");
	ft_fprintf(STDOUT_FILENO, "vector_new tests successfull\n");
}
