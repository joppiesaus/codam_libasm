# libasm
Small project where I implement some libc functions in x86_64 to learn more about assembly.

## hints

Function arguments(in order):
`rdi rsi rdx rcx r8 r9`

return register:
`rax`

syscall:
```
mov rax, <syscall code>
syscall
```

[registers preserved accross function calls](https://stackoverflow.com/a/18024743): `rbx, rsp, rbp, r12, r13, r14, r15`

useful links:
 - [amd64 instruction reference](https://www.felixcloutier.com/x86/)
 - [x64 cheat sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
