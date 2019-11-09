#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "header.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int	i;
  	i = 0;
    while (*(str + i) != '\0')
    {
		my_putchar (*(str + i));
		i = i + 1;
    }
}

int	my_strlen(char *str)
{
	int	i;

  	i = 0;
  	while (*(str + i) != '\0')
  	{
		i = i + 1;
 	}
  	return (i);
}

int my_strcmp(char *s1, char *s2)
{
	int	i;

  	i = 0;
  	while( (s1[i] != '\0') && (s2[i] != '\0'))
  	{
		if(s1[i] < s2[i])
			return (-1);
      	else if(s1[i] > s2[i])
			return (1);
      	i++;
    }
  	if (my_strlen(s1) < my_strlen(s2))
    	return (-1);
  	else if (my_strlen(s1) > my_strlen(s2))
    	return (1);
  	return (0);
}
