/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:19:31 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:19:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <limits.h>
#include "../../include/libft.h" // Your header file where ft_isascii is declared

START_TEST(test_regular_ascii_values) {
    ck_assert_int_eq(ft_isascii('A'), 1);
    ck_assert_int_eq(ft_isascii('z'), 1);
    ck_assert_int_eq(ft_isascii('0'), 1);
    ck_assert_int_eq(ft_isascii(' '), 1);
}
END_TEST

START_TEST(test_non_ascii_values) {
    ck_assert_int_eq(ft_isascii(128), 0);
    ck_assert_int_eq(ft_isascii(255), 0);
    ck_assert_int_eq(ft_isascii(-1), 0);
}
END_TEST

START_TEST(test_boundary_values) {
    ck_assert_int_eq(ft_isascii(0), 1);    // Lower boundary of ASCII
    ck_assert_int_eq(ft_isascii(127), 1);  // Upper boundary of ASCII
    ck_assert_int_eq(ft_isascii(-128), 0);
    ck_assert_int_eq(ft_isascii(128), 0);
}
END_TEST

START_TEST(test_extreme_values) {
    ck_assert_int_eq(ft_isascii(INT_MIN), 0);
    ck_assert_int_eq(ft_isascii(INT_MAX), 0);
}
END_TEST

Suite *ft_isascii_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_isascii");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_regular_ascii_values);
    tcase_add_test(tc_core, test_non_ascii_values);
    tcase_add_test(tc_core, test_boundary_values);
    tcase_add_test(tc_core, test_extreme_values);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = ft_isascii_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}

