/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:16:09 by marvin            #+#    #+#             */
/*   Updated: 2022/11/07 21:16:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_null_str(void)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char) * 1);
	if (substr == NULL)
		return (0);
	substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lens;
	size_t	j;
	char	*f;

	if (!s)
		return (0);
	lens = ft_strlen((char *)s);
	j = 0;
	if (len > lens)
		len = lens - start;
	if (lens < (size_t)start)
		return (ft_null_str());
	f = malloc(sizeof(char) * (len + 1));
	if (!f)
		return (NULL);
	while (j < len)
	{
		f[j] = s[start + j];
		j++;
	}
	f[j] = '\0';
	return (f);
}

/*int main()
{
    char *str = "Andreia";
    int c = 2;
    size_t  len = 3;

    printf("%s", ft_substr(str, c, len));
}*/
