  	ORG	$8000
START	MOVE.W	X,-(SP)
	
	JSR	SolveQuad
	LEA	4(SP),SP
	TRAP	#14
	
SolveQuad	MOVE.W	4(SP),D0
	MOVE.W 	4(SP),D1

	MULS.W	D1,D1
	MULS.W	#5,D1

	MULS.W	#2,D0
	SUB.W	D0,D1

	ADDI.W	#6,D1
	RTS
	
	ORG	$9000
X	DC.W	5

	END	START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
