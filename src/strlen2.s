

section .text
    global ft_strlen


; rdi is first arg
ft_strlen:
    mov     rbx, rdi

loop1:
    movzx   rax, byte [rdi]
    cmp     rax, 0
    jz      end
    inc     rdi
    jmp     loop1

end:
    sub rdi, rbx
    mov rax, rdi
    ret
