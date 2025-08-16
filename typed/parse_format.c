/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: parse_format — Practice Mode: Copy / Recall
*/

int	parse_format(const char *format, va_list args)
{
	int	count;
	
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_arg(*format, args);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	return (count);
}
