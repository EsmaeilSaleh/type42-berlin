/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: flood_fill — Practice Mode: Copy / Recall
*/

typedef struct s_point
{
	int	x;
	int	y;
+
} t_point;

#include "flood_fill.h"

void	fill(char **tab, t_point size, char target, int row, int col)
{
	// Question 1: am I out of bounds?
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	//Question 2: am I the wrong char, or already filled?
	if (tab[row][col] != target || tab[row][col] == 'F')
		return ;
	// Question 3: fill me, then spread to neighbors
	tab[row][col] = 'F';
	fill(tab, size, target, row - 1, col);
	fill(tab, size, target, row + 1, col);
	fill(tab, size, target, row, col - 1);
	fill(tab, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point target)
{
	char target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.y, begin.x);
}
