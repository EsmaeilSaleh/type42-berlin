#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int	ft_strlen(char *str)
{
		int	i;

		i = 0;
		while (str[i])
			i++;
		return (i);
}
