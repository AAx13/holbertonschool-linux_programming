BITS 64

	global	asm_strcspn

	section	.text

	;; Copycat of the function strcspn(3), in x86-64 Assembly

asm_strcspn:

	xor     rax, rax		; Zero rax rbx and r9 for use later.
	xor     rbx, rbx
	xor     r9, r9
	mov     rcx, -1			; Initialize rcx and rdx to -1 for use as counters.
	mov     rdx, -1

loop:

	inc     rcx
	mov     bl, BYTE [rdi + rcx] 	; Iterate first string to check character by character.
	cmp     bl, 0
	je      end			; Jump to end if we've reached the end of s1 or s1 is null.

reject_loop:

	inc     rdx
	mov     r9b, BYTE [rsi + rdx] 	; Nested loop to search for rejected characters.
	cmp     r9b, 0			; If reached end of s2 jump to s2_rejected, increment rax,
	je      s2_rejected		; reset rdx counter and jump to outer loop.

	cmp     bl, r9b			; Compare *s1 char to *s2 char if not equal continue to interate s2.
	jne     reject_loop

end:
	ret

s2_rejected:

	inc	rax
	mov	rdx, -1
	jmp	loop
	
