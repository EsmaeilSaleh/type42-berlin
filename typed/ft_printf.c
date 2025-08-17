/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_printf — Practice Mode: Copy / Recall
*/

int	ft_printf(conat char *format, ...)
{
	va_list	args;
	int		count;

	count = parse_format(format, args);
	va_end(args);
	return (count);
}
