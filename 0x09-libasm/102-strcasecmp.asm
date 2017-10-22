BITS 64

	global	asm_strcasecmp

	section	.text

	;; Copycat of the function strcasecmp(3), in x86-64 Assembly

asm_strcasecmp:

	xor	rax, rax		; Zero rax, rbx, and r9 registers for use later.
	xor	rbx, rbx
	xor	r9, r9
	mov	rcx, -1

loop:
	
	inc	rcx
	mov	bl, BYTE [rdi + rcx] 	; Transfer 1 byte (char) from first string.
	cmp	bl, 0			; Compare to null char.
	je	skip_s1_lower		; If null skip lower case conversion.
	or	bl, 20H
	
skip_s1_lower:
	
	mov     r9b, BYTE [rsi + rcx] 	; Transfer 1 byte (char) from second string.
	cmp	r9b, 0			; Compare to null char.
	je	s2_null_check		; If null, check if last char from string 1 is also null.
	or	r9b, 20H		; Else, convert char to lower case if not.

compare:
	
	sub	rbx, r9			; Compare both characters and continue loop if equal.
	jz	loop

end:
	mov	rax, rbx

	ret

s2_null_check:

	cmp	bl, 0			; If first string char is null.
	je	end			; Jump to end and return (both strings empty or at end.)
	jmp	compare			; Else, jump to compare.
	
