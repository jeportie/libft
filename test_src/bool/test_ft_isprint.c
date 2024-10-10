/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:20:25 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:25:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <limits.h>
#include "../../include/libft.h"

START_TEST(test_printable_chars) {
    for (int c = 32; c <= 126; c++) {
        ck_assert_int_eq(ft_isprint(c), 1);
    }
}
END_TEST

START_TEST(test_non_printable_chars) {
    for (int c = 0; c < 32; c++) {
        ck_assert_int_eq(ft_isprint(c), 0);
    }
    ck_assert_int_eq(ft_isprint(127), 0);
}
END_TEST

START_TEST(test_boundary_values) {
    ck_assert_int_eq(ft_isprint(31), 0);
    ck_assert_int_eq(ft_isprint(32), 1);
    ck_assert_int_eq(ft_isprint(126), 1);
    ck_assert_int_eq(ft_isprint(127), 0);
}
END_TEST

START_TEST(test_extreme_values) {
    ck_assert_int_eq(ft_isprint(-1), 0);
    ck_assert_int_eq(ft_isprint(128), 0);
    ck_assert_int_eq(ft_isprint(INT_MIN), 0);
    ck_assert_int_eq(ft_isprint(INT_MAX), 0);
}
END_TEST

Suite *ft_isprint_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_isprint");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_printable_chars);
    tcase_add_test(tc_core, test_non_printable_chars);
    tcase_add_test(tc_core, test_boundary_values);
    tcase_add_test(tc_core, test_extreme_values);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = ft_isprint_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}

