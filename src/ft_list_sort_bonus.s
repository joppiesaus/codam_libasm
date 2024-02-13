            section .text
            global ft_list_swap

            ; void ft_list_swap(t_list **tracer, t_list *to_swap)
            ;                   RDI              RSI

; uses rax, rbx, rsi, rdi
ft_list_swap:
        ; RAX = t_list *tail;
        ; RBX = t_list *next;

        mov rax, [rsi + 8]  ; tail = to_swap->next
        mov rbx, [rdi]      ; next = *tracer
        mov [rbx + 8], rax  ; next->next = tail
        mov [rdi], rsi      ; *tracer = to_swap
        mov [rsi + 8], rbx  ; to_swap->next = next
        ret

; uses rax, rsi, rdi
; does not work for some reason
; ft_list_swap:
;         ; RAX = t_list *next;

;         ; mov rbx, [rsi + 8]     ; tail = to_swap->next
;         mov rax, [rdi]           ; next = *tracer
;         mov [rax + 8], [rsi + 8] ; next->next = tail
;         mov [rdi], rsi           ; *tracer = to_swap
;         mov [rsi + 8], rax       ; to_swap->next = next
;         ret
