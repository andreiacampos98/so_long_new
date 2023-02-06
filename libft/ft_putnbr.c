/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:29:04 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 10:14:57 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr(unsigned int value, int *l, int unsig)
{
	if ((int)value < 0 && !unsig)
	{
		ft_putchar('-');
		value *= (-1);
		(*l)++;
	}
	if (value > 9)
	{
		ft_putnbr(value / 10, l, unsig);
		ft_putnbr(value % 10, l, unsig);
	}
	else
		(*l) += ft_putchar(value + '0');
}
