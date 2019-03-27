	ORG	$8024
	
START	
	
LOOP	MOVEA.L	(A1)+,D0	
	COMPI.B	#60,D0
	BLE	EXIT
	
	COMPI.B	#20, D0
	BLE	EXIT

	SUB.B 	#20, D0
	MOVEA.L	D0, A1

	BRA	LOOP
	EXIT	TRAP #14
	

	ORG	$9000

MESSAGE	DC.B	'Assembly Language Programming is Fun!',0

	END	START
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
