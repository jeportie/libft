/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:19:59 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:20:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <limits.h>
#include "../../include/libft.h"

START_TEST(test_digits) {
    for (int c = '0'; c <= '9'; c++) {
        ck_assert_int_eq(ft_isdigit(c), 1);
    }
}
END_TEST

START_TEST(test_non_digits) {
    ck_assert_int_eq(ft_isdigit('a'), 0);
    ck_assert_int_eq(ft_isdigit('Z'), 0);
    ck_assert_int_eq(ft_isdigit(' '), 0);
    ck_assert_int_eq(ft_isdigit('@'), 0);
}
END_TEST

START_TEST(test_boundary_values) {
    ck_assert_int_eq(ft_isdigit('0' - 1), 0);
    ck_assert_int_eq(ft_isdigit('9' + 1), 0);
}
END_TEST

START_TEST(test_extreme_values) {
    ck_assert_int_eq(ft_isdigit(INT_MIN), 0);
    ck_assert_int_eq(ft_isdigit(INT_MAX), 0);
}
END_TEST

Suite *ft_isdigit_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_isdigit");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_digits);
    tcase_add_test(tc_core, test_non_digits);
    tcase_add_test(tc_core, test_boundary_values);
    tcase_add_test(tc_core, test_extreme_values);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    // Similar to the main function in the previous test
}

