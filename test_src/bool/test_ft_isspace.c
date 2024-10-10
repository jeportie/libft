/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:20:53 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:21:04 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <limits.h>
#include "../../include/libft.h"

START_TEST(test_whitespace_chars) {
    ck_assert_int_eq(ft_isspace(' '), 1);
    ck_assert_int_eq(ft_isspace('\f'), 1);
    ck_assert_int_eq(ft_isspace('\n'), 1);
    ck_assert_int_eq(ft_isspace('\r'), 1);
    ck_assert_int_eq(ft_isspace('\t'), 1);
    ck_assert_int_eq(ft_isspace('\v'), 1);
}
END_TEST

START_TEST(test_non_whitespace_chars) {
    ck_assert_int_eq(ft_isspace('A'), 0);
    ck_assert_int_eq(ft_isspace('0'), 0);
    ck_assert_int_eq(ft_isspace('@'), 0);
}
END_TEST

START_TEST(test_boundary_values) {
    ck_assert_int_eq(ft_isspace(8), 0);   // Before '\t' (ASCII 9)
    ck_assert_int_eq(ft_isspace(14), 0);  // After '\v' (ASCII 11)
}
END_TEST

START_TEST(test_extreme_values) {
    ck_assert_int_eq(ft_isspace(-1), 0);
    ck_assert_int_eq(ft_isspace(128), 0);
    ck_assert_int_eq(ft_isspace(INT_MIN), 0);
    ck_assert_int_eq(ft_isspace(INT_MAX), 0);
}
END_TEST

Suite *ft_isspace_suite(void) {
    // Similar structure as previous suites
}

int main(void) {
    // Similar to the main function in the previous tests
}

