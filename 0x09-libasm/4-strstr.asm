BITS 64

	global	asm_strstr

	section	.text

	;; Copycat of the function strstr(3), in x86-64 Assembly

asm_strstr:

	mov	rcx, 0				; Set counter to 0
	mov	rbx, rdi			; Put first param string into rbx register.
	movzx	rdx, BYTE [rsi]			; Put single character from 2nd param into rdx register.

loop:

	cmp	BYTE [rbx], 0			; If end of the string, substring not found return null.
	je	null
	cmp	BYTE [rbx], dl			; Compare each character in first string to first char in 2nd.
	je	check				; If equal jump to check loop.
	inc	rbx
	jmp	loop

check:

	inc	rcx
	movzx	rdx, BYTE [rsi + rcx]		; Move the next character in the 2nd string into rdx register.
	cmp	dl, 0				; If end of 2nd string return to end (substring found).
	je	end
	cmp	BYTE [rbx + rcx], dl 		; Else compare next character in string 1 to next char in string 2.
	jne	reset				; If not equal, reset counter, increment rbx and return to loop
	jmp	check				; to continue to search for substring. Else continue.

reset:

	mov	rcx, 0
	inc	rbx
	jmp	loop

null:

	mov	rbx, 0

end:
	mov	rax, rbx
	
	ret
