	.arch msp430g2553
	.p2align 1,0
	.text
	
	.extern perdiod	
	.extern music 		; reference to music() function.
	.extern songT 		; keep track of music state.

jt:
	.word case_0		; jt[0]
	.word case_1		; jt[1]
	.word case_2		; ji[2]

musicS:
	cmp #4, &songT		; songT 4 doesn't borrow if songT > 3
	jhs default		; jump if songT > 3

	mov &songT, r12	
	add r12, r12		;
				; r12 = 2 * songT
	mov jt(r12), r0		; jump jt[songT]

case_0:
	mov #250, &period
	mov #1, &songT		; songT = 0
	jmp end			; break

case_1:
	mov #500, &period
	mov #2, &songT		;songT =2
	jmp end			;break

case_2:
	mov #750, &period
	mov #0, &songT		;songT = 0
	jmp end			;break

	
default:
	mov #1000, &period
	mov #1, &songT		;no break

end:
	mov &period, r12
	call #buzzer_set_period ; call function buzzer_set_period
	pop r0
	


	
