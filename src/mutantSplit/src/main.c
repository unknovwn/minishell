/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:24:21 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/29 15:07:25 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "mutant_split.h"

static void	print_arr_len(char **strings)
{
	size_t	len = 0;
	while (*strings != NULL)
	{
		len += 1;
		strings += 1;
	}
	printf("user len    = %zu\n", len);
}

int			main(void)
{
	/*
	** Tests
	*/

	int		fd = open("user_output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IREAD | S_IWRITE);

	char	**res;
	char	c;

	//Basic
	printf("~~~ basic ~~~\n");
	c = ';';
	char	*s1 = "123";
	char	*s2 = "123;4567";
	char	*s3 = "123;4567;789123";
	char	*s4 = "12;4567;";
	char	*s5 = ";1;456;789123456";
	char	*s6 = ";1234567;4;";
	char	*s7 = ";1234567;456789;7891;";

	printf("input: |%s|\n", s1);
	printf("correct len = %d\n", 1);
	res = mutant_split(s1, c);
	//print_arr_len(res);
	printf("WORDS   len = %d\n", 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s2);
	printf("correct len = %d\n", 2);
	res = mutant_split(s2, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 3, 4);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s3);
	printf("correct len = %d\n", 3);
	res = mutant_split(s3, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 3, 4, 6);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s4);
	printf("correct len = %d\n", 2);
	res = mutant_split(s4, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 2, 4);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s5);
	printf("correct len = %d\n", 3);
	res = mutant_split(s5, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 1, 3, 9);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s6);
	printf("correct len = %d\n", 2);
	res = mutant_split(s6, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 7, 1);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s7);
	printf("correct len = %d\n", 3);
	res = mutant_split(s7, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 7, 6, 4);
	free(res);
	printf("\n");

	printf("~~~~~~~~~~~~~\n\n");

	//Hard
	printf("~~~ hard ~~~~\n");
	char	*s8 = ";;;;;123;;;;";
	char	*s9 = "12;;;;;;456";
	char	*s10 = "1;;;;;46;;;;;789";
	char	*s11 = "123;;;;;456789;;;;";
	char	*s12 = ";;;;12345;;;;45;;;;7";
	char	*s13 = ";;;;12345;;;;;456789;;;";
	char	*s14 = ";;;;1234;;;;456789;7891234567;;;;";

	printf("input: |%s|\n", s8);
	printf("correct len = %d\n", 1);
	res = mutant_split(s8, c);
	//print_arr_len(res);
	printf("WORDS   len = %d\n", 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s9);
	printf("correct len = %d\n", 2);
	res = mutant_split(s9, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 2, 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s10);
	printf("correct len = %d\n", 3);
	res = mutant_split(s10, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 1, 2, 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s11);
	printf("correct len = %d\n", 2);
	res = mutant_split(s11, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 3, 6);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s12);
	printf("correct len = %d\n", 3);
	res = mutant_split(s12, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d,  %d\n", 5, 2, 1);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s13);
	printf("correct len = %d\n", 2);
	res = mutant_split(s13, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 5, 6);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s14);
	printf("correct len = %d\n", 3);
	res = mutant_split(s14, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 4, 6, 10);
	free(res);
	printf("\n");

	printf("~~~~~~~~~~~~~\n\n");

	//BasicWithProtecting
	printf("~~~ Basic With Protecting ~~~\n");
	s1 = "1\\;46"; //1
	s2 = "12'3;4'56"; //1
	s3 = "\"123;456\";789"; //2
	s4 = "123\\\\;456;"; //2
	s5 = ";123\"\";456\'\';789"; //3
	s6 = "\";123;456;\""; //1
	s7 = ";123;45\\\"6;789;"; //3;

	printf("input: |%s|\n", s1);
	printf("correct len = %d\n", 1);
	res = mutant_split(s1, c);
	//print_arr_len(res);
	free(res);
	printf("WORDS   len = %d\n", 4);
	printf("\n");

	printf("input: |%s|\n", s2);
	printf("correct len = %d\n", 1);
	res = mutant_split(s2, c);
	//print_arr_len(res);
	printf("WORDS   len = %d\n", 7);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s3);
	printf("correct len = %d\n", 2);
	res = mutant_split(s3, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 7, 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s4);
	printf("correct len = %d\n", 2);
	res = mutant_split(s4, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 4, 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s5);
	printf("correct len = %d\n", 3);
	res = mutant_split(s5, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 3, 3, 3);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s6);
	printf("correct len = %d\n", 1);
	res = mutant_split(s6, c);
	//print_arr_len(res);
	printf("WORDS   len = %d,\n", 9);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s7);
	printf("correct len = %d\n", 3);
	res = mutant_split(s7, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 3, 4, 3);
	free(res);
	printf("\n");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

	printf("~~~ Hard With Protecting ~~~~\n");

	s8 = "\'123\\;\\;456\'\\;\';\'789";
	s9 = "\"123;;\";456\\;\\;\'789;\'321";
	s10 = "123\\\';\';;;;\'456\\;\";;;\";78\\;9";
	s11 = "\\\"123;\"456\"\\;;";
	s12 = "\\\"123;\\\'456;789\\;321\';\'654";
	s13 = "\\;123\\;\';;;;\'\\;;456\'\';\"\";\";\"789";
	s14 = "\\'123;\'456;\';768\\;1";

	printf("input: |%s|\n", s8);
	printf("correct len = %d\n", 1);
	res = mutant_split(s8, c);
	//print_arr_len(res);
	printf("WORDS   len = %d\n", 15);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s9);
	printf("correct len = %d\n", 2);
	res = mutant_split(s9, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 5, 12);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s10);
	printf("correct len = %d\n", 3);
	res = mutant_split(s10, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 4, 11, 4);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s11);
	printf("correct len = %d\n", 2);
	res = mutant_split(s11, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d\n", 4, 4);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s12);
	printf("correct len = %d\n", 3);
	res = mutant_split(s12, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 4, 4, 11);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s13);
	printf("correct len = %d\n", 4);
	res = mutant_split(s13, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d, %d\n", 10, 3, 0, 4);
	free(res);
	printf("\n");

	printf("input: |%s|\n", s14);
	printf("correct len = %d\n", 3);
	res = mutant_split(s14, c);
	//print_arr_len(res);
	printf("WORDS   len = %d, %d, %d\n", 4, 4, 5);
	free(res);
	printf("\n");


	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	//mutant_split(argv[1], ';');
	return (0);
}

