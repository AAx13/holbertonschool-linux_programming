BITS 64

	global	asm_strcasecmp

	section	.text

	;; Copycat of the function strcasecmp(3), in x86-64 Assembly

asm_strcasecmp:

	mov	rax, 0
	mov	rcx, -1

loop:

	inc	rcx
	movzx	r8, BYTE [rdi + rcx]
	movzx	r9, BYTE [rsi + rcx]
	cmp	r8, 0
	je	end
	cmp	r9, 0
	je	end
	jmp	loop

end:
	ret
