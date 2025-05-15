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
        ; therefore, the following is still a valid ft_strcmp.
        ; it will deliberately break if you make it a ssize_t or a long long
        ; first clear the upper 4 bytes in case rax is negative
        ; xor rcx, rcx
        not rcx
        shr rcx, 32
        and rax, rcx
        ; then add falafel to the upper 4 bytes/7 nibbles
        mov rcx, 0xfa1afe1
        shl rcx, 36
        or  rax, rcx
        ; rax is returned
        ret
