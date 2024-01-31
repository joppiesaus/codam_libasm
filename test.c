#include "libasm.h"

#include <string.h> /* strlen, strcmp */
#include <stdio.h> /* printf, fflush */
#include <stdlib.h> /* memset */
#include <unistd.h> /* write */
#include <sys/errno.h> /* errno */
#include <fcntl.h>

#define STRLEN(x) printf("strlen(\"%s\"): %zu, %zu", (x), strlen((x)), ft_strlen((x)));\
    check_result(strlen((x)) == ft_strlen((x)))

#define STRCMP(a, b) printf("strcmp(\"%s\", \"%s\"): %d, %d", (a), (b), ft_sign(strcmp((a), (b))), ft_sign(ft_strcmp((a), (b))));\
    check_two(ft_sign(strcmp((a), (b))), ft_sign(ft_strcmp((a), (b))))

/*
// for some reason this doesn't work
#define STRCMP(a, b) printf("strcmp(\"%s\", \"%s\"): %d, %d", (a), (b), ft_sign(strcmp((a), (b))), ft_sign(ft_strcmp((a), (b))));\
    check_result(ft_sign(strcmp((a), (b))) == ft_sign(ft_strcmp((a), (b))))*/

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

// static void print_byte(const unsigned char b)
// {
//     printf("%x%x", b >> 4, b & 0x0f);
// }

// static void print_int(void *i)
// {
//     const char *buf = i;

//     print_byte(buf[0]);
//     printf(" ");
//     print_byte(buf[1]);
//     printf(" ");
//     print_byte(buf[2]);
//     printf(" ");
//     print_byte(buf[3]);
//     printf("\n");
// }

// returns the "sign" of the number
static int ft_sign(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n > 0)
    {
        return 1;
    }
    return 0;
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

static void test_single_strdup(const char *s)
{
    char *dst;

    printf("strdup(\"%s\")", s);
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
}

static void test_write_single(const char *data, ssize_t len)
{
    int     fd[2];
    char    *buf;
    
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return;
    }

    // set pipes to nonblocking
    fcntl(fd[0], F_SETFL, O_NONBLOCK);
    fcntl(fd[1], F_SETFL, O_NONBLOCK);

    ssize_t ret = ft_write(fd[1], data, len);
    close(fd[1]);
    if (ret == -1)
    {
        perror("ft_write");
        close(fd[0]);
        return;
    }
    else if (ret != len)
    {
        printf("ft_write returns %zd bytes written, is this correct?\n", ret);
    }

    buf = malloc(len);
    if (!buf)
    {
        perror("malloc");
        close(fd[0]);
        return;
    }

    ret = read(fd[0], buf, len);
    if (ret == -1)
    {
        perror("read");
        close(fd[0]);
    }
    check_result(memcmp(buf, data, len) == 0);
    free(buf);
    close(fd[0]);
}

static void test_write()
{
    test_write_single("helllo", 6);
    test_write_single("", 0);

    #define BIGBUF_LEN 65536

    char *bigbuf = malloc(BIGBUF_LEN);
    memset(bigbuf, '#', BIGBUF_LEN);
    test_write_single(bigbuf, BIGBUF_LEN);
    free(bigbuf);

    test_write_single("helllo", 6);

    ssize_t result = ft_write(34245256, "hi", 2);
    check_result(result == -1 && errno == EBADF);

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
    return 0;
}
