/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:47:48 by mfelida           #+#    #+#             */
/*   Updated: 2024/03/02 19:13:08 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "ft_vector.h"

//test_create_delete.c
void	test_vector_new(void);
//exit_test.c
void	exit_test(t_vector	*v, const char *msg);
#endif // !TESTS_H
