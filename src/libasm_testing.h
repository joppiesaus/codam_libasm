#ifndef LIBASM_TESTING_H
#define LIBASM_TESTING_H

void    check_result(int result);
int     check_bytes(const char *s, const char value, size_t n);
int     ft_sign(int n);

void    test_write();

#endif
