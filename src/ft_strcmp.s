            section .text
            global ft_strcmp

ft_strcmp:
        ; RDI = const char *s1
        ; RSI = const char *s2

compare_loop:
        movzx rax, byte [rdi]
        movzx rcx, byte [rsi]
        cmp rax, 0 ; *s1 != 0
        jz end
        cmp rax, rcx ; *s1 == *s2
        jnz end
        inc rdi ; s1++
        inc rsi ; s2++
        jmp compare_loop

end:
        sub rax, rcx ; return value = *s1 - *s2
        ; rax is returned
        ret
