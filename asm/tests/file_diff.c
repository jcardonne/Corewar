/*
** EPITECH PROJECT, 2021
** test_add_sub.c
** File description:
** test_add_sub
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include <stdio.h>
#include <stdio.h>


Test(utils, tyron)
{
    FILE *source = fopen("tyron.cor", "r");
    FILE *compare = fopen("assets/tyron.cor", "r");
    int value = cr_file_match_file(source, compare);

    cr_assert(eq(int, value, 1));
    fclose(source);
    fclose(compare);
}

Test(utils, pdd)
{
    FILE *source = fopen("pdd.cor", "r");
    FILE *compare = fopen("assets/pdd.cor", "r");
    int value = cr_file_match_file(source, compare);

    cr_assert(eq(int, value, 1));
    fclose(source);
    fclose(compare);
}

Test(utils, bill)
{
    FILE *source = fopen("bill.cor", "r");
    FILE *compare = fopen("assets/bill.cor", "r");
    int value = cr_file_match_file(source, compare);

    cr_assert(eq(int, value, 1));
    fclose(source);
    fclose(compare);
}

Test(utils, abel)
{
    FILE *source = fopen("abel.cor", "r");
    FILE *compare = fopen("assets/abel.cor", "r");
    int value = cr_file_match_file(source, compare);

    cr_assert(eq(int, value, 1));
    fclose(source);
    fclose(compare);
}
