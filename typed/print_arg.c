/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: print_arg — Practice Mode: Copy / Recall
*/

int	print_arg(char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(va_arg(args, int)));
	else if (specifier == 's')
		return (handle_string(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (handle_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (handle_hex_lower(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (handle_hex_upper(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (handle_pointer(va_arg(args, void *)));
	else if (specifier == '%')
		return (handle_percent());
	return (0);
}
