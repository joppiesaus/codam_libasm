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

        cmp     rax, 0  ; check for error. syscall returns negative errno on errror
        jge     end     ; jump to end when everything OK

        neg     rax     ; flip errno(return value is negative errno)
        push    rax     ; save errno
        call    __errno_location wrt ..plt      ; put errno location into rax
        pop     rcx     ; put errno into rcx
        mov     [rax], ecx      ; write errno(is 32 bit int)
        mov     rax, -1         ; return -1

end:
        ret
