BITS 64

	global	asm_memcpy

	section	.text

	;; Copycat of the function memcpy(3), in x86-64 Assembly

asm_memcpy:

	mov	rcx, -1
	movzx	rbx, BYTE [rsi]			; Move a single byte from 2nd parameter into rbx register.
	
loop:

	inc	rcx
	cmp	rdx, 0				; Compare 3rd param to 0 (stopping point)
	je	end
	mov	BYTE [rdi + rcx], bl 		; Move a byte at location rsi, into address of rdi + rcx (counter).
	movzx	rbx, BYTE [rsi + rcx + 1]	; Move the next byte into the register holding single bytes of data.
	dec	rdx				; Decrement rdx (3rd param indicating how many bytes to cpy).
	jmp	loop

end:
	mov	rax, rdi

	ret
