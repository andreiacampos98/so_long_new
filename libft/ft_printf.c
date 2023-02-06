/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:51 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 17:25:06 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr((va_arg(args, int)), &len, 0);
	else if (c == 'u')
		ft_putnbr((va_arg(args, int)), &len, 1);
	else if (c == 'x' || c == 'X')
		ft_puthex((va_arg(args, unsigned long long int)), &len, c);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[j] != '\0')
	{
		if (str[j] == '%')
			i += ft_format(args, str[++j]);
		else
			i += ft_putchar(str[j]);
		j++;
	}
	va_end(args);
	return (i);
}

/*int	main(void)
{
	char	c;
	char	*str;
	int		i;

	c = 'C';
	str = "Correto";
	i = -125;
	printf("%*s", 5, str);
	ft_printf("A Andreia e louca\n");
	ft_printf("A Andreia e louca: caracter %c\n", c);
	ft_printf("A Andreia e louca: string %s\n", str);
	ft_printf("A Andreia e louca: inteiro %i\n", i);
	ft_printf("A Andreia e louca: decimal %d\n", i);
	ft_printf("A Andreia e louca: unsigned decimal %u\n", i);
	ft_printf("A Andreia e louca: hexadecimal lower %x\n", i);
	ft_printf("A Andreia e louca: pointer %p\n", &str);
	ft_printf("A Andreia e louca: hexadecimal upper %X\n", i);
	printf("A Andreia e louca\n");
	printf("A Andreia e louca: caracter %c\n", c);
	printf("A Andreia e louca: string %s\n", str);
	printf("A Andreia e louca: inteiro %i\n", i);
	printf("A Andreia e louca: decimal %d\n", i);
	printf("A Andreia e louca: unsigned decimal %u\n", i);
	printf("A Andreia e louca: hexadecimal lower %x\n", i);
	printf("A Andreia e louca: pointer %p\n", &str);
	printf("A Andreia e louca: hexadecimal upper %X\n", i);
	return (0);
}*/
