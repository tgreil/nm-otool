
char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[n])
		n++;
	while (src[i])
	{
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}
