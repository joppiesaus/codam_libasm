; ----------------------------------------------------------------------------------------
;     calculates strlen("7 chars")
;     nasm -felf64 strlen_cringe.s && ld strlen_cringe.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _start

          section   .text
_start:
        mov rax, 0
        mov [count_char], rax

strlen:
        mov rbx, [count_char] ; the count
        mov rcx, str ; current address

        ; TODO this compares size_t and not byte???
        ; TODO do "minus trick" instead, is better.
strlen_step:
        mov rax, [rcx] ; load current char in string/pointer
        inc rcx ; increase pointer by 1 byte to right
        inc rbx ; increase the count
        cmp rax, 0
        jnz strlen_step ; go back if not 0 yet

        dec rbx ; we counted one too much, decrement one
        mov [count_char], rbx

print:
        mov rax, [count_char]
        add rax, 0x30 ; add '0' to make it human-readable
        mov [count_char], rax

        ; see https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
        mov     rax, 1                  ; system call for write
        mov     rdi, 1                  ; file handle 1 is stdout
        mov     rsi, count_char            ; address of string to output
        
        ; lea     rsi, count_char
        mov     rdx, 1                  ; number of bytes
        syscall                           ; invoke operating system to do the write

        mov     rax, 60                 ; system call for exit
        xor     rdi, rdi                ; exit code 0
        syscall                         ; invoke operating system to exit


        section .data
        str:  db  "7 chars"

        section .bss
        count_char: resb 1
