/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: max — Practice Mode: Copy / Recall
*/

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int	max_val;

	if (!tab || len == 0)
		return (0);
	max_val = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > max_val)
			max_val = tab[i];
		i++;
	}
	return (max_val);
}
