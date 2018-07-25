/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:46:04 by tgreil            #+#    #+#             */
/*   Updated: 2018/07/22 14:24:09 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include "libft.h"
# include "util.h"

# define EXIT_SUCCESS	0
# define EXIT_ERROR		-1
# define DEFAULT_FILE	"a.out"

/*
**		nm.c
*/
int				ft_nm(char *file_name);
int				main(int ac, char **av);

#endif
