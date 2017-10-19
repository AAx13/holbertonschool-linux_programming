BITS 64

	global	asm_puts
	extern	asm_strlen

	section	.text

	;; Prints a string of characters on the standard output, in x86-64 Assembly

asm_puts:

	call	asm_strlen
	mov	rcx, rax	; Store strlen in rcx
	mov	rbx, rdi	; Store string to write in rbx

	mov	rax, 1		; Write syscall
	mov	rdi, 1
	mov	rsi, rbx	; String
	mov	rdx, rcx	; String length
	syscall			; Return value is bytes written to stdout.

	ret
