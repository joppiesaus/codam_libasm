; see ft_strlen.c for this function in c

; you could compare size_t's but then you get that weird
; speed hack thing with the bitshift magic

                        section .text
                        global ft_strlen

        ; size_t ft_strlen(const char *str)
        ;                  RDI

ft_strlen:
        mov rax, rdi ; copy string's address to rax

strlen_step:
        movzx rcx, byte [rax] ; get current char, only copy one byte
        cmp rcx, 0
        jz strlen_out ; if current char == 0, we're done, escape

        inc rax ; otherwise increment the address, continue
        jmp strlen_step

strlen_out:
        sub rax, rdi
        ; rax is returned
        ret
