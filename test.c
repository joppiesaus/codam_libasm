#include <string.h> /* strlen, strcmp */
#include <stdio.h> /* printf */

extern size_t ft_strlen(const char *str);
extern int ft_strcmp(const char *s1, const char *s2);

#define STRLEN(x) printf("strlen(\"%s\"): %zu, %zu", (x), strlen((x)), ft_strlen((x)));\
    check_result(strlen((x)) == ft_strlen((x)))

#define STRCMP(a, b) printf("strcmp(\"%s\", \"%s\"): %d, %d", (a), (b), strcmp((a), (b)), ft_strcmp((a), (b)));\
    check_result(strcmp((a), (b)) == ft_strcmp((a), (b)))

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
}

int main()
{
    test_strlen();
    printf("\n");
    test_strcmp();
    return 0;
}
