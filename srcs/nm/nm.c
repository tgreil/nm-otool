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

// TO REMOVE
#include <stdio.h>

void	ft_nm_print_64_onetype(struct nlist_64 *symoff)
{
	char	ctp;

	ft_printf("%zx ", symoff->n_type);
	if (symoff->n_sect == NO_SECT)
	{
		ctp = 'A';
		ctp = 'U';
	}
	else
	{

		if (symoff->n_type == N_SECT)
			ctp = 't';
		else
			ctp = 'T';
	}
	ft_printf("%c ", ctp);
}

void	ft_nm_print_64_one(char *content, struct nlist_64 *symoff, struct symtab_command *sc)
{
	if (symoff->n_value > 0)
		ft_printf("%016zx ", symoff->n_value);
	else
		ft_printf("%16s ", "");
	ft_nm_print_64_onetype(symoff);
	ft_printf("%s\n", content + sc->stroff + symoff->n_un.n_strx);
}

struct nlist_64	*ft_nm_symoff_copy(struct nlist_64 *symoff, size_t size)
{
	struct nlist_64	*symoff_copy;
	size_t			i;

	i = 0;
	if (!(symoff_copy = malloc(sizeof(struct nlist_64) * size)))
		return (NULL);
	while (i < size)
	{
		ft_memcpy(&symoff_copy[i], &symoff[i], sizeof(struct nlist_64));
		i++;
	}
	return (symoff_copy);
}

void	ft_nm_symoff_sort(struct nlist_64 *symoff, size_t size, char * content, size_t stroff)
{
	struct nlist_64	tmp;
	size_t			i;

	i = 0;

	while (size > 1 && i + 1 < size)
	{
		if (ft_strcmp(content + stroff + symoff[i].n_un.n_strx,
				content + stroff + symoff[i + 1].n_un.n_strx) > 0)
		{
			tmp = symoff[i];
			symoff[i] = symoff[i + 1];
			symoff[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int		ft_nm_print_64(char *content, struct symtab_command *sc)
{
	struct nlist_64	*symoff;
	struct nlist_64	*symoff_copy;
	uint32_t		i;

	i = 0;
	symoff = (struct nlist_64 *)(content + sc->symoff);
	if (!(symoff_copy = ft_nm_symoff_copy(symoff, sc->symoff)))
		return (EXIT_ERROR);
	ft_nm_symoff_sort(symoff_copy, sc->nsyms, content, sc->stroff);
	while (i < sc->nsyms)
	{
		ft_nm_print_64_one(content, &symoff_copy[i], sc);
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
	if (lc->cmd != LC_SYMTAB)
	{
		ft_printf("!2!Unable to find symtab in load command\n");
		return (EXIT_ERROR);
	}
	ft_nm_print_64(content, sc);	
	return (EXIT_SUCCESS);
}

int		ft_nm_parse(char *content)
{
	struct mach_header	*mh;

	mh = (struct mach_header *)content;
/*	printf("\
Mach_Header structure:\n\
magic:%u\n\
cputype:%u\n\
cpusubtype:%u\n\
filetype:%u\n\
ncmds:%u\n\
sizeofcmds:%u\n\
flags:%u\n\
", mh->magic, mh->cputype, mh->cpusubtype, mh->filetype, mh->ncmds, mh->sizeofcmds, mh->flags);*/
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
			if (ac > 2)
				ft_printf("\n%s:\n", av[i_av]);
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
