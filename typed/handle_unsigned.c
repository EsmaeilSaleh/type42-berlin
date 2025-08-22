/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: handle_unsigned — Practice Mode: Copy / Recall
*/

int	handle_unsigned(va_lsit args)
{
	unsgined int n = va_arg(args, unsigned int);
	chat *str = ft_uitoa(n);
	int len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return len;
}
