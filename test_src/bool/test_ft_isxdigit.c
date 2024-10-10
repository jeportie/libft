/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isxdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:21:37 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:26:12 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <limits.h>
#include "../../include/libft.h"

START_TEST(test_hex_digits_uppercase) {
    for (int c = 'A'; c <= 'F'; c++) {
        ck_assert_int_eq(ft_isxdigit(c), 1);
    }
}
END_TEST

START_TEST(test_hex_digits_lowercase) {
    for (int c = 'a'; c <= 'f'; c++) {
        ck_assert_int_eq(ft_isxdigit(c), 1);
    }
}
END_TEST

START_TEST(test_decimal_digits) {
    for (int c = '0'; c <= '9'; c++) {
        ck_assert_int_eq(ft_isxdigit(c), 1);
    }
}
END_TEST

START_TEST(test_non_hex_chars) {
    ck_assert_int_eq(ft_isxdigit('G'), 0);
    ck_assert_int_eq(ft_isxdigit('z'), 0);
    ck_assert_int_eq(ft_isxdigit(' '), 0);
    ck_assert_int_eq(ft_isxdigit('@'), 0);
}
END_TEST

START_TEST(test_boundary_values) {
    ck_assert_int_eq(ft_isxdigit('0' - 1), 0);
    ck_assert_int_eq(ft_isxdigit('9' + 1), 0);
    ck_assert_int_eq(ft_isxdigit('A' - 1), 0);
    ck_assert_int_eq(ft_isxdigit('F' + 1), 0);
    ck_assert_int_eq(ft_isxdigit('a' - 1), 0);
    ck_assert_int_eq(ft_isxdigit('f' + 1), 0);
}
END_TEST

START_TEST(test_extreme_values) {
    ck_assert_int_eq(ft_isxdigit(-1), 0);
    ck_assert_int_eq(ft_isxdigit(128), 0);
    ck_assert_int_eq(ft_isxdigit(INT_MIN), 0);
    ck_assert_int_eq(ft_isxdigit(INT_MAX), 0);
}
END_TEST

Suite *ft_isxdigit_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_isxdigit");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_hex_digits_uppercase);
    tcase_add_test(tc_core, test_hex_digits_lowercase);
    tcase_add_test(tc_core, test_decimal_digits);
    tcase_add_test(tc_core, test_non_hex_chars);
    tcase_add_test(tc_core, test_boundary_values);
    tcase_add_test(tc_core, test_extreme_values);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = ft_isxdigit_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}

