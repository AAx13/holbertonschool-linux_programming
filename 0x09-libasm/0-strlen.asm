BITS 64

	global	asm_strlen

	section	.text

	;; Copycat of the function strlen(3), in x86-64 Assembly

asm_strlen:

	mov	rcx, -1			; Initialize with -1 incase empty strings are passed.
loop:
	inc     rcx			; Increment counter register.
	cmp     BYTE [rdi + rcx], 0	; Compare register holding string at the position of the rcx counter val.
	jne	loop			; Continue loop if not null.

	mov	rax, rcx		; Return the counters value.
	ret
