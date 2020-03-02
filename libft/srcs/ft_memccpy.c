
#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*c_dest;
	unsigned char	*c_src;
	size_t			i;

	i = 0;
	c_src = (unsigned char *)src;
	c_dest = (unsigned char *)dest;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		if (c_src[i] == (unsigned char)c)
			return ((void *)(c_dest + i + 1));
		i++;
	}
	return (NULL);
}
