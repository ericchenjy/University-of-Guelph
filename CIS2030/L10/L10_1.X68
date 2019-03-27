DUART	EQU	$00c001	;Base address
SRA	EQU	2	;Status Register A
TBA	EQU	6	;Transmit	buffer

	
	ORG	$8000
	LEA	TEXT,A1	;Point to A0
PRINT	MOVE.B	(A1)+,D0	;get Character
	CMP.L	#0,D0	;Checking if it is a null
	BEQ	EXIT	;if it is exit
	LEA	DUART,A0	;A0 points 68681
LOOP	MOVE.B	SRA(A0),D7	;get port A status
	ANDI.B	#4,D7	;buffer memory
	BEQ	LOOP	;no, check it again
	MOVE.B	D0,TBA(A0)	;yes; output chracter
	BRA	PRINT

EXIT	TRAP	#14

	ORG	$9000
TEXT	DC.B	'Hello world!',0
	END	PRINT
	
	
	

	
	*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
