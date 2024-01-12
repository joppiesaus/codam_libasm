#include <string.h> /* strlen, strcmp */
#include <stdio.h> /* printf, fflush */
#include <stdlib.h> /* memset */
#include <unistd.h> /* write */

extern size_t ft_strlen(const char *str);
extern int ft_strcmp(const char *s1, const char *s2);
extern char *ft_strcpy(char *dst, const char *src);

#define STRLEN(x) printf("strlen(\"%s\"): %zu, %zu", (x), strlen((x)), ft_strlen((x)));\
    check_result(strlen((x)) == ft_strlen((x)))

#define STRCMP(a, b) printf("strcmp(\"%s\", \"%s\"): %d, %d", (a), (b), strcmp((a), (b)), ft_strcmp((a), (b)));\
    check_result(strcmp((a), (b)) == ft_strcmp((a), (b)))

// returns true if n bytes in s are all equal to value
static int check_bytes(const char *s, const char value, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (s[i] != value)
        {
            return 0;
        }
    }
    return 1;
}

// // prints all bytes as chars to the to the terminal, with null terminators as 0
// // up to n chars.
// static void print_bytes(const char *s, size_t n)
// {
//     for (size_t i = 0; i < n; i++)
//     {
//         char c = s[i];
//         if (c == 0)
//         {
//             c = '0';
//         }
//         write(1, &c, 1);
//     }
// }

static void check_result(int result)
{
    if (result)
    {
        printf("...\tgood\n");
    }
    else
    {
        printf("...\tBAD!\n");
    }
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
}

static void test_single_strcpy(const char *s)
{
    #define ADDITIONAL_LEN 18

    const size_t len = strlen(s) + 1;
    char *dst = calloc(len + ADDITIONAL_LEN, sizeof(char));

    // also add some "trap" bytes, if these are changed then we know
    // that ft_strcpy accesses memory out of bounds
    memset(dst + len, 42, ADDITIONAL_LEN);

    printf("ft_strcpy %s", s);
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
}

int main()
{
    test_strlen();
    printf("\n");
    test_strcmp();
    printf("\n");
    test_strcpy();
    return 0;
}
