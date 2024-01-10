#include <string.h> /* strlen */
#include <stdio.h> /* printf */

extern size_t ft_strlen(const char *str);

#define STRLEN(x) printf("strlen(\"%s\"): %zu, %zu", x, strlen((x)), ft_strlen((x)));\
    check_result(strlen((x)) == ft_strlen((x)))


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

int main()
{
    test_strlen();
    return 0;
}
