/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:57:05 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/20 11:08:32 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*int main()
{
    char    *s1;
    char    *s2;
    int     n;

    s1 = "CApiar para aqui!!!";
    s2 = "Cao e copiar e comparar";
    n = 10;
    printf("%d\n", ft_strncmp(s1, s2, n));
    printf("%d", strncmp(s1, s2, n));
}*/
