/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 07:08:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/10/02 07:23:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "../../include/libft.h"

// Include the header file where ft_memset is declared
void *ft_memset(void *s, int c, size_t n);

// Test for normal behavior
START_TEST(test_normal_behavior)
{
    char buffer[10];
    ft_memset(buffer, 'A', sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); i++) {
        ck_assert_int_eq(buffer[i], 'A');
    }
}
END_TEST

// Test for zero length
START_TEST(test_zero_length)
{
    char buffer[10] = {0};
    ft_memset(buffer, 'A', 0);
    for (size_t i = 0; i < sizeof(buffer); i++) {
        ck_assert_int_eq(buffer[i], 0);
    }
}
END_TEST

// Test for setting a single byte
START_TEST(test_single_byte)
{
    char buffer[10] = {0};
    ft_memset(buffer, 'A', 1);
    ck_assert_int_eq(buffer[0], 'A');
    for (size_t i = 1; i < sizeof(buffer); i++) {
        ck_assert_int_eq(buffer[i], 0);
    }
}
END_TEST

// Test for setting the entire buffer
START_TEST(test_entire_buffer)
{
    char buffer[10];
    ft_memset(buffer, 'A', sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); i++) {
        ck_assert_int_eq(buffer[i], 'A');
    }
}
END_TEST

// Test for large size
START_TEST(test_large_size)
{
    char *buffer = malloc(1000000);
    ck_assert_ptr_nonnull(buffer);
    ft_memset(buffer, 'A', 1000000);
    for (size_t i = 0; i < 1000000; i++) {
        ck_assert_int_eq(buffer[i], 'A');
    }
    free(buffer);
}
END_TEST

Suite *memset_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("ft_memset");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_normal_behavior);
    tcase_add_test(tc_core, test_zero_length);
    tcase_add_test(tc_core, test_single_byte);
    tcase_add_test(tc_core, test_entire_buffer);
    tcase_add_test(tc_core, test_large_size);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = memset_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

