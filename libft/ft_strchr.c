/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:49:44 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/08 19:38:18 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*int main()
{
    char    str[15] = "CFDHAbkojjd";
    int     c = 'z';
    char    *res;

    res = ft_strchr(str, c);
    if(res == NULL)
        printf("%s\n", "nao tem");
    else
        printf("%s\n", res);
    printf("%s", strchr(str, c));
    return(0);
}*/
