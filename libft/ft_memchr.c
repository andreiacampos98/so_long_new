/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:36:56 by marvin            #+#    #+#             */
/*   Updated: 2022/11/07 17:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sptr;

	i = 0;
	sptr = (unsigned char *) s;
	while (i < n)
	{
		if (sptr[i] == (unsigned char) c)
			return (&sptr[i]);
		i++;
	}
	return (NULL);
}

/*int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;
   char *ret1;

   ret = memchr(str, ch, 4);
   ret1 = ft_memchr(str, ch, 4);

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("String after |%c| is - |%s|\n", ch, ret1);

   return (0);
}*/
