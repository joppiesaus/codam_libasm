# libasm
Small project where I implement some libc functions in x86_64 to learn more about assembly.

## hints

Function arguments(in order):
`RDI RSI RDX RCX R8 R9`

return regsiter:
`RAX`

syscall move `rax, <syscall code>` then `syscall`

useful links:
 - [amd64 instruction reference](https://www.felixcloutier.com/x86/)
 - [x64 cheat sheet](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)
