/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: sort_list — Practice Mode: Copy / Recall
*/

static void	swapt_content(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swapped;
	t_list	*cur;

	if (!lst)
		return (NULL);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		cur = lst;
		while (cur->next)
		{
			if (cmp((int)(long)cur->content, 
							(int)(long)cur->next->content) > 0)
			{
				swap_content(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
	}
	return (lst);
}
