/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:14:53 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/19 16:41:49 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen((char *)src);
	if (size == 0)
		return (len_src);
	len_dst = ft_strlen(dest);
	if (size < len_dst)
		return (len_src + size);
	while (src[i] != '\0' && (len_dst + i) < (size - 1))
	{
		dest[len_dst + i] = src[i];
		i++;
	}
	dest[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/*int	main()
{
	char	s1[] = "42 Porto Aliados";
	char	s2[] = "Porto";

	printf("%d", ft_strlcat(s1, s2, 4));
	//printf("%d", strlcat(s1, s2, 4));
}*/
