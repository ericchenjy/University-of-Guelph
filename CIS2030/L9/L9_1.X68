	ORG	$8000
START 	TRAP #5
	TRAP #14

	ORG	$8024
	JMP	TRAPS

	ORG	$9000
TRAPS	MOVEA.L	#MESSAGE,A0	//Make the mesage point to A0
	
LOOP	MOVE.L	(A0)+,D0
	CMPI.B	#$0,D0	//Checking if it is a null character
	BEQ	EXIT
	
	CMPI.B	#$60,D0	//Checking if it is a lowerCase
	BLT	UPPERCASE
	


BACK	SUB.B 	#$20,D0	//If it is, minus 20 concert it to a upp case
	BRA	NEXT

UPPERCASE	CMPI.B 	#$40,D0
	BGT	BACK	
	
NEXT	TRAP #1
	BRA 	LOOP

EXIT	TRAP #1
	RTE


	ORG	$A000

MESSAGE	DC.B	'Assembly Language Programming is Fun!',0

	END	START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
