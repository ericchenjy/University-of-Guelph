  	ORG	$8000
START	MOVE.W	NUM1,D0
	MOVE.W	NUM2,D1
	BTST	#0,D1	//Check if D1 is odd
	BNE	ODDNUMBER

LOOP	LSL	#1,D0	//Logical shifting to the left
	LSR	#1,D1	//Logical shifting to the right
	
	CMPI.W	#1,D1	
	BLE	DONE	

	BTST	#0,D1	//Check if D1 is odd
	BNE	ODDNUMBER
	BRA	LOOP

ODDNUMBER	ADD.W	D0,D2
	BRA	LOOP

DONE	ADD.W	D0,D2
	TRAP	#14

	ORG	$9000
NUM1	DC.W	$1E
NUM2	DC.W	$19

	END	START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
