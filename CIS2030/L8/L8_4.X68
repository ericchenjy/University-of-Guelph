  	ORG	$8000

START:
	MOVE.W	#X,A1
	MOVE.W	Y,-(SP)
	MOVE.W	Z,-(SP)
	BSR	SolveQuad
	LEA	6(SP),SP
	TRAP	#14
	
SolveQuad	
	MOVEM.W 	(SP)+, D0-D2
	MOVE.W	14(SP),D0
	MOVE.W 	12(SP),D1
	MOVE.W	4(SP),D2
	
	MULS.W	D0,D1	//x*x

	MULS.W	D0,D0	//x * x

	MULS.W	#5,D0	//x * x

	MULS.W 	#4,D1	//4 * D1
	
	MULS	D2,D2	//z * z 

	SUB.W	#D1,D0

	ADD.W	D0,D2
	
	MOVEM.W	(SP)+,D0-D2
	RTS
	
	ORG	$9000
Z	DC.W	5
Y	DC.W	4
X	DC.W 	3

	END	START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
