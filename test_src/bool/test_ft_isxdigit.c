/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isxdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:21:37 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/10 20:21:54 by jeportie         ###   ########.fr       */
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
    // Similar structure as previous suites
}

int main(void) {
    // Similar to the main function in the previous tests
}

