/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 12:04:14 by tgreil            #+#    #+#             */
/*   Updated: 2018/07/22 12:12:00 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int		ft_error(char *binary, char *file, char *error, int status)
{
	ft_printf("!2!%s: %s%s%s\n", binary, file ? file : "",
													file ? ": " : "", error);
	return (status);
}
