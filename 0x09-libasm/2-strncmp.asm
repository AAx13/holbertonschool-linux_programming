BITS 64

	global	asm_strncmp

	section	.text

	;; Copycat of the function strncmp(3), in x86-64 Assembly

asm_strncmp:

	mov	cx, -1
	mov	rax, 0

loop:
	
	inc	cx			; Starting from zero we compare counter to size_t n passed.
	cmp	cx, dx
	je	end			; Jump to end if counter is equal to size_t n passed.

	mov	al, BYTE [rdi + rcx] 	; Move next character into BYTE rax register.
	sub	al, BYTE [rsi + rcx]	; Subtract that character from the next character in 2nd string.
	cmp	al, 0			; Compare the result to 0
	jl	lesser			; If less than - jump to lesser label modify value to -1 and return.
	jg	greater			; If greater than - jump to greater label modify value to 1 and return.
	jmp	loop

lesser:

	mov	eax, -1
	jmp	end

greater:
	
	mov	eax, 1
	jmp	end
	
end:

	ret
