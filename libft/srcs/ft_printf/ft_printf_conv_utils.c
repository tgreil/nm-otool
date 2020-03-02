
#include "libft.h"

void		ft_printf_conv_sign(char *s, t_pf_conversion conv)
{
	if (conv.to_sign == TRUE && s[0] == ' ')
		s[0] = '+';
}

size_t		ft_printf_conv_print(char *s, t_pf_conversion conv, int fd)
{
	if (s[0] != ' ' || conv.space_it == TRUE)
		return (ft_putstr_fd(s, fd));
	else
		return (ft_putstr_fd(s + 1, fd));
}
