/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:19:18 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 07:19:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		i = (unsigned int) n * -1;
	}
	else
		i = (unsigned int) n;
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd((i % 10) + '0', fd);
	}
	else
		ft_putchar_fd(i + '0', fd);
}

/*int	main()
{
	int	f;

	f = open("teste1", O_WRONLY | O_CREAT | O_RDONLY);
	ft_putnbr_fd(-10, f);
	close(f);
}*/