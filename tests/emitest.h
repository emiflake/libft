/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   emitest.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 13:25:19 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/18 16:51:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void emi_assert_mac(int, char*);

#define STRINGIZE_NX(S) #S
#define emi_test1(fn, i0, o) 			 	{ char s[] = STRINGIZE_NX(fn ## _tested_with_ ## i0 ## _should_be_ ## o);            			 		   emi_assert_mac(fn(i0) == o, s); }
#define emi_test2(fn, i0, i1, o) 		 	{ char s[] = STRINGIZE_NX(fn ## _tested_with_ ## i0 ## _ ## i1 ## _should_be_ ## o); 			 		   emi_assert_mac(fn(i0, i1) == o, s); }
#define emi_test3(fn, i0, i1, i2, o) 	 	{ char s[] = STRINGIZE_NX(fn ## _tested_with_ ## i0 ## _ ## i1 ## _ ## i2 ## _should_be_ ## o); 		   emi_assert_mac(fn(i0, i1, i2) == o, s); }
#define emi_test4(fn, i0, i1, i2, i3, o) 	{ char s[] = STRINGIZE_NX(fn ## _tested_with_ ## i0 ## _ ## i1 ## _ ## i2 ## _ ## i3 ## _should_be_ ## o); emi_assert_mac(fn(i0, i1, i2, i3) == o, s); }

void emi_exe(char *);
void emi_init(char *);
void emi_trial(char *);
void emi_debrief();
void emi_test(int(*f)(char *, char *), char *s1, char *s2, int exp);
void emi_assert_i(int, char*);
void emi_assert(int);
void emi_norm(char *);
