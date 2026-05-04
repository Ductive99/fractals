/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:01:29 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/14 11:01:53 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*current;
// 	t_list	*temp;
// 	t_list	*new;

// 	if (!lst)
// 		return (NULL);
// 	current = lst->next;
// 	new = ft_lstnew((*f)(lst->content));
// 	while (current)
// 	{
// 		temp = ft_lstnew((*f)(current->content));
// 		ft_lstadd_back(&new, temp);
// 		ft_lstdelone(temp, del);
// 		current = current->next;
// 	}
// 	return (new);
// }

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	*new_node;
// 	t_list	*last;

// 	new_list = NULL;
// 	if (!lst || !f || !del)
// 		return (NULL);
// 	while (lst)
// 	{
// 		new_node = ft_lstnew(f(lst->content));
// 		if (!new_node)
// 		{
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		if (!new_list)
// 			new_list = new_node;
// 		else
// 			last->next = new_node;
// 		last = new_node;
// 		lst = lst->next;
// 	}
// 	return (new_list);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
