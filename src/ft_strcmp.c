int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 != 0 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*((const unsigned char *)s1) - *((const unsigned char *)s2));
}
