
char	*ft_strncat(char *dest, const char *src, int nb)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[n])
		n++;
	while (src[i] && i < nb)
	{
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}
