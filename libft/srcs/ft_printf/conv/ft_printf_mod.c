
#include "libft.h"

int		ft_printf_mod(t_printf *pf)
{
	pf->conv.field_min -= 1;
	if (pf->conv.field_fill_char == '0' && pf->conv.field_fill_side == LEFT)
	{
		pf->conv.precision = pf->conv.field_min;
		pf->conv.field_min = 0;
	}
	ft_printf_field_print(pf, LEFT);
	if (pf->conv.field_fill_char == '0')
		pf->printed += ft_print_char_xtime('0', pf->conv.precision, pf->fd);
	pf->printed += ft_putchar_fd('%', pf->fd);
	ft_printf_field_print(pf, RIGHT);
	return (EXIT_SUCCESS);
}
