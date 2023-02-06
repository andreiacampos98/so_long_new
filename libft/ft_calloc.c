/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:37:50 by marvin            #+#    #+#             */
/*   Updated: 2022/11/07 20:37:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;

	a = malloc(nitems * size);
	if (!a)
		return (NULL);
	ft_bzero(a, nitems * size);
	return (a);
}

/*int main () 
{
   int i, n;
   int *a;

   printf("%c", ft_calloc(10, 4));
   return(0);
}*/
