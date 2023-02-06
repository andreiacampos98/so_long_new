/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:30:23 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 10:15:21 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_puthex(unsigned int value, int *l, int c)
{
	if (value > 15)
	{
		ft_puthex(value / 16, l, c);
		ft_puthex(value % 16, l, c);
	}
	else
	{
		if (value < 10)
			(*l) += ft_putchar(value + '0');
		else if (c == 'x')
			(*l) += ft_putchar(value - 10 + 'a');
		else if (c == 'X')
			(*l) += ft_putchar(value - 10 + 'A');
	}
}
