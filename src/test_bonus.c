#include "bonus.h"
#include "libasm.h"
#include "libasm_testing.h"

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc */

void test_ft_list_push_front()
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


void test_bonus()
{
    printf("\n*** BONUS ***\n");
    test_ft_list_push_front();
}
