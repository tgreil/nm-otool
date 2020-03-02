
#include <stdio.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!(*to_find))
		return ((char *)str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
				j++;
			if (!to_find[j])
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
