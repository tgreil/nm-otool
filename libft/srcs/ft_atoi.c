
#include "libft.h"

int			ft_atoi(const char *str)
{
	int		is_neg;
	int		nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	is_neg = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f'))
		str++;
	if (*str == '-')
		is_neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && i < 19)
		nbr = nbr * 10 + str[i++] - '0';
	if (i == 19 && is_neg < 0)
		return (0);
	if (i == 19 && is_neg > 0)
		return (-1);
	return (is_neg * nbr);
}
