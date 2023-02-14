.MODEL SMALL
.STACK 100H
.DATA

; The string to be printed
STRING DB 'This is a sample string', '$'

.CODE
MAIN PROC FAR
MOV AX,@DATA
MOV DS,AX

; call reverse function
CALL REVERSE

; load address of the string
LEA DX,STRING

; output the string
; loaded in dx
MOV AH, 09H
INT 21H

; interrupt to exit
MOV AH, 4CH
INT 21H

MAIN ENDP
REVERSE PROC
	; load the offset of
	; the string
	MOV SI, OFFSET STRING

	; count of characters of the;
	;string
	MOV CX, 0H

	LOOP1:
	; compare if this is;
	;the last character
	MOV AX, [SI]
	CMP AL, '$'
	JE LABEL1

	; else push it in the;
	;stack
	PUSH [SI]

	; increment the pointer;
	;and count
	INC SI
	INC CX

	JMP LOOP1

	LABEL1:
	; again load the starting;
	;address of the string
	MOV SI, OFFSET STRING

		LOOP2:
		;if count not equal to zero
		CMP CX,0
		JE EXIT

		; pop the top of stack
		POP DX

		; make dh, 0
		XOR DH, DH

		; put the character of the;
		;reversed string
		MOV [SI], DX

		; increment si and;
		;decrement count
		INC SI
		DEC CX

		JMP LOOP2

				
	EXIT:
	; add $ to the end of string
	MOV [SI],'$ '
	RET
		
REVERSE ENDP
END MAIN
