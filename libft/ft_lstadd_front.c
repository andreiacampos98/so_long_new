/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:34:04 by marvin            #+#    #+#             */
/*   Updated: 2022/11/16 20:34:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{	
		if (!lst)
			*lst = new;
		new->next = *lst;
		*lst = new;
	}
}

/*int		main()
{
	t_list	**lst;
	t_list	*new;

	lst[0]->content = "Andreia";
	lst[1]->content = "Andreia1";
	lst[0]->next = 0;
	new->next = 0;
	new->content = "c";
	printf("%p\n", lst);
	printf("%p\n", new);
	ft_lstadd_front(lst, new);
	printf("%p\n", lst);
	printf("%p\n", new);
}*/