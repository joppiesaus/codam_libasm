/* swaps two elements of a linked list
 * you could remove the tail variable but it doesn't work
 * in my assembly implementation */
static void ft_list_swap(t_list **tracer, t_list *to_swap)
{
    t_list  *tail;
    t_list  *next;

    tail = to_swap->next;
    next = *tracer;
    next->next = tail;
    *tracer = to_swap;
    to_swap->next = next;
}

/* TODO: test
 * sort of a gnome sort. idk it's innefficient af, but it's simple,
 * assembly is hard enough on its own */
void    ft_list_sort(t_list **lst, int (*cmp)(void *, void *))
{
    t_list  *cur;
    t_list  **tracer;
    size_t  is_sorted;

    is_sorted = 0;
    while (is_sorted == 0)
    {
        tracer = lst;
        cur = *tracer;
        is_sorted = 1; // inc?
        while (cur && cur->next)
        {
            if ((*cmp)(cur->data, cur->next->data) > 0) // TODO: verify
            {
                swap(tracer, cur->next);
                is_sorted = 0;
            }
            tracer = &cur->next;
            cur = *tracer;
        }
    }
}
