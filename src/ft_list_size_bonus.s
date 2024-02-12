            section .text
            global ft_list_size

            ; size_t  ft_list_size(const t_list *lst);
            ;                      RDI


; even simpler than ft_strlen
ft_list_size:
            xor rax, rax ; n = 0;

step:                    ; while (lst != NULL)
            cmp rdi, 0
            jz return
            inc rax            ; n++
            mov rdi, [rdi + 8] ; lst = lst->next
            jmp step

return:
            ret