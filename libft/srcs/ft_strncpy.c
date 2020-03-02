
char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && i < n)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
