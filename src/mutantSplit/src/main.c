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

int	main(void)
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
	char	*s2 = "123;456";
	char	*s3 = "123;456;789";
	char	*s4 = "123;456;";
	char	*s5 = ";123;456;789";
	char	*s6 = ";123;456;";
	char	*s7 = ";123;456;789;";

	printf("input: |%s|\n", s1);
	printf("correct len = %d\n", 1);
	res = mutant_split(s1, c);
	printf("\n");

	printf("input: |%s|\n", s2);
	printf("correct len = %d\n", 2);
	res = mutant_split(s2, c);
	printf("\n");

	printf("input: |%s|\n", s3);
	printf("correct len = %d\n", 3);
	res = mutant_split(s3, c);
	printf("\n");

	printf("input: |%s|\n", s4);
	printf("correct len = %d\n", 2);
	res = mutant_split(s4, c);
	printf("\n");

	printf("input: |%s|\n", s5);
	printf("correct len = %d\n", 3);
	res = mutant_split(s5, c);
	printf("\n");

	printf("input: |%s|\n", s6);
	printf("correct len = %d\n", 2);
	res = mutant_split(s6, c);
	printf("\n");

	printf("input: |%s|\n", s7);
	printf("correct len = %d\n", 3);
	res = mutant_split(s7, c);
	printf("\n");

	printf("~~~~~~~~~~~~~\n\n");

	//Hard
	printf("~~~ hard ~~~~\n");
	char	*s8 = ";;;;;123;;;;";
	char	*s9 = "123;;;;;;456";
	char	*s10 = "123;;;;;456;;;;;789";
	char	*s11 = "123;;;;;456;;;;";
	char	*s12 = ";;;;123;;;;456;;;;789";
	char	*s13 = ";;;;123;;;;;456;;;";
	char	*s14 = ";;;;123;;;;456;789;;;;";

	printf("input: |%s|\n", s8);
	printf("correct len = %d\n", 1);
	res = mutant_split(s8, c);
	printf("\n");

	printf("input: |%s|\n", s9);
	printf("correct len = %d\n", 2);
	res = mutant_split(s9, c);
	printf("\n");

	printf("input: |%s|\n", s10);
	printf("correct len = %d\n", 3);
	res = mutant_split(s10, c);
	printf("\n");

	printf("input: |%s|\n", s11);
	printf("correct len = %d\n", 2);
	res = mutant_split(s11, c);
	printf("\n");

	printf("input: |%s|\n", s12);
	printf("correct len = %d\n", 3);
	res = mutant_split(s12, c);
	printf("\n");

	printf("input: |%s|\n", s13);
	printf("correct len = %d\n", 2);
	res = mutant_split(s13, c);
	printf("\n");

	printf("input: |%s|\n", s14);
	printf("correct len = %d\n", 3);
	res = mutant_split(s14, c);
	printf("\n");

	printf("~~~~~~~~~~~~~\n\n");

	//BasicWithProtecting
	printf("~~~ Basic With Protecting ~~~\n");
	s1 = "123\\;456"; //1
	s2 = "12'3;4'56"; //1
	s3 = "\"123;456\";789"; //2
	s4 = "123\\\\;456;"; //2
	s5 = ";123\"\";456\'\';789"; //3
	s6 = "\";123;456;\""; //1
	s7 = ";123;45\\\"6;789;"; //3;

	printf("input: |%s|\n", s1);
	printf("correct len = %d\n", 1);
	res = mutant_split(s1, c);
	printf("\n");

	printf("input: |%s|\n", s2);
	printf("correct len = %d\n", 1);
	res = mutant_split(s2, c);
	printf("\n");

	printf("input: |%s|\n", s3);
	printf("correct len = %d\n", 2);
	res = mutant_split(s3, c);
	printf("\n");

	printf("input: |%s|\n", s4);
	printf("correct len = %d\n", 2);
	res = mutant_split(s4, c);
	printf("\n");

	printf("input: |%s|\n", s5);
	printf("correct len = %d\n", 3);
	res = mutant_split(s5, c);
	printf("\n");

	printf("input: |%s|\n", s6);
	printf("correct len = %d\n", 1);
	res = mutant_split(s6, c);
	printf("\n");

	printf("input: |%s|\n", s7);
	printf("correct len = %d\n", 3);
	res = mutant_split(s7, c);
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
	printf("\n");

	printf("input: |%s|\n", s9);
	printf("correct len = %d\n", 2);
	res = mutant_split(s9, c);
	printf("\n");

	printf("input: |%s|\n", s10);
	printf("correct len = %d\n", 3);
	res = mutant_split(s10, c);
	printf("\n");

	printf("input: |%s|\n", s11);
	printf("correct len = %d\n", 2);
	res = mutant_split(s11, c);
	printf("\n");

	printf("input: |%s|\n", s12);
	printf("correct len = %d\n", 3);
	res = mutant_split(s12, c);
	printf("\n");

	printf("input: |%s|\n", s13);
	printf("correct len = %d\n", 4);
	res = mutant_split(s13, c);
	printf("\n");

	printf("input: |%s|\n", s14);
	printf("correct len = %d\n", 3);
	res = mutant_split(s14, c);
	printf("\n");


	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	//mutant_split(argv[1], ';');
	return (0);
}

