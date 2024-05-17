#include "../libft.h"

/// @brief 		Iterates the list ’lst’ and applies the function ’f’ on
///				the data of each node.
/// @param lst 	Address of a pointer to a node.
/// @param f 	Address of the function used to iterate on the list.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		lst = lst->next;
		f(tmp->data);
		tmp = lst;
	}
}
