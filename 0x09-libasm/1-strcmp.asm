BITS 64

	global	asm_strcmp
	
	section	.text

	;; Copycat of the function strcmp(3), in x86-64 Assembly

asm_strcmp:

	mov	rax, rdi
	cmp	BYTE [rax], 0
	je	lesser
	cmp	BYTE [rsi], 0
	je	greater
	sub	rax, rsi

	cmp	rax, 0
	jl	lesser
	jg	greater
	je	equal

lesser:

	mov	rax, -1
	jmp	end

greater:

	mov	rax, 1
	jmp	end

equal:

	mov	rax, 0
	jmp	end

end:
	ret
