char *ft_strcpy(char *dst, const char *src)
{
    while (true)
    {
        *dst = *src;
        if (*src == 0)
        {
            break;
        }
        src++;
        dst++;
    }
    return dst;
}
