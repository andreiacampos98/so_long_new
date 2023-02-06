/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:49:51 by anaraujo          #+#    #+#             */
/*   Updated: 2022/12/17 10:14:05 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	s = ptr;
}

/*int main()
{
    char buffer[10] ="Andreia";
 
    ft_bzero(&buffer, 10);
    printf("\nImprimir: %s\n", buffer);
    return (0);
}*/
