#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
