/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:28:57 by marvin            #+#    #+#             */
/*   Updated: 2022/11/13 20:28:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s != 0 && f != 0)
	{
		i = 0;
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}

/*void    *f(unsigned int i, char *c)
{
	c[i] = c[i] - 32;
}

int main()
{
	char    str1[] = "abc";
	char    *str2;
	printf("%s\n", str1);
    printf("%p\n", str1);
    ft_striteri(str1, *f);
	printf("%s\n", str1);
    printf("%p\n", str1);
}*/