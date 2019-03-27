DUART	EQU	$00C001	;Base Address
SRA	EQU	2	;Status Register A
RBA	EQU	6	;Transmit buffer


	ORG	$8000
START	MOVEA.L	#STRING,A1
	JSR	SCAN
	TRAP	#15
SCAN
		
	LEA	DUART,A0	;Point to A0
LOOP	MOVE.B	SRA(A0),D7	;read status reg A
	ANDI.B	#1,D7	;RxRDY = 1
	BEQ	LOOP	;no: check again
	CMPI.B	#0,(A1)
	BEQ	EXIT
	MOVE.B	RBA(A0),(A1)+
	BRA	LOOP
EXIT	RTS
	

	ORG	$9000
STRING	DS.B	16
	DC.B        0
	
	END	START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
