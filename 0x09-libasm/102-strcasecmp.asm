BITS 64

	global	asm_strcasecmp

	section	.text

	;; Copycat of the function strcasecmp(3), in x86-64 Assembly

asm_strcasecmp:

	xor	rax, rax		; Zero rax, rdx, and rbx registers for use later.
	xor	rdx, rdx
	xor	rbx, rbx
	mov	rcx, -1

loop:
	
	inc	rcx
	mov	dl, BYTE [rdi + rcx] 	; Transfer 1 byte (char) from first string.
	cmp	dl, 0			; Compare to null char.
	je	skip_s1_lower		; If null skip lower case conversion.
	or	dl, 20H
	
skip_s1_lower:
	
	mov     bl, BYTE [rsi + rcx] 	; Transfer 1 byte (char) from second string.
	cmp	bl, 0			; Compare to null char.
	je	s2_null_check		; If null, check if last char from string 1 is also null.
	or	bl, 20H			; Else, convert char to lower case if not.

compare:
	
	sub	rdx, rbx		; Compare both characters and continue loop if equal.
	jz	loop

end:
	mov	rax, rdx

	ret

s2_null_check:

	cmp	dl, 0			; If first string char is null.
	je	end			; Jump to end and return (both strings empty or at end.)
	jmp	compare			; Else, jump to compare.
	
