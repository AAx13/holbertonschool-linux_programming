BITS 64

	global	asm_strspn

	section	.text

	;; Copycat of the function strspn(3), in x86-64 Assembly.

asm_strspn:

	xor	rax, rax		; Zero rax rbx and r9 for use later.
	xor	rbx, rbx
	xor	r9, r9
	mov	rcx, -1			; Initialize rcx and rdx to -1 for use as counters.
	mov	rdx, -1

loop:

	inc	rcx
	mov	bl, BYTE [rdi + rcx] 	; Iterate first string to check character by character.
	cmp	bl, 0			; Jump to end if we've reached the end of s1 or s1 is null.
	je	end

accept_loop:

	inc	rdx
	mov	r9b, BYTE [rsi + rdx] 	; Nested loop to search for accepted characters.
	cmp	r9b, 0			; If *s2 is null then there are no more chars to be accepted
	je	end			; from the initial part of s1 so we return.

	cmp	bl, r9b			; Compare *S1 to *S2 if not equal continue to iterate S2
	jne	accept_loop 

	inc	rax			; Else increment rax reset rdx to -1 and jump to outer loop.
	mov	rdx, -1
	jmp	loop

end:

	ret
