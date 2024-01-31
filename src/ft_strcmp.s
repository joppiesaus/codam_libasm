            section .text
            global ft_strcmp

ft_strcmp:
        ; RDI = const char *s1
        ; RSI = const char *s2
        mov rcx, rdi
        mov rdx, rsi

compare_loop:
        movzx rax, byte [rcx]
        movzx rbx, byte [rdx]
        cmp rax, 0 ; *s1 != 0
        jz end
        cmp rax, rbx ; *s1 == *s2
        jnz end
        inc rcx ; s1++
        inc rdx ; s2++
        jmp compare_loop

end:
        sub rax, rbx ; return value = *s1 - *s2
        ; rax is returned
        ret
