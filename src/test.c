#include "libasm.h"
#include "libasm_testing.h"
#include "bonus.h"

#include <string.h> /* strlen, strcmp */
#include <stdio.h> /* printf, fflush */
#include <stdlib.h> /* memset */
#include <sys/errno.h> /* errno */

#define STRLEN(x) printf("strlen(\"%s\"): %zu, %zu", (x), strlen((x)), ft_strlen((x)));\
    check_result(strlen((x)) == ft_strlen((x)))

#define STRCMP(a, b) printf("strcmp(\"%s\", \"%s\"): %d, %d", (a), (b), ft_sign(strcmp((a), (b))), ft_sign(ft_strcmp((a), (b))));\
    check_two(ft_sign(strcmp((a), (b))), ft_sign(ft_strcmp((a), (b))))

static void check_two(int a, int b)
{
    check_result(a == b);
}

static void test_strlen()
{
    STRLEN("");
    STRLEN("hi");
    STRLEN("hi\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
    STRLEN("h342fsi");
    STRLEN("88888888");
    STRLEN("ninenine9");
    STRLEN("hello\0test");
    STRLEN("the impostor is sus. ther eis an impostor among us");
}

static void test_strcmp()
{
    STRCMP("a", "a");
    STRCMP("", "");
    STRCMP("abbbbbb", "abbbbbb");
    STRCMP("abbbbbb", "abbbbbc");
    STRCMP("abbbbbbb", "abbbbbcb");
    STRCMP("", "b");
    STRCMP("b", "");
    STRCMP("b\0bsfssdfs", " ggbef");
    STRCMP("\220", "");
    STRCMP("", "\220");
    STRCMP("f", "g");
}

static void test_single_strcpy(const char *s)
{
    #define ADDITIONAL_LEN 18

    const size_t len = strlen(s) + 1;
    char *dst = calloc(len + ADDITIONAL_LEN, sizeof(char));

    // also add some "trap" bytes, if these are changed then we know
    // that ft_strcpy accesses memory out of bounds
    memset(dst + len, 42, ADDITIONAL_LEN);

    printf("ft_strcpy(\"%.32s\")", s);
    fflush(stdout);
    char *returned = ft_strcpy(dst, s);
    // print_bytes(dst, len + ADDITIONAL_LEN);
    // write(1, dst, len + ADDITIONAL_LEN);

    check_result(
        strcmp(s, dst) == 0 &&
        check_bytes(dst + len, 42, ADDITIONAL_LEN) &&
        returned == dst
    );

    free(dst);
}

static void test_strcpy()
{
    test_single_strcpy("");
    test_single_strcpy("asdfsd");
    test_single_strcpy("asdfsdff");
    test_single_strcpy("asfdsdfadsf");
    test_single_strcpy("");

    char *big = generate_big_string();
    test_single_strcpy(big);
    free(big);
}

static void test_single_strdup(const char *s)
{
    char *dst;

    printf("strdup(\"%.32s\")", s);
    dst = ft_strdup(s);
    check_result(strcmp(s, dst) == 0 && dst != s);
    free(dst);
}

static void test_strdup()
{
    test_single_strdup("");
    test_single_strdup("aaaaaaaa");
    test_single_strdup("aa aaab");
    test_single_strdup("aaaaaaaab");

    char *big = generate_big_string();
    test_single_strdup(big);
    free(big);
}

int main()
{
    test_strlen();
    printf("\n");
    test_strcmp();
    printf("\n");
    test_strcpy();
    printf("\n");
    test_strdup();
    printf("\n");
    test_write();
    printf("\n");
    test_read();

    test_bonus();
    return 0;
}
