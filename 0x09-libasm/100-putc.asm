BITS 64

	global	asm_putc

	section	.text

	;; Prints a single character on the standard output, in x86-64 Assembly

asm_putc:

	mov	[rsi], rdi	; Store char into another register as we'll need rsi for syscall.

	mov	rax, 1		; Mov 1 into rax selecting the write syscall.
	mov	rdi, 1		; Mov 1 into rdi (arg1 of write) selecting stdout file descriptor.
	mov	rdx, 1		; Mov 1 into rdx (arg3) because we only want to print 1 byte.
	syscall			; Call write()

	ret
	
