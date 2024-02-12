#include "bonus.h"
#include "libasm.h"
#include "libasm_testing.h"

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free, exit */

t_list *create_list_item(size_t content)
{
    t_list  *li;

    li = malloc(sizeof(t_list));
    if (!li)
    {
        perror("malloc");
        exit(1);
    }
    li->data = (void *)content;
    li->next = NULL;
    return li;
}

// DOES NOT FREE CONTENTS by design
// WARNING: DOES NOT SET LIST TO NULL
void free_list(t_list *lst)
{
    t_list *next;

    while (lst)
    {
        next = lst->next;
        free(lst);
        lst = next;
    }
}

void test_list_push_front()
{
    t_list *lst = NULL;

    /* screw it... stack allocate the linked list */
    t_list item;
    t_list item2;

    item.next = (t_list *)0xbadfa1afe1;
    item.data = (void *)0xdabcafe;

    printf("ft_list_push_front(<empty list>, item)");
    ft_list_push_front(&lst, &item);
    check_result(lst->next == NULL && lst->data == (void *)0xdabcafe);

    item2.next = (t_list *)0xfa1afe1;
    item2.data = (void *)0xc0ffeecafe;
    printf("ft_list_push_front(<list>, item)");
    ft_list_push_front(&lst, &item2);
    check_result(lst->next == &item && lst->data == (void *)0xc0ffeecafe
        && lst->next->data == (void *)0xdabcafe
        && lst->next->next == NULL);
}

void test_list_size()
{
    t_list *lst = NULL;

    printf("ft_list_size(NULL)");
    check_result(ft_list_size(lst) == 0);

    ft_list_push_front(&lst, create_list_item(1));

    printf("ft_list_size(<1 element>)");
    check_result(ft_list_size(lst) == 1);

    ft_list_push_front(&lst, create_list_item(2));
    printf("ft_list_size(<2 elements>)");
    check_result(ft_list_size(lst) == 2);

    ft_list_push_front(&lst, create_list_item(3));
    ft_list_push_front(&lst, create_list_item(4));
    ft_list_push_front(&lst, create_list_item(5));

    printf("ft_list_size(<5 elements>)");
    check_result(ft_list_size(lst) == 5);

    ft_list_push_front(&lst, create_list_item(6));
    ft_list_push_front(&lst, create_list_item(7));
    ft_list_push_front(&lst, create_list_item(8));
    ft_list_push_front(&lst, create_list_item(9));
    ft_list_push_front(&lst, create_list_item(10));
    ft_list_push_front(&lst, create_list_item(11));

    printf("ft_list_size(<11 elements>)");
    check_result(ft_list_size(lst) == 11);

    free_list(lst);
}


void test_bonus()
{
    printf("\n*** BONUS ***\n");
    test_list_push_front();
    printf("\n");
    test_list_size();
}
