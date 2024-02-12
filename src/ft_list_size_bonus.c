

size_t  ft_list_size(const t_list *lst)
{
    size_t  n; // rax

    n = 0;
    while (lst != NULL)
    {
        n++;
        lst = lst->next;
    }
    return (n);
}
