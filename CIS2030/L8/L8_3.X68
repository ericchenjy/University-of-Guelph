  	ORG	$8000

START:
	MOVE.W	X,-(SP)
	MOVE.W	Y,-(SP)
	MOVE.W	Z,-(SP)
	JSR	SolveQuad
	LEA	6(SP),SP
	TRAP	#14
	
SolveQuad	MOVEM.W 	D0-D2/-(SP)
	MOVE.W	14(SP),D0
	MOVE.W 	12(SP),D1
	MOVE.W	10(SP),D2

	
	MULS.W	D0,D1	//x * y

	MULS.W	D0,D0	//x * x
	MULS.W	#5,D0	//5 * x


	MULS.W 	#2,D1	//2 * y = y
	
	SUB.W	D1,D0	//x - y = x
	
	MULS	D2,D2	//z * z 

	ADD.W	D2,D0	//x + z
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
