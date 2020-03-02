
#include "libft.h"

void		ft_strclr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}
