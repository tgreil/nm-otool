/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 11:50:39 by tgreil            #+#    #+#             */
/*   Updated: 2018/07/22 14:23:58 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		ft_nm_print_64(char *content, struct symtab_command *sc)
{
	int				tab[sc->nsyms];
	struct nlist_64	*symoff;
	uint32_t		i;

	i = 0;
	ft_bzero((void *)tab, sizeof(int) * sc->nsyms);
	symoff = (struct nlist_64 *)(content + sc->symoff);
	while (i < sc->nsyms)
	{
		ft_printf("%s\n", content + sc->stroff + symoff[tab[i]].n_un.n_strx);
		i++;
	}
	return (EXIT_SUCCESS);
}

int		ft_nm_parse_64(char *content)
{
	struct load_command		*lc;
	struct mach_header_64	*mh;
	struct symtab_command	*sc;
	int						i;

	i = 0;
	lc = (struct load_command *)(content + sizeof(struct mach_header_64));
	mh = (struct mach_header_64 *)content;
	while (i < (int)mh->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			break ;
		lc = (struct load_command *)((void *)lc + lc->cmdsize);
		i++;
	}
	sc = (struct symtab_command *)lc;
	ft_nm_print_64(content, sc);
	return (EXIT_SUCCESS);
}

int		ft_nm_parse(char *content)
{
	struct mach_header	*mh;

	mh = (struct mach_header *)content;
	if (mh->magic == MH_MAGIC_64)
		ft_nm_parse_64(content);
	return (EXIT_SUCCESS);
}

int		ft_nm(char *file_name)
{
	void		*content;
	struct stat	buf;
	int			fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (ft_error("nm", file_name, "no such file", EXIT_ERROR));
	if (fstat(fd, &buf) < 0)
		return (EXIT_ERROR);
	if (!(content = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)))
		return (EXIT_ERROR);
	if (ft_nm_parse((char *)content) == EXIT_ERROR)
		return (EXIT_ERROR);
	if (munmap(content, buf.st_size) < 0)
		return (EXIT_ERROR);
	close(fd);
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	int	i_av;

	i_av = 1;
	if (ac > 1)
	{
		while (i_av < ac)
		{
			ft_printf("%s%s:\n", ac > 2 ? "\n" : "", av[i_av]);
			ft_nm(av[i_av]);
			i_av++;
		}
	}
	else
	{
		ft_printf("%s:\n", DEFAULT_FILE);
		ft_nm(DEFAULT_FILE);
	}
	return (EXIT_SUCCESS);
}
