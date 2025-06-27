/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stash                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: update_stash — Practice Mode: Copy / Recall
*/

char	*update_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;
	size_t	len;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != 
