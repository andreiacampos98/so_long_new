/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:32:32 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/17 10:13:36 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_puthex_ptr(unsigned long long value, int *l)
{
	if (value > 15)
	{
		ft_puthex_ptr(value / 16, l);
		ft_puthex_ptr(value % 16, l);
	}
	else
	{
		if (value < 10)
			(*l) += ft_putchar(value + '0');
		else
			(*l) += ft_putchar(value - 10 + 'a');
	}
}

int	ft_putptr(unsigned long long p)
{
	int	size;

	size = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	size += write(1, "0x", 2);
	ft_puthex_ptr(p, &size);
	return (size);
}
