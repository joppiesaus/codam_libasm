typedef struct  s_list
{
    void            *data;
    struct s_list   *next;
}               t_list;

void ft_list_push_front(t_list **head, const t_list *entry)
{
    t_list  *front;

    front = *head;
    *head = entry;
    entry->next = front;
}
