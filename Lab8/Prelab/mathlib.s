;  Ashley Nguyen - apn2my
;  PreLab08 - mathlib.s
;  3/28/16
;  product multiplies two integer inputs
;  power raises first input to power of second input

	global product
	global power
	section .text

product:
	; Standard prologue
	push 	ebp		; Save original base pointer
	mov 	ebp, esp	; Set new value of ebp to esp
	push 	edi		; Save edi

	; Procedure Body
	xor 	eax, eax	; Setting eax to 0
	mov	edi, [ebp + 8]	; edi <- x
	mov	edx, [ebp + 12]	; ecx <- n (number times to add to x)

product_loop:
	; Iterative loop to add to x
	cmp	edx, 0		; n==0?
	jle	product_done	; jmp to done if n is less than or equal to 0
	add	eax, edi	; add input x to eax (sum)
	dec	edx		; n-- (reverse order push to stack)
	jmp	product_loop	; iterate thru loop again until finished

product_done:
	; Standard epilogue
	pop 	edi		; Restore callee registers, top element
	mov	esp, ebp	; Deallocating memory from ebp back to esp
	pop	ebp		; Return caller's base ptr
	ret

power:
	; Standard prologue
	push 	ebp		; Save base ptr
	mov 	ebp, esp	; Set value of esp to ebp
	push	esi		; Save registers (esi may already be in use)

	; Procedure body
	mov	esi, [ebp + 8]	; edi <- b (base)
	mov	ecx, [ebp + 12]	; ecx <- p (power)
	xor	eax, eax	; initializing result to 0
	cmp	ecx, 0		; if power > 0 conditional
	jg	rec		; jump greater: else jump to recursive function
	mov	eax, 1		; Result base case = 1
	jmp	power_done	; jump to done

rec:
	; Recursive Body Function
	dec	ecx		; power--
	push	ecx		; push that new decremented value
	push	esi		; base value
	call	power		; recursive call to power, reinput new decremented value
	pop	ecx		; clears previous power value after calling
	push	eax		; push calculated total to result
	push	esi		; Call base again
	call	product 	; Multiply

power_done:
	; Standard epilogue
	pop 	esi		; Restore callee registers
	mov	esp, ebp	; Deallocates by mov(esp, ebp) and pop ebp
	pop	ebp		; Returns base pointer value 
	ret
