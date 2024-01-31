            section .text
            global ft_read
            extern __errno_location     ; see ft_write.s for more info

        ; ssize_t read(int fd, void *buf, size_t count)
        ;              RDI     RSI        RDX
ft_read:
        xor     rax, rax  ; set rax to 0 which is the syscall for read
        ; RDI, RSI, RDX should be filled in
        syscall

        ; check for error. syscall returns negative errno on errror
        cmp     rax, 0
        jge     end

        neg     rax     ; flip errno(return value is negative errno)
        push    rax     ; save errno
        call    __errno_location wrt ..plt      ; put errno location into rax
        pop     rbx     ; put errno into rbx
        mov     [rax], ebx      ; write errno(is 32 bit int)
        mov     rax, -1         ; return -1

end:
        ret
