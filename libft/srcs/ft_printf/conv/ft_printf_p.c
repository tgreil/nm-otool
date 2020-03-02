
#include "libft.h"

int		ft_printf_p(t_printf *pf)
{
	pf->conv.chang = TRUE;
	if (pf->conv.size < 5)
		pf->conv.size = 5;
	ft_printf_xxx(pf, "0123456789abcdef", "0x", 1);
	return (EXIT_SUCCESS);
}
