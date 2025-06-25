/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_putnbr_base — Practice Mode: Copy / Recall
*/

void	ft_putnbr_base(unsigned int nbr, char *base, int fd)
{
	unsigned int	len;

	len = ft_strlen(base);

	if (nbr >= len)
		ft_putnbr_base(nbr / len, base, fd);
	write(fd, &base[nbr % len], 1);
}
