section .text
    global ft_strcmp


; rdi first arg, rsi second
; int ft_strcmp(const char *s1, const char *s2)

ft_strcmp:
    movzx rax, byte [rdi]
    cmp rax, 0
    jz end
    movzx rcx, byte [rsi]
    cmp rax, rcx
    jnz end
    inc rdi
    inc rsi
    jmp ft_strcmp

end:
    mov rax, 0
    ;sub rax, rcx
    ret
    