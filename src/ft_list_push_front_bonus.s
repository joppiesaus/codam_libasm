            section .text
            global ft_list_push_front

            ; typedef struct  s_list
            ; {
            ;     void            *data;
            ;     struct s_list   *next;
            ; }               t_list;


            ; void ft_list_push_front(t_list **head, const t_list *entry)
            ;                         RDI            RSI

ft_list_push_front:
            ; rax = t_list *front
            mov rax, [rdi]  ; front = *head
            mov [rdi], rsi  ; *head = entry
            mov [rsi + 8], rax ; entry->next = front;
            ret
