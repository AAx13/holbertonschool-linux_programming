BITS 64

	global	asm_strcmp
	
	section	.text

	;; Copycat of the function strcmp(3), in x86-64 Assembly

asm_strcmp:

	mov	rax, rdi	; First string into return value.
	cmp	BYTE [rax], 0	; Check if first string is null.
	je	lesser
	cmp	BYTE [rsi], 0	; Check if second string is null.
	je	greater
	sub	rax, rsi	; Subtract first string from the second.

	cmp	rax, 0		; Compare result to 0.
	jl	lesser
	jg	greater

lesser:				; lesser greater and equal refer to setting the correct
				; return value based on comparison result. 
	mov	rax, -1		
	jmp	end

greater:

	mov	rax, 1
	jmp	end

end:
	ret
