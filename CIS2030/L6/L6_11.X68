  	  ORG		$8000
START	  LEA		STRING1, A0
	  LEA		STRING2, A1
	  MOVE.B		$FF, D0
	  CMP		(A0)+,(A1)+
	  
	  BEQ		LOOP
	  
	  CMPI.L		 ,A1
	
	  BRA		LOOP
		
DONE	 TRAP	#14

	  ORG	$9000
LIST	  DC.B	'1','9','9','9','8','8','8','8','$D0'
	  
	  ORG	$9020
LIST2	  DC.B	'1','9','9','9','8','8','8','8','$D0'

	  END	START	
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~12~
