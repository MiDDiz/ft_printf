/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaftana <jnaftana@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:34:45 by jnaftana          #+#    #+#             */
/*   Updated: 2021/11/23 17:56:16 by jnaftana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
 * This is the main function. The starting point of ft_printf.
 * We use this to make all the calls to the methods that compose the functionality
 * of the main function.
 * 
 *  get_num_args -> Number of valid '%arg' instances in order to initialize v_args
 *  printf_handler -> main functionality
 * 
 *  return value: the number of characters printed.
*/

int	ft_printf(const char *str, ...)
{
	size_t	size;
	va_list	v_args;
	size_t	n_print_char;

	n_print_char = 0;
	size = get_num_args(str);
	va_start(v_args, str);
	printf_handler(str, v_args, &n_print_char, size);
	va_end(v_args);
	return (n_print_char);
}

/*
 * This function is used to get the total ammount of valid '%arg' occurences 
 */

size_t	get_num_args(char const *str)
{
	char	*ptr_str;
	size_t	num_args;

	ptr_str = (char *)str;
	num_args = 0;
	while (*ptr_str)
	{
		if (*ptr_str == '%' && is_arg(*(ptr_str + 1)))
		{
			num_args++;
		}
		ptr_str++;
	}
	return (num_args);
}

/*
 * This is the main functionality function.
 * It iterates for the whole str passed finding valid '%args' occurences.
 * If not found we print the character normally.
 * If we found an arg, we pass everything to a args handler function.
 * 
 * Arguments: 
 * 		str -> the main string
 * 		v_args -> the list of arguments passed
 * 		n_args -> the number of arguments passed (maybe unnecesary)
 * 		ptr_n_printd -> pointer to the size_t that stores the num of characters printed.
 * 		
*/

void	printf_handler (const char *str, va_list v_args, size_t *ptr_n_printed, size_t n_params)
{
	char	*ptr_str;

	ptr_str = (char *)str;
	while (*ptr_str)
	{
		if (*ptr_str == '%' && is_arg(*(ptr_str + 1)))
		{
			ptr_str++;
			n_params--;
			args_handler(*ptr_str, v_args, ptr_n_printed);
			ptr_str++;
		}
		else
		{
			ft_putchar_fd(*ptr_str, 1);
			*ptr_n_printed += 1;
			ptr_str++;
		}
	}
}

/*
 * 
*/

void	args_handler(char arg_type, va_list v_args, size_t *ptr_n_printed)
{
	if (arg_type == 'c')
		p_char((char) va_arg(v_args, int), ptr_n_printed);
	else if (arg_type == 's')
		p_str(va_arg(v_args, char *), ptr_n_printed);
	else if (arg_type == 'd' || arg_type == 'i')
		p_int(va_arg(v_args, int), ptr_n_printed);
	else if (arg_type == 'u')
		p_uint(va_arg(v_args, unsigned int), ptr_n_printed);
	else if (arg_type == 'x')
		p_hex(va_arg(v_args, unsigned int), ptr_n_printed);
	else if (arg_type == 'X')
		p_hexup(va_arg(v_args, unsigned int), ptr_n_printed);
	else if (arg_type == 'p')
		p_hexup((size_t) va_arg(v_args, void *), ptr_n_printed);
	else if (arg_type == '%')
		p_char('%', ptr_n_printed);
}