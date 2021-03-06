#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;

	a = -1;
	if (!dst && !src)
		return (0);
	while (dstsize > ++a)
	{
		*(dst + a) = *(src + a);
		if (!*(src + a))
			return (ft_strlen(src));
	}
	*(dst + a - 1) = '\0';
	return (ft_strlen(src));
}
