/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:20:49 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/19 16:04:37 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*int main()
{
    char    dest[] = "A Andreia e linda";;
    char    src[] = "aaaa";

    printf("%p\n", (char *)ft_memcpy(dest, src, 2));
    printf("%s\n", dest);
    printf("%p\n", (char *)memcpy(dest, src, 2));
    printf("%s", dest);
    return(0);
}*/
