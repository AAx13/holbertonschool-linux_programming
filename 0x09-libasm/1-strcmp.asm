BITS 64

	global	asm_strcmp
	
	section	.text

	;; Copycat of the function strcmp(3), in x86-64 Assembly

asm_strcmp:

	mov	rax, 0
	mov	rcx, -1
loop:

	inc	rcx
	movzx	rdx, BYTE [rdi + rcx] 	; Transfer one character at a time from s1 and s2 to rdx and rbx.
	movzx	rbx, BYTE [rsi + rcx]
	cmp	dl, 0			; Compare *s1 to null byte.
	je	lesser
	cmp	bl, 0			; Compare *s2 to null byte.
	je	greater
	sub	dl, bl			; Compare *s1 and *s2 to eachother. (Subtract *s1 from *s2)
	jl	lesser
	jg	greater
	jmp	loop

lesser:
	
	cmp	bl, 0			; If *s1 is null and *s2 is also null, return 0.
	je	end
	mov	rax, -1			; Else, return -1 for lesser.
	jmp	end

greater:

	cmp	dl, 0			; If *s2 is null and *s1 is also null, return 0.
	je	end
	mov	rax, 1			; Else, return 1 for greater.

end:
	ret
