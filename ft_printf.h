/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:45:26 by jnaftana          #+#    #+#             */
/*   Updated: 2021/10/23 11:47:05 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#define is_arg(a) ((a=='c') || (a=='s') || (a=='p') || (a=='d') || (a=='i') || \
					(a=='u') || (a=='x') || (a=='X') || (a=='%'))

int		ft_printf(char const *s, ...);
void	printf_handler (const char *str, va_list v_args, size_t n_args, size_t *ptr_n_printed);
size_t	get_num_args(char const *str);
void	args_handler(char arg_type, va_list v_args, size_t *ptr_n_printed);

#endif