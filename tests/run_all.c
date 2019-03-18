#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "emitest.h"

int main(void)
{
	emi_init("libft unit tests");

	emi_trial("memset");
	{
		char *str;
		str = malloc(sizeof(char) * 16);
		ft_memset(str, 'a', 15);
		str[15] = '\0';

		emi_assert(strcmp(str, "aaaaaaaaaaaaaaa") == 0);

		ft_memset(str, 'b', 1);
		emi_assert(strcmp(str, "baaaaaaaaaaaaaa") == 0);

		ft_memset(str, 'a', 0);
		emi_assert(strcmp(str, "baaaaaaaaaaaaaa") == 0);
		emi_assert(ft_memset(0, 'a', 10) == NULL);
	}

	emi_trial("bzero");
	{
		char *str;
		str = malloc(sizeof(char) * 16);
		/* useless overhead, 
		 * but for testing sake, 
		 * it's good */
		ft_bzero(str, 16);
		ft_memset(str, 'a', 15);

		emi_assert(strcmp(str, "aaaaaaaaaaaaaaa") == 0);

		ft_bzero(str, 16);
		ft_bzero(NULL, 0);
		emi_assert(strcmp(str, "") == 0);
	}

	emi_trial("memcpy");
	{
		char *src = "hello, world";
		char *dest = malloc(sizeof(char) * 32);
		ft_bzero(dest, 32);
		ft_memcpy(dest, src, 12);
		ft_memcpy(dest + 12, src, 12);
		
		emi_assert(strcmp(dest, "hello, worldhello, world") == 0);
	}

	emi_trial("memccpy");
	{
		char *src = "hello, world";
		char *dest = malloc(sizeof(char) * 32);
		ft_bzero(dest, 32);
		ft_memccpy(dest, src, 'w', 32);
		
		emi_assert(strcmp(dest, "hello, ") == 0);
	}

	emi_debrief();
	return (0);
}
