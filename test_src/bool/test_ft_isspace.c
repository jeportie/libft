/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:20:53 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:25:54 by jeportie         ###   ########.fr       */
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
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_isspace");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_whitespace_chars);
    tcase_add_test(tc_core, test_non_whitespace_chars);
    tcase_add_test(tc_core, test_boundary_values);
    tcase_add_test(tc_core, test_extreme_values);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = ft_isspace_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}

