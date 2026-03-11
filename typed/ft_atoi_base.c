/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaleh <esaleh@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:00:00 by esaleh            #+#    #+#             */
/*   Updated: ✨ type42.berlin by ft trainer ✨        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  type42-berlin — Typing Trainer for 42 Network
**  Function: ft_atoi_base — Practice Mode: Copy / Recall
*/

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;
	int	val;

	res = 0;
	sign = 1;
	if (!str || str_base < 2 || str_base > 16)
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			val = *str - '0';
		if (*str >= 'a' && *str <= 'z')
			val = *str - 'a' + 10;
		if (*str >= 'A' && *str <= 'Z')
			val = *str - 'A' + 10;
		else
			break;
		if (val >= str_base)
			break;
		res = res * str_base + val;
		str++;
	}
	return (res * sign);
}
