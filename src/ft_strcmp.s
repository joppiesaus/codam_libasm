            section .text
            global ft_strcmp

        ; int   ft_strcmp(const char *s1, const char *s2)
        ;                 RDI             RSI

ft_strcmp:
compare_loop:
        movzx rax, byte [rdi]   ; get first byte at both s1 and s2
        movzx rcx, byte [rsi]
        cmp rax, 0    ; *s1 != 0
        jz end
        cmp rax, rcx  ; *s1 == *s2
        jnz end
        inc rdi       ; s1++
        inc rsi       ; s2++
        jmp compare_loop

end:
        sub rax, rcx ; return value = *s1 - *s2
        ; thankfully, c will automatically cast the return value to a 32 bit int.
        ; rax is returned
        ret
