#include "libft.h"

void			*ft_realloc(void *s, size_t old_size, size_t size)
{
	void		*new;

	if (s == NULL)
		return (malloc(size));
	new = malloc(size);
	if (old_size > size)
		memcpy(new, s, size);
	else
		memcpy(new, s, old_size);
	free(s);
	return (new);
}
