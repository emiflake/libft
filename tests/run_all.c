/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_all.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 18:18:37 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/19 18:20:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "emitest.h"

int	main(void)
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
		emi_assert(strcmp(str, "") == 0);
	}

	emi_trial("memcpy");
	{
		char *src = "hello, world";
		char *dest = malloc(sizeof(char) * 32);
		ft_bzero(dest, 32);
		ft_memcpy(dest, src, 12);
		ft_memcpy(dest + 12, src, 12);
		ft_memcpy(NULL, NULL, 0);
		
		emi_assert(strcmp(dest, "hello, worldhello, world") == 0);

		ft_memcpy(dest, dest + 5, ft_strlen(dest));
		emi_assert(strcmp(dest, ", worldhello, world") == 0);
	}

	emi_trial("memccpy");
	{
		char *src = "hello, world";
		char *dest = malloc(sizeof(char) * 32);
		ft_bzero(dest, 32);
		ft_memccpy(dest, src, 'w', 32);
		
		emi_assert(strcmp(dest, "hello, ") == 0);
	}

	emi_trial("memmove");
	{
		char *src = "hiya, how are you 'dave'?";
		size_t len = ft_strlen(src);
		char *dest = malloc(sizeof(char) * len);
		ft_memcpy(dest, src, len);
		ft_memmove(dest + 19, dest, 4);
		emi_assert(strcmp("hiya, how are you 'hiya'?", dest) == 0);
	}

	emi_trial("memchr");
	{
		char *str = "hello, world";
		char *dest = ft_memchr(str, 'w', ft_strlen(str));

		emi_assert(strcmp(dest, "world") == 0);
	}

	emi_trial("memcmp");
	{
		char *s1 = "hello";
		char *s2 = "hella";
		size_t len = ft_strlen(s1);

		ft_memcmp(NULL, NULL, 0);
		
		emi_assert(ft_memcmp(s1, s2, len) == memcmp(s1, s2, len));
	}
	
	emi_trial("strdup");
	{
		char *str = "hello";
		char *copy = ft_strdup(str);

		emi_assert_i(str != copy, "different address");
		emi_assert_i(strcmp(str, copy) == 0, "same contents");
	}

	emi_trial("strlen");
	{
		char *str = "hello, world";

		emi_assert(ft_strlen(str) == 12);
		emi_assert_i(ft_strlen("") == 0, "empty string");
		emi_assert_i(ft_strlen(0) == 0, "NULL");
	}

	emi_debrief();
	return (0);
}
