/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_plus_flag                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: handle_plus_flag — Practice Mode: Copy / Recall
*/

int	handle_plus_flag(int n)
{
	if (n >= 0)
		return (printf("+%d", n));
	return (printf("%d", n));
}
