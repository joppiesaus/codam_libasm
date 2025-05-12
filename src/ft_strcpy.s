            section .text
            global ft_strcpy

ft_strcpy:
        ; RDI = char *dst
        ; RSI = const char *src
        ; store rdi, we need it later
        mov rdx, rdi
 
compare_loop:
        ; this is probably really slow
        movzx rcx, byte [rsi]
        mov [rdi], cl ; CL is first byte of rcx, see https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf
        cmp rcx, 0
        jz end
        inc rsi
        inc rdi
        jmp compare_loop

end:
        mov rax, rdx ; return dest address
        ret
