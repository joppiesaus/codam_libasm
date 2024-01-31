char *ft_strdup(const char *s)
{
    size_t  len;
    char    *ret;

    len = ft_strlen(s);
    ret = malloc(len + 1);
    if (ret == NULL)
    {
        return ret;
    }
    ft_strcpy(ret, s);
    return ret;
}
