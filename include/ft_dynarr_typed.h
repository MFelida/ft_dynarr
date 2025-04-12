/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynarr_typed.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifelida <mifelida@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:36:15 by mifelida          #+#    #+#             */
/*   Updated: 2025/04/12 14:25:59 by mifelida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DYNARR_TYPED_H
# define FT_DYNARR_TYPED_H

# define DECLARE_TYPED_DYNARR(_DYNARR_TYPE, _ELEM_TYPE, _PRFX)\
typedef struct s_##_PRFX\
{\
	void	*data;\
	size_t	size;\
	size_t	cap;\
	size_t	elem_size;\
	void	*_me;\
}	_DYNARR_TYPE;\
\
_DYNARR_TYPE	*_PRFX##_new(size_t	size);\
_DYNARR_TYPE	*_PRFX##_copy(_DYNARR_TYPE *src);\
void			*_PRFX##_free(_DYNARR_TYPE *v);\
\
size_t			_PRFX##_pushback(_DYNARR_TYPE *v, _ELEM_TYPE d);\
size_t			_PRFX##_insert(_DYNARR_TYPE *v, size_t pos, _ELEM_TYPE d);\
_ELEM_TYPE		_PRFX##_popback(_DYNARR_TYPE *v);\
_ELEM_TYPE		_PRFX##_erase(_DYNARR_TYPE *v, size_t pos);\
\
_ELEM_TYPE		_PRFX##_front(_DYNARR_TYPE *v);\
_ELEM_TYPE		_PRFX##_back(_DYNARR_TYPE *v);

# define DEFINE_TYPED_DYNARR(_DYNARR_TYPE, _ELEM_TYPE, _PRFX)\
_DYNARR_TYPE	*_PRFX##_new(size_t	size)\
{\
	return ((_DYNARR_TYPE*) dynarr_new(size, sizeof(_ELEM_TYPE)));\
}\
\
_DYNARR_TYPE	*_PRFX##_copy(_DYNARR_TYPE *src)\
{\
	return ((_DYNARR_TYPE*) dynarr_copy((t_dynarr*) src));\
}\
void	*_PRFX##_free(_DYNARR_TYPE *v)\
{\
	return (dynarr_free((t_dynarr*) v));\
}\
\
size_t	_PRFX##_pushback(_DYNARR_TYPE *v, _ELEM_TYPE d)\
{\
	return (dynarr_pushback((t_dynarr*) v, &d));\
}\
size_t	_PRFX##_insert(_DYNARR_TYPE *v, size_t pos, _ELEM_TYPE d)\
{\
	return (dynarr_insert((t_dynarr*) v, pos, &d));\
}\
_ELEM_TYPE	_PRFX##_popback(_DYNARR_TYPE *v)\
{\
	return (*(_ELEM_TYPE*) dynarr_popback((t_dynarr*) v));\
}\
_ELEM_TYPE	_PRFX##_erase(_DYNARR_TYPE *v, size_t pos)\
{\
	return (*(_ELEM_TYPE*) dynarr_erase((t_dynarr*) v, pos));\
}\
\
_ELEM_TYPE	_PRFX##_front(_DYNARR_TYPE *v)\
{\
	return (*(_ELEM_TYPE*) dynarr_front((t_dynarr*) v));\
}\
_ELEM_TYPE	_PRFX##_back(_DYNARR_TYPE *v)\
{\
	return (*(_ELEM_TYPE*) dynarr_back((t_dynarr*) v));\
}

#endif // !FT_DYNARR_TYPED_H
