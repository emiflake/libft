/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_all.c                                                :+:    :+:      */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 18:18:37 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/25 13:33:02 by nmartins            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include "libft.h"
#include "emitest.h"

// run extra tests specific to my library
#define EXTRA

int	main(void)
{
	emi_init("libft unit tests");

	emi_trial("First, we check norm");
	emi_norm("../*.c");

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
		{
			char *src = "hello, world";
			char *dest = malloc(sizeof(char) * 32);
			char *dest2 = malloc(sizeof(char) * 32);
			ft_bzero(dest, 32);
			void *ret1 = ft_memccpy(dest, src, 'w', ft_strlen(src));
			ft_bzero(dest2, 32);
			void *ret2 = memccpy(dest2, src, 'w', ft_strlen(src));

			emi_assert(strcmp(dest, "hello, w") == 0);
			emi_assert(memcmp(dest, dest2, 32) == 0);
			emi_assert((unsigned long)ret1 - (unsigned long)dest ==
					(unsigned long)ret2 - (unsigned long)dest2);
		}
		{
			char *src = "hello, world";
			char *dest = malloc(sizeof(char) * 32);
			char *dest2 = malloc(sizeof(char) * 32);
			ft_bzero(dest, 32);
			void *ret1 = ft_memccpy(dest, src, 'z', ft_strlen(src));
			ft_bzero(dest2, 32);
			void *ret2 = memccpy(dest2, src, 'z', ft_strlen(src));

			emi_assert(strcmp(dest, "hello, world") == 0);
			emi_assert(memcmp(dest, dest2, 32) == 0);
			emi_assert((unsigned long)ret1 == (unsigned long)ret2);
		}
		{
			char *src = "hello, world";
			char *dest = malloc(sizeof(char) * 32);
			char *dest2 = malloc(sizeof(char) * 32);
			ft_bzero(dest, 32);
			void *ret1 = ft_memccpy(dest, src, 'd', ft_strlen(src));
			ft_bzero(dest2, 32);
			void *ret2 = memccpy(dest2, src, 'd', ft_strlen(src));

			emi_assert(memcmp(dest, dest2, 32) == 0);
			emi_assert((unsigned long)ret1 - (unsigned long)dest ==
					(unsigned long)ret2 - (unsigned long)dest2);
		}
		{
			char *src = "hello, world";
			char *dest = malloc(sizeof(char) * 32);
			char *dest2 = malloc(sizeof(char) * 32);
			ft_bzero(dest, 32);
			void *ret1 = ft_memccpy(dest, src, 'h', ft_strlen(src));
			ft_bzero(dest2, 32);
			void *ret2 = memccpy(dest2, src, 'h', ft_strlen(src));

			emi_assert(memcmp(dest, dest2, 32) == 0);
			emi_assert((unsigned long)ret1 - (unsigned long)dest ==
					(unsigned long)ret2 - (unsigned long)dest2);
		}
		{
			char *src = "hello, world";
			char *dest = malloc(sizeof(char) * 32);
			char *dest2 = malloc(sizeof(char) * 32);
			ft_bzero(dest, 32);
			void *ret1 = ft_memccpy(dest, src, 'l', 5);
			ft_bzero(dest2, 32);
			void *ret2 = memccpy(dest2, src, 'l', 5);

			emi_assert(memcmp(dest, dest2, 32) == 0);
			emi_assert((unsigned long)ret1 - (unsigned long)dest ==
					(unsigned long)ret2 - (unsigned long)dest2);
		}
	}

	emi_trial("memmove");
	{
		{
			char *src = "hiya, how are you 'dave'?";
			size_t len = ft_strlen(src);
			char *dest = malloc(sizeof(char) * len);
			char *dest2 = malloc(sizeof(char) * len);
			ft_memcpy(dest, src, len);
			memcpy(dest2, src, len);
			ft_memmove(dest + 19, dest, 4);
			memmove(dest2 + 19, dest2, 4);
			emi_assert(strcmp("hiya, how are you 'hiya'?", dest) == 0);
			emi_assert(strcmp("hiya, how are you 'hiya'?", dest2) == 0);
			emi_assert(memcmp(dest, dest2, len + 1) == 0);
		}
		{
			char *src = "hiya, how are you 'dave'?";
			size_t len = ft_strlen(src);
			char *dest = malloc(sizeof(char) * len);
			char *dest2 = malloc(sizeof(char) * len);
			ft_memcpy(dest, src, len);
			memcpy(dest2, src, len);
			ft_memmove(dest + 20, dest, 4);
			memmove(dest2 + 20, dest2, 4);
			printf("'%s' vs '%s'\n", dest, dest2);
			emi_assert(memcmp(dest, dest2, len) == 0);
		}
		{
			char *src = "hiya, how are you 'dave'?";
			size_t len = ft_strlen(src);
			char *dest = malloc(sizeof(char) * len);
			char *dest2 = malloc(sizeof(char) * len);
			ft_memcpy(dest, src, len);
			memcpy(dest2, src, len);
			ft_memmove(dest + 19, dest, 9);
			memmove(dest2 + 19, dest2, 9);
			emi_assert(memcmp(dest, dest2, len + 1) == 0);
		}
	}

	emi_trial("memchr");
	{
		{
			char *str = "hello, world";
			char *dest = ft_memchr(str, 'w', ft_strlen(str));
			char *dest2 = memchr(str, 'w', ft_strlen(str));

			emi_assert(strcmp(dest, "world") == strcmp(dest2, "world"));
		}
		{
			char *str = "hello";
			char *dest = ft_memchr(str, 'w', ft_strlen(str));
			char *dest2 = memchr(str, 'w', ft_strlen(str));

			emi_assert(dest == dest2);
		}
	}

	emi_trial("memcmp");
	{
		{
			char *s1 = "hello";
			char *s2 = "hella";
			size_t len = ft_strlen(s1) + 1;

			emi_assert(ft_memcmp(s1, s2, len) == memcmp(s1, s2, len));
		}
		{
			char *s1 = "";
			char *s2 = "";
			size_t len = ft_strlen(s1) + 1;

			emi_assert(ft_memcmp(s1, s2, len) == memcmp(s1, s2, len));
		}
		{
			char *s1 = "*****";
			char *s2 = "*****";
			size_t len = ft_strlen(s1) + 1;

			emi_assert(ft_memcmp(s1, s2, len) == memcmp(s1, s2, len));
		}
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
		emi_assert(ft_strlen(str) == strlen(str));
		char str2[] = "ok but what about these:\0 huh?";
		emi_assert(ft_strlen(str2) == strlen(str2));
		emi_assert(ft_strlen("*************************") ==
				strlen("*************************"));
		emi_assert(ft_strlen("") == strlen(""));
		emi_assert_i(ft_strlen("") == 0, "empty string");
	}

	emi_trial("strcpy & strncpy");
	{
		char *src = "hallo";
		char dest[40];
		char dest2[40];

		ft_bzero(dest, 40);
		ft_strcpy(dest, src);
		emi_assert(strcmp(dest, "hallo") == 0);
		ft_bzero(dest2, 40);
		strcpy(dest2, src);
		emi_assert_i(memcmp(dest, dest2, 40) == 0,
				"libc version, sanity check");

		char dest3[40];
		char dest4[40];
		ft_bzero(dest3, 40);
		ft_bzero(dest4, 40);
		ft_strncpy(dest3, src, 4);
		strncpy(dest4, src, 4);
		emi_assert_i(memcmp(dest3, dest4, 40) == 0, "libc version for strncpy");
	}

	emi_trial("strcat");
	{
		char str[50] = "Hello ";
		char str3[50] = "Hello ";
		char str2[50] = "World!";
		strcat(str3, str2);
		strcat(str3, " ... ");
		strcat(str3, "Goodbye World!");
		ft_strcat(str, str2);
		ft_strcat(str, " ... ");
		ft_strcat(str, "Goodbye World!");
		emi_assert(strcmp(str, "Hello World! ... Goodbye World!") == 0);
		emi_assert(memcmp(str3, str, 50) == 0);
		emi_assert(strcmp(str2, "World!") == 0);
	}

	emi_trial("strncat");
	{
#ifdef __APPLE__
		char str[50] = "Hello ";
		char str2[50] = "Hello ";
		strncat(str2, "Goodbye World!", 4);
		strncat(str2, " World!", 7);
		ft_strncat(str, "Goodbye World!", 4);
		ft_strncat(str, " World!", 7);
		emi_assert(memcmp(str, str2, 50) == 0);

		char bye[10] = "bye ";
		ft_strncat(bye, bye, 3);
		emi_assert(strcmp(bye, "bye bye") == 0);
#endif
	}

	emi_trial("strlcat");
	{
#ifdef __APPLE__
		{
			char str[50] = "Ok, cool! I am big";
			char str2[50] = "Ok, cool! I am big";
			size_t res = strlcat((char*)str, "Goodbye World!", 10);
			size_t res2 = ft_strlcat((char*)str2, "Goodbye World!", 10);
			emi_assert(memcmp(str, str2, 50) == 0);
			emi_assert(res == res2);
		}
		{
			char str[50] = "Ok, cool!";
			char str2[50] = "Ok, cool!";
			size_t res = strlcat((char*)str, "Go\0odbye World!", 10);
			size_t res2 = ft_strlcat((char*)str2, "Go\0odbye World!", 10);
			emi_assert(memcmp(str, str2, 50) == 0);
			emi_assert(res == res2);
		}
		{
			char str[50] = "Ok, cool!";
			char str2[50] = "Ok, cool!";
			size_t res = strlcat((char*)str, "Goodbye World!", 50);
			size_t res2 = ft_strlcat((char*)str2, "Goodbye World!", 50);
			emi_assert(memcmp(str, str2, 50) == 0);
			emi_assert(res == res2);
		}
#endif
	}

	emi_trial("strchr & strrchr");
	{
		char *src = "hello, world";

		emi_assert(strcmp(ft_strchr(src, 'w'), "world") == 0);
		emi_assert(ft_strchr(src, 'z') == 0);
		emi_assert_i(strcmp(ft_strchr(src, 'o'), "o, world") == 0,
				"strchr the beginning");
		emi_assert_i(strcmp(ft_strrchr(src, 'o'), "orld") == 0,
				"strrchr the end");
	}

	emi_trial("strstr & strnstr");
	{
		char *src = "hello, world";

		emi_assert(strcmp(ft_strstr(src, "w"), strstr(src, "w")) == 0);
		emi_assert(strcmp(ft_strstr(src, "lo"), strstr(src, "lo")) == 0);
		emi_assert(strcmp(ft_strstr(src, ""), strstr(src, "")) == 0);
		emi_assert(ft_strnstr(src, "w", 1) == 0);
		emi_assert(ft_strnstr(src, "w", 4) == 0);
		emi_assert(strcmp(ft_strnstr(src, "w", 10), "world") == 0);
#ifdef __APPLE__
		emi_assert(ft_strnstr(src, "w", 4) == strnstr(src, "w", 4));
#endif
	}

	emi_trial("strcmp & strncmp");
	{
		char *s1 = "hello, world";
		char *s2 = "hello, wòrld";

		emi_assert(ft_strcmp(s1, s2) == strcmp(s1, s2));
		emi_assert(ft_strcmp(s2, s1) == strcmp(s2, s1));
		emi_assert(ft_strcmp("", "") == strcmp("", ""));
		emi_assert(ft_strcmp(s1, "") == strcmp(s1, ""));
		emi_assert(ft_strcmp("", s2) == strcmp("", s2));
		emi_assert_i(ft_strncmp(s1, s2, 0) == 0, "zero length search");
		emi_assert(ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
	}

	emi_trial("is*****");
	{
		emi_assert(ft_isalpha('H'));
		emi_assert(!ft_isalpha('*'));
		emi_assert(ft_isdigit('0'));
		emi_assert(ft_isdigit('9'));
		emi_assert(!ft_isdigit('a'));
		emi_assert(!ft_isdigit('*'));
		emi_assert(ft_isascii('$'));
		emi_assert(!ft_isascii(2000));
		emi_assert(!ft_isascii(-5));
		emi_assert(!ft_isprint('\t'));
		emi_assert(ft_isprint(' '));
		emi_assert(ft_isprint('@'));
#ifdef EXTRA
		emi_assert(ft_iswhite(' '));
		emi_assert(ft_iswhite('\t'));
		emi_assert(ft_iswhite('\n'));
		emi_assert(!ft_iswhite('@'));
#endif
	}

#ifdef EXTRA
	emi_trial("drop & take while");
	{
		char *original = "hello, world";
		char *w1 = ft_str_drop_while(original, ft_isalpha);

		emi_assert(strcmp(w1, ", world") == 0);
		emi_assert_i(w1 != ft_strchr(original, ','), "actually makes a copy");

		char *w2 = ft_str_take_while(original, ft_isalpha);

		emi_assert(strcmp(w2, "hello") == 0);
		emi_assert_i(w2 != original, "actually makes a copy");
	}
#endif

	emi_trial("atoi");
	{
		emi_assert_i(ft_atoi("100") == 100, "100");
		emi_assert_i(ft_atoi("-100") == -100, "-100");
		emi_assert_i(ft_atoi("0") == 0, "0");
		emi_assert_i(ft_atoi("123abc123") == 123, "123");
		emi_assert_i(ft_atoi("           \t+69") == 69, "whitespace for +69");
		emi_assert_i(ft_atoi("\n\n1\t2") == 1, "weird whitespace around 1");
		emi_assert_i(ft_atoi("+2147483647") == 2147483647, "int_max");
		emi_assert_i(ft_atoi("-2147483648") == -2147483648, "int_min");
		emi_assert_i(ft_atoi("-2147483648") == atoi("-2147483648"),
				"comparison to atoi with edge cases");
		emi_assert_i(ft_atoi("+2147483647") == atoi("+2147483647"),
				"comparison to atoi with edge cases");
		emi_assert_i(ft_atoi("-21474836481") == atoi("-21474836481"),
				"comparison to atoi with edge cases");
		emi_assert_i(ft_atoi("               \t+69") ==
				atoi("               \t+69"),
				"comparison to atoi with edge cases");
	}

	emi_trial("manual tests");
	{
		printf(" ==> the following are manual tests, ");
		printf("please ensure they are checked correctly ");
		printf("before handing it in\n");
		printf("---- START ----\n");

		ft_putstr("test the world\n");
		ft_putchar('x');
		ft_putchar('\n');
		ft_putendl("we are alive");
		ft_putnbr(INT_MIN);
		ft_putchar('\n');
		ft_putnbr(INT_MAX);
		ft_putchar('\n');
		ft_putnbr(-123);
		ft_putchar('\n');
		ft_putnbr(123);
		ft_putchar('\n');
		ft_putnbr(0);
		ft_putchar('\n');

		int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
		printf("debug fd: <%d>\n", fd);
		ft_putstr_fd("test the world\n", fd);
		ft_putchar_fd('x', fd);
		ft_putchar_fd('\n', fd);
		ft_putendl_fd("we are alive", fd);

		printf("---- END  ----\n");
		printf(" ==> also ensure that the files have been modified:");
		printf("'test.txt'\n");
		printf(" ==> contents should match the printed text above");
	}

	emi_trial("ft_memalloc & ft_memdel & ft_strnew");
	{
		int *ns = ft_memalloc(sizeof(int));
		*ns = 10;
		emi_assert_i(ns != 0, "test base");
		ft_memdel((void**)&ns);
		emi_assert(ns == NULL);
		ns = ft_memalloc(sizeof(int) * 1000000000000000000);
		emi_assert_i(ns == 0, "too much mem");

		ft_memdel((void**)&ns);
		emi_assert(ns == NULL);

		char *mystr = "hello";
		char *copy = ft_strnew(10);
		ft_strcpy(copy, mystr);
		emi_assert(copy != mystr);
		emi_assert(strcmp(copy, mystr) == 0);
		emi_assert(memcmp(copy, mystr, 10) != 0);
	}

	emi_trial("ft_strclr");
	{
		char mystr[10] = "hi, world";
		char *mystr2 = ft_strnew(10);
		ft_strclr(mystr);
		emi_assert(memcmp(mystr, mystr2, 10) == 0);
	}

	emi_trial("ft_striter & ft_striteri");
	{
		void ft_make_upper(char *c);
		void ft_sponge(unsigned int i, char *c);

		char str[] = "hello, world";

		ft_striter(str, ft_make_upper);
		emi_assert(strcmp(str, "HELLO, WORLD") == 0);

		ft_striteri(str, ft_sponge);
		emi_assert(strcmp(str, "HeLlO, wOrLd") == 0);
	}

#ifdef EXTRA
	emi_trial("ft_strtoup & ft_strtolo");
	{
		char str[] = "mixed Case is Me";

		emi_assert(strcmp(ft_strtolo(str), "mixed case is me") == 0);
		emi_assert(strcmp(ft_strtoup(str), "MIXED CASE IS ME") == 0);
	}
#endif

	emi_trial("ft_strequ & ft_strnequ");
	{
		char s1[] = "hello, world";
		char s2[] = "hello, universe";

		emi_assert(!ft_strequ(s1, s2));
		emi_assert(ft_strequ(s1, ft_strdup(s1)));
		emi_assert(ft_strnequ(s1, s2, 6));
		emi_assert(!ft_strnequ(s1, s2, 8));
	}

	emi_trial("ft_strmap & ft_strmapi");
	{
		char ft_sponge_c(unsigned int i, char c);
		char ft_toupper_c(char);
		char ft_tolower_c(char);
		char s1[] = "Hello, World";

		emi_assert(strcmp(ft_strmap(s1, ft_toupper_c), "HELLO, WORLD") == 0);
		emi_assert(strcmp(ft_strmap(s1, ft_tolower_c), "hello, world") == 0);
		emi_assert(strcmp(ft_strmapi(s1, ft_sponge_c), "HeLlO, wOrLd") == 0);
	}

	emi_trial("ft_strtrim");
	{
		char s1[] = "    hello far world     ";
		char s2[] = "hello far world     ";
		char s3[] = "   \t\nhello far world";
		char s4[] = "";
		char s5[] = "       ";
		char s6[] = "   am i even valid\0 at all?";

		emi_assert(strcmp(ft_strtrim(s1), "hello far world") == 0);
		emi_assert(strcmp(ft_strtrim(s2), "hello far world") == 0);
		emi_assert(strcmp(ft_strtrim(s3), "hello far world") == 0);
		emi_assert(strcmp(ft_strtrim(s4), "") == 0);
		emi_assert(strcmp(ft_strtrim(s5), "") == 0);
		emi_assert(strcmp(ft_strtrim(s6), "am i even valid") == 0);
	}

#ifdef EXTRA
	emi_trial("ft_strchrcount");
	{
		char s1[] = "mississippi";
		emi_assert(ft_strchrcount(s1, 's') == 4);
		emi_assert(ft_strchrcount(s1, 'i') == 4);
		emi_assert(ft_strchrcount(s1, 'p') == 2);
		emi_assert(ft_strchrcount(s1, 'a') == 0);
	}
#endif

	emi_trial("ft_strsplit");
	{
		{
			char str[] = "hello, world, hi";

			char **words = ft_strsplit(str, ' ');
			char *exp_words[] = { "hello,", "world,", "hi" };
			for (size_t i = 0; i <3; i++)
				emi_assert(strcmp(words[i], exp_words[i]) == 0);
		}
		{
			char str[] = "hello*fellow***students";

			char **words = ft_strsplit(str, '*');
			char *exp_words[] = { "hello", "fellow", "students", 0 };
			for (size_t i = 0; words[i]; i++)
				emi_assert(strcmp(words[i], exp_words[i]) == 0);
		}
		{
			char str[] = "AAAAAA";

			char **words = ft_strsplit(str, 'A');
			emi_assert(words[0] == 0);
		}
	}

	emi_trial("ft_strsub");
	{
		char str[] = "baba is you";

		emi_assert(memcmp(ft_strsub(str, 5, 2), "is", 3) == 0);
		emi_assert(memcmp(ft_strsub(str, 0, 4), "baba", 5) == 0);
		emi_assert(memcmp(ft_strsub(str, 8, 3), "you", 4) == 0);
		emi_assert_i(ft_strsub(str, 0, 3) != str, "is fresh");
	}

	emi_trial("ft_strjoin");
	{
		emi_assert(strcmp(ft_strjoin("hello, ", "world!"),
								"hello, world!") == 0);
		emi_assert(strcmp(ft_strjoin("", "world!"),
								"world!") == 0);
		emi_assert(strcmp(ft_strjoin("hello!", ""),
								"hello!") == 0);
		emi_assert(strcmp(ft_strjoin("", ""),
								"") == 0);
	}

#ifdef EXTRA
	emi_trial("ft_strrev");
	{
		char s1[] = "hello, world";
		char *s2 = ft_strdup(s1);
		ft_strrev(s2);

		emi_assert(strcmp(s2, "dlrow ,olleh") == 0);
		ft_strrev(s2);
		emi_assert(strcmp(s2, s1) == 0);

		char s3[] = "";
		ft_strrev(s3);
		emi_assert(strcmp(s3, "") == 0);
	}

	emi_trial("ft_itoa");
	{
		emi_assert(INT_MIN == ft_atoi(ft_itoa(INT_MIN)));
		emi_assert(INT_MAX == ft_atoi(ft_itoa(INT_MAX)));
		emi_assert(100 == ft_atoi(ft_itoa(100)));
		emi_assert(-100 == ft_atoi(ft_itoa(-100)));
		emi_assert(0 == ft_atoi(ft_itoa(0)));
		emi_assert(strcmp(ft_itoa(-623), "-623") == 0);
		emi_assert(strcmp(ft_itoa(0), "0") == 0);
		emi_assert(strcmp(ft_itoa(156), "156") == 0);
	}

	emi_trial("ft_print_memory");
	{
		char str[] = "hello, world, how are you doing today? hello my name is jeff uh yeah";
		ft_print_memory(str, sizeof(str));
	}
#endif

#define LISTS
#ifdef LISTS
	emi_trial("ft_lstnew");
	{
		t_list *lst;

		lst = ft_lstnew("hello", 6);
		emi_assert(strcmp(lst->content, "hello") == 0);
		emi_assert(6 == lst->content_size);
	}

	emi_trial("ft_lstadd");
	{
		t_list *lst;

		lst = ft_lstnew("hello", 6);
		ft_lstadd(&lst, ft_lstnew("hello", 6));
		emi_assert(memcmp(lst->next->content, "hello", 6) == 0);
		emi_assert((size_t)lst);
		emi_assert((size_t)lst->next);
		emi_assert(!(size_t)lst->next->next);
	}

	emi_trial("ft_lstdelone");
	{
		void del_list(void *k, size_t l);
		t_list *lst;

		lst = ft_lstnew("hello", 6);
		ft_lstadd(&lst, ft_lstnew("hi", 3));
		ft_lstadd(&lst, ft_lstnew("hewwo", 6));

		t_list *next;
		next = lst->next;
		ft_lstdelone(&lst, del_list);
		emi_assert(!(size_t)lst);
		emi_assert((size_t)next);
		emi_assert((size_t)next->next);
		
	}

	emi_trial("ft_lstdel");
	{
		void del_list(void *k, size_t l);
		t_list *lst;

		lst = ft_lstnew("hello", 6);
		ft_lstadd(&lst, ft_lstnew("hello", 6));
		ft_lstdel(&lst, del_list);
		emi_assert(!lst);
	}

#endif
	emi_debrief();
	return (0);
}

void del_list(void *k, size_t l)
{
	(void)l;
	free(k);
}
