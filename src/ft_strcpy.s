            section .text
            global ft_strcpy

ft_strcpy:
        ; RDI = char *dst
        ; RSI = const char *src
        mov rax, rdi
        mov rbx, rsi

compare_loop:
        ; this is probably really slow
        movzx rcx, byte [rbx]
        mov [rax], cl ; CL is first byte of rcx, see https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf
        cmp rcx, 0
        jz end
        inc rbx
        inc rax
        jmp compare_loop

end:
        mov rax, rdi ; return dest address
        ret
