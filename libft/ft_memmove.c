/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:00:48 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/19 16:10:31 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	dif;

	i = 0;
	dif = dest - src;
	if (!src && !dest)
		return (NULL);
	if (dif < n)
	{
		i = n;
		while (i--)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		while (n--)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*int main()
{
    char    dest[20]= "662345";
    char    src[10]= "12345";

    printf("%p\n", ft_memmove(dest, src, 3));
    printf("%s\n", dest);
    printf("%p\n", memmove(dest, src, 3));
    printf("%s", dest);
    return(0);
}*/
