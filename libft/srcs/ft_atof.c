#include "libft.h"
#include <math.h>

float		ft_atof(char *str)
{
	float	res;
	float	tmp;
	char	*value;
	char	*tmp_value;

	tmp_value = ft_strdup(str);
	value = tmp_value;
	res = (float)ft_atoi(value);
	if ((ft_strchr(value, '.')) && (ft_strchr(value, '|'))
		&& (ft_strchr(value, '.')) < (ft_strchr(value, '|')))
	{
		value = ft_strchr(value, '.');
		if ((ft_strchr(value, '|')))
			value[ft_strchr(value, '|') - value] = '\0';
		tmp = ft_atoi(++value);
		if (res < 0 || str[0] == '-')
			tmp *= -1;
		res += ((ft_strchr(value, ','))) ?
				tmp / (pow(10, ft_strchr(value, ',') - value)) :
				tmp / (pow(10, ft_strlen(value)));
	}
	free(tmp_value);
	return (res);
}
