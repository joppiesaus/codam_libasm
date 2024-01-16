                section .text
                global ft_strdup

                extern ft_strlen
                extern ft_strcpy
                extern malloc

ft_strdup:
        ; rdi = const char *s
        push rdi         ; store rdi, we need it later
        call ft_strlen

        ; strlen(s) is now in rax

        inc rax           ; we need to allocate an extra byte for the null terminator

        mov rdi, rax
        ; xor rax, rax

        ; TODO: errno?
        call malloc wrt ..plt ; no idea what wrt ..plt does but you need it

        pop rsi         ; rsi = char *src for strcpy

        ; did malloc return NULL? return NULL as well.
        ; since rax is already 0/null no need to xorraxrax it.
        cmp rax, 0
        jz end

        mov rdi, rax    ; rdi = char *dst for strcpy
        call ft_strcpy
        ; return char *dst, which ft_strcpy nicely puts into rax already

end:
        ret
