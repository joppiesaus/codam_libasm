            section .text
            global ft_write

            ; so errno is actually(implementation dependent):
            ; extern int *__errno_location (void) __THROW __attribute_const__;
            ; # define errno (*__errno_location ())
            ; from /usr/include/errno.h

            extern __errno_location

        ; ssize_t ft_write(int fd, const void *buf, size_t count)
        ;                  RDI     RSI              RDX
ft_write:
        mov     rax, 1  ; syscall for write
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
