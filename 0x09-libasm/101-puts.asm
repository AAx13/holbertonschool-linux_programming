BITS 64

	global	asm_puts
	extern	asm_strlen

	section	.text

	;; Prints a string of characters on the standard output, in x86-64 Assembly

asm_puts:

	call	asm_strlen
	mov	rdx, rax	; Store strlen in rdx
	mov	rsi, rdi	; Store string to write in rsi

	mov	rax, 1		; Write syscall
	mov	rdi, 1
	syscall			; Return value is bytes written to stdout.

	ret
