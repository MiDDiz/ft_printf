/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_types_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:55:57 by jnaftana          #+#    #+#             */
/*   Updated: 2021/11/23 17:56:15 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	p_uint(unsigned int num, size_t *ptr_n_printed)
{
	char	*n_str;

	n_str = ft_utoa(num);
	ft_putstr_fd(n_str, 1);
	*ptr_n_printed += ft_strlen(n_str);
}

void	p_hex(size_t num, size_t *ptr_n_printed)
{
	char	*n_str;

	n_str = ft_hextoa(num);
	ft_putstr_fd(n_str, 1);
	*ptr_n_printed += ft_strlen(n_str);
}

void	p_hexup(size_t num, size_t *ptr_n_printed)
{
	char	*n_str;

	n_str = ft_hextoa(num);
	n_str = ft_strupper(n_str);
	ft_putstr_fd(n_str, 1);
	*ptr_n_printed += ft_strlen(n_str);
}
