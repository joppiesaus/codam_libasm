#include "libasm.h"
#include "libasm_testing.h"

#include <string.h> /* memcmp */
#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf */
#include <unistd.h> /* pipe, read, write */
#include <fcntl.h> /* fcntl */
#include <sys/errno.h>

static void test_write_single(const char *data, ssize_t len)
{
    int     fd[2];
    char    *buf;

    printf("ft_write(...)");

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
    close(fd[0]);
    if (ret == -1)
    {
        perror("read");
        free(buf);
    }
    check_result(memcmp(buf, data, len) == 0);
    free(buf);
}

static void test_read_single(const char *data, ssize_t len)
{
    int     fd[2];
    char    *buf;

    printf("ft_read(...)");

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return;
    }

    // set pipes to nonblocking
    fcntl(fd[0], F_SETFL, O_NONBLOCK);
    fcntl(fd[1], F_SETFL, O_NONBLOCK);

    ssize_t ret = write(fd[1], data, len);
    close(fd[1]);
    if (ret == -1)
    {
        perror("write");
        close(fd[0]);
        return;
    }
    else if (ret != len)
    {
        printf("warning: write returns %zd bytes written, ft_read might \"fail\"\n", ret);
    }

    buf = malloc(len);
    if (!buf)
    {
        perror("malloc");
        close(fd[0]);
        return;
    }

    ret = ft_read(fd[0], buf, len);
    close(fd[0]);
    if (ret == -1)
    {
        perror("ft_read");
        free(buf);
        return;
    }
    check_result(memcmp(buf, data, len) == 0);
    free(buf);
}

void test_write()
{
    test_write_single("helllo", 6);
    test_write_single("", 0);

    #define BIGBUF_LEN 65536

    char *bigbuf = malloc(BIGBUF_LEN);
    memset(bigbuf, '#', BIGBUF_LEN);
    test_write_single(bigbuf, BIGBUF_LEN);
    free(bigbuf);

    test_write_single("helllo", 6);

    printf("ft_write(<invalid fd>...)");

    ssize_t result = ft_write(34245256, "hi", 2);
    check_result(result == -1 && errno == EBADF);

    #undef BIGBUF_LEN
}

void test_read()
{
    test_read_single("helllo", 6);
    test_read_single("", 0);

    #define BIGBUF_LEN 65536

    char *bigbuf = malloc(BIGBUF_LEN);
    memset(bigbuf, '#', BIGBUF_LEN);
    test_read_single(bigbuf, BIGBUF_LEN);
    free(bigbuf);

    test_read_single("helllo", 6);

    printf("ft_read(<invalid fd>...)");

    ssize_t result = ft_read(34245256, "hi", 2);
    check_result(result == -1 && errno == EBADF);

    #undef BIGBUF_LEN
}
