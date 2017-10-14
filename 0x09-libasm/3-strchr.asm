BITS 64

	global	asm_strchr

	section	.text

	;; Copycat of the function strchr(3), in x86-64 Assembly

asm_strchr:


loop:

	mov	al, [edi]	; Move first character of the string passed into BYTE [rax]
	cmp	al, sil		; Compare to character passed.
	je	found
	cmp	al, 0		; Compare character to 0 or null byte.
	je	zero
	inc	di		; Iterate register holding the string.
	jmp	loop

found:

	mov	eax, edi	; The pointer to the string starting at the last character checked
	jmp	end		; goes into return register.

zero:

	mov	eax, 0		; If end of string set return register to null.

end:	
	ret
	
	
