
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*last;

	if (!alst || !del)
		return ;
	tmp = *alst;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
		ft_lstdelone(&last, del);
	}
	*alst = NULL;
}
