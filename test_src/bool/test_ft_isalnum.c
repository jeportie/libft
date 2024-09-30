/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:09:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/30 12:10:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "../../include/libft.h"

START_TEST(test_isalnum_alpha_lowercase)
{
    ck_assert_int_eq(ft_isalnum('a'), 1);
}
END_TEST

START_TEST(test_isalnum_alpha_uppercase)
{
    ck_assert_int_eq(ft_isalnum('Z'), 1);
}
END_TEST

START_TEST(test_isalnum_digit)
{
    ck_assert_int_eq(ft_isalnum('5'), 1);
}
END_TEST

START_TEST(test_isalnum_non_alnum)
{
    ck_assert_int_eq(ft_isalnum('@'), 0);
}
END_TEST

START_TEST(test_isalnum_space)
{
    ck_assert_int_eq(ft_isalnum(' '), 0);
}
END_TEST

START_TEST(test_isalnum_null_char)
{
    ck_assert_int_eq(ft_isalnum('\0'), 0);
}
END_TEST

START_TEST(test_isalnum_boundary_before_digit)
{
    ck_assert_int_eq(ft_isalnum('/'), 0);
}
END_TEST

START_TEST(test_isalnum_boundary_after_digit)
{
    ck_assert_int_eq(ft_isalnum(':'), 0);
}
END_TEST

START_TEST(test_isalnum_boundary_before_alpha_upper)
{
    ck_assert_int_eq(ft_isalnum('@'), 0);
}
END_TEST

START_TEST(test_isalnum_boundary_after_alpha_upper)
{
    ck_assert_int_eq(ft_isalnum('['), 0);
}
END_TEST

Suite *isalnum_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("isalnum");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_isalnum_alpha_lowercase);
    tcase_add_test(tc_core, test_isalnum_alpha_uppercase);
    tcase_add_test(tc_core, test_isalnum_digit);
    tcase_add_test(tc_core, test_isalnum_non_alnum);
    tcase_add_test(tc_core, test_isalnum_space);
    tcase_add_test(tc_core, test_isalnum_null_char);
    tcase_add_test(tc_core, test_isalnum_boundary_before_digit);
    tcase_add_test(tc_core, test_isalnum_boundary_after_digit);
    tcase_add_test(tc_core, test_isalnum_boundary_before_alpha_upper);
    tcase_add_test(tc_core, test_isalnum_boundary_after_alpha_upper);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = isalnum_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    if (number_failed == 0)
    {
        printf("\033[0;32mAll tests passed!\033[0m\n");
    }
    else
    {
        printf("\033[0;31mSome tests failed!\033[0m\n");
    }

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

