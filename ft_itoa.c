#include    "libft.h"

static int	ft_decad(int n);
static char	*ft_swapnum(int n, char *d);
static char	*ft_strrev(char *str);

char	*ft_itoa(int n)
{
	int		b;
	char	*d;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = ft_decad(n);
	d = (char *)malloc(sizeof(char) * b + 1);
	if (!d)
		return (NULL);
	*(d + b) = '\0';
	d = ft_swapnum(n, d);
	d = ft_strrev(d);
	return (d);
}

static int	ft_decad(int n)
{
	int	a;

	a = 1;
	if (n < 0)
	{
		n = -n;
		a += 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		a += 1;
	}
	return (a);
}

static char	*ft_swapnum(int n, char *d)
{
	int		a;
	char	*c;

	a = 0;
	c = (char *)d;
	while (n != 0)
	{
		if (n < 0)
		{
			*(c + a++) = '-';
			n = -n;
		}
		*(c + a++) = n % 10 + 48;
		n = n / 10;
	}
	return (c);
}

static char	*ft_strrev(char *str)
{
	size_t	a;
	size_t	len;
	char	b;

	a = 0;
	len = ft_strlen(str);
	while (len - 1 > a)
	{
		if (*(str + a) == '-')
			a++;
		b = *(str + a);
		*(str + a++) = *(str + len - 1);
		*(str + len-- - 1) = b;
	}
	return (str);
}
