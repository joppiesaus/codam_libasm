; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;     nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

; IDEA; print char from register with write call

          global    _start

          section   .text
_start:

        ; supercoolchar = ' '
        ; but if you move it into .data you don't have to do this
        mov     rax, ' ' ; space
        mov     [supercoolchar], rax

print:
        ; see https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
        mov     rax, 1                  ; system call for write
        mov     rdi, 1                  ; file handle 1 is stdout
        mov     rsi, supercoolchar            ; address of string to output
        ; lea     rsi, supercoolchar
        mov     rdx, 1                  ; number of bytes
        syscall                           ; invoke operating system to do the write

        mov rax, [supercoolchar]        ; rax = supercoolchar
        inc rax                         ; supercoolchar++;
        mov [supercoolchar], rax        ; supercoolchar = rax
        sub rax, ('*' + 1)              ; if supercoolchar <= '*' print & increment again
        jnz print


        mov     rax, 60                 ; system call for exit
        xor     rdi, rdi                ; exit code 0
        syscall                         ; invoke operating system to exit


        ; section .data
        ; supercoolchar:  db  ' '

        section .bss
        supercoolchar: resb 1 ; reserve 1 byte as static variable


; in c:
; int main()
; {
;     static char supercoolchar;
;     supercoolchar = ' ';

;     do
;     {
;         write(1, &supercoolchar, 1);
;         supercoolchar++;
;     }
;     while (supercoolchar != ('*' + 1))

;     exit(0);
; }
