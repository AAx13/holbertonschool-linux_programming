BITS 64

	global	asm_strpbrk

	section	.text

	;; Copycat of the function strpbrk(3), in x86-64 Assembly

asm_strpbrk:

	xor	rbx, rbx		; Initialize rbx and r9 to 0.
	xor	r9, r9
	mov	rcx, -1			; Initialize rcx to -1 for us as a counter.

loop:

	mov	bl, BYTE [rdi]		; Place a character into rbx (bl).
	cmp	bl, 0			; Compare to null byte if true then s1 is null or
	je	null_not_found		; accepted characters were not found (Return NULL).

accept_loop:

	inc	rcx
	mov	r9b, BYTE [rsi + rcx] 	; Iterate and compare s2.
	cmp	r9b, 0			; If null byte found, jump to outer loop and continue to iterate s1.
	je	next_s1_char

	cmp	bl, r9b			; Compare *s1 to *s2 if equal then first occurence of accepted string
	je	found			; was found. Return pointer to location in s1.
	jmp	accept_loop		; Else continue.

null_not_found:

	mov	rax, 0
	jmp	end

found:

	mov	rax, rdi

end:
	ret
	
next_s1_char

	inc	rdi
	mov	rcx, -1
	jmp	loop
	
