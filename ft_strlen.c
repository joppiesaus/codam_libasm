#include <stddef.h> // size_t

size_t	ft_strlen(const char *s)
{
	const char *orig_s = s;

	while (*s)
	{
		s++;
	}
	return orig_s - s;
}
