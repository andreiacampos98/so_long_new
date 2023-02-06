/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:03:38 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/19 16:19:55 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(str);
	if (c == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (0);
}

/*int main()
{
    char    *str;
    int     c;
    char    *res;

    str = "ssssaa";
    c = 'b';
    res = ft_strrchr(str, c);
    if(res == NULL)
        printf("%s\n", "nao tem");
    else
        printf("%s\n", res);
    printf("%s", strrchr(str, c));
}*/
