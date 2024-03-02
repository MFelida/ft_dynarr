/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:54:41 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/02 18:56:59 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include "tests.h"
#include <stdlib.h>
#include <unistd.h>

void	exit_test(t_vector *v, const char *msg)
{
	vector_free(&v);
	ft_fprintf(STDERR_FILENO, "%s\n", msg);
	exit(EXIT_FAILURE);
}
