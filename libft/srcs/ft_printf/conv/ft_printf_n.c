
#include "libft.h"

int		ft_printf_n(t_printf *pf)
{
	int *n;

	n = va_arg(pf->ap, int *);
	if (n)
		*n = pf->printed;
	return (EXIT_SUCCESS);
}
