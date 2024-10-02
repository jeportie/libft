/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 08:19:19 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 08:20:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "../../include/libft.h"

START_TEST(test_ft_isalpha_lowercase)
{
    ck_assert_int_eq(ft_isalpha('a'), 1);
    ck_assert_int_eq(ft_isalpha('z'), 1);
}
END_TEST

START_TEST(test_ft_isalpha_uppercase)
{
    ck_assert_int_eq(ft_isalpha('A'), 1);
    ck_assert_int_eq(ft_isalpha('Z'), 1);
}
END_TEST

START_TEST(test_ft_isalpha_non_alpha)
{
    ck_assert_int_eq(ft_isalpha('0'), 0);
    ck_assert_int_eq(ft_isalpha('9'), 0);
    ck_assert_int_eq(ft_isalpha('@'), 0);
    ck_assert_int_eq(ft_isalpha('['), 0);
    ck_assert_int_eq(ft_isalpha('`'), 0);
    ck_assert_int_eq(ft_isalpha('{'), 0);
}
END_TEST

START_TEST(test_ft_isalpha_edge_cases)
{
    ck_assert_int_eq(ft_isalpha('a' - 1), 0); // char before 'a'
    ck_assert_int_eq(ft_isalpha('z' + 1), 0); // char after 'z'
    ck_assert_int_eq(ft_isalpha('A' - 1), 0); // char before 'A'
    ck_assert_int_eq(ft_isalpha('Z' + 1), 0); // char after 'Z'
}
END_TEST

Suite *ft_isalpha_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_isalpha");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_ft_isalpha_lowercase);
    tcase_add_test(tc_core, test_ft_isalpha_uppercase);
    tcase_add_test(tc_core, test_ft_isalpha_non_alpha);
    tcase_add_test(tc_core, test_ft_isalpha_edge_cases);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = ft_isalpha_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}

