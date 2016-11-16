; Ashley Nguyen - apn2my
; PreLab09 - threexplusone.s
; 4/10/16

; Optimizations made:
; Instead of pushing esi onto the stack, just used within subroutine since value will ultimately not need to be preserved.
; Shortened epilogue with leave command.
; Did not include xEven subroutine because threexplusone subroutine figures out whether input is even with idiv and cmp edx,1
; Use of LEA command reduced number of mov lines needed.
; For the lea line, breaking up the multiplication function into 3 adds (eax+eax+eax) improved running time.
; I was unsuccessful in condensing the prologue and epilogue due to the many mov commands I ended up having in my function.
; Utilization of the xor command to set registers to 0 seemed to improve running time by performing a simple boolean function   rather than moving or arithmetically modifying the registers. 

	global threexplusone
	section .text
	
threexplusone:
	push ebp		;Store old base pointer
	mov  ebp, esp		;Set stack ptr to be at base ptr's location

	mov eax, [ebp + 8]	;Moving input to result register
	mov ecx, eax		;Making a copy of eax register to ecx to use for equation
	cmp eax, 1 		;if input = 1, then done since divided enough times, reset eax and continue to epilogue 
	je  reset

	xor edx, edx  		;Sets EDX = 0 (remainder holding register)
	mov esi, 2		;Store value of 2 in esi
	cdq
	idiv esi		;divides eax by 2 to determine if odd or even
	cmp edx, 1		;remainder stored in EDX, if 1 then input is odd
	je  xOdd		;jump equals if EDX holds 1 (odd #)
	jmp loop		;else, must be even perform recursive looop
xOdd:
	mov eax, ecx		;Restore copy of eax
	lea eax, [eax+eax+eax+1];x is odd, so perform operation
	jmp loop		;continue to loop to determine if resulting calculations are either even or odd 
loop:
	push eax		;push the current value in eax
	call threexplusone	;recursively call subroutine
	add eax, 1		;counts # steps taken to reach input value 1 (steps++)
	jmp done		;jump to epilogue
reset:
	xor eax, eax		;resetting eax's register to 0 once it has hit 1 to terminate step count
	jmp done		;perform epilogue
done:
	leave			;condensed command of mov ebp,esp and pop ebp
	ret			;return value in eax register 
	
	
