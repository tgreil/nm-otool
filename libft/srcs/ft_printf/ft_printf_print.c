
#include "libft.h"

void	ft_putstr_fill(t_printf *pf, char *str, char fill_c, char side)
{
	int	str_size;
	int	i;

	i = 0;
	str_size = 0;
	while (str[str_size])
		str_size++;
	while (side == LEFT && i + str_size < pf->conv.field_min)
	{
		pf->printed += ft_putchar_fd(fill_c, pf->fd);
		i++;
	}
	pf->printed += ft_putstr_fd(str, pf->fd);
	i += str_size;
	while (side == RIGHT && i < pf->conv.field_min)
	{
		pf->printed += ft_putchar_fd(' ', pf->fd);
		i++;
	}
}
