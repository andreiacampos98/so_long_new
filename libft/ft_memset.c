/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:43:30 by anaraujo          #+#    #+#             */
/*   Updated: 2022/11/08 19:38:14 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main()
{
    char buffer[11];
    char *string;
 
    ft_memset(buffer, 0, sizeof(buffer));
    string = (char *) ft_memset(buffer,'A', 10);
    printf("\nBuffer contents: %s\n", string);
}*/
