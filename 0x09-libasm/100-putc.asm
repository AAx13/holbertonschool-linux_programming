BITS 64

	global	asm_putc

	section	.text

	;; Prints a single character on the standard output, in x86-64 Assembly

asm_putc:

	push	rbp
	mov	rbp, rsp

	sub	rsp, 4
	mov	[rsp], edi	; Move size of DWORD (4 bytes) onto the stack and fill wtih a char.

	mov	rax, 1		; Mov 1 into rax selecting the write syscall.
	mov	rdi, 1		; Mov 1 into rdi (arg1 of write) selecting stdout file descriptor.
	mov	rsi, rsp
	mov	rdx, 1		; Mov 1 into rdx (arg3) because we only want to print 1 byte.
	syscall			; Call write()

	mov	rsp, rbp
	pop	rbp

	ret
	
