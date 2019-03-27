
DUART    EQU      $00C001     ;base address of 68681
SRA   	 EQU      2           ;input port register
RBA	 EQU	  6
OPR_SET  EQU      14*2        ;set bit command reg.
OPR_CLR  EQU      15*2        ;clear bit cmd. reg.

         ORG      $8000
SCAN	 LEA      #DUART,A0   ;A0 points to 68681
LOOP     MOVE.B   SRA(A0),D7  ;read input port
	 ANDI.B	  #1,D7		;RxRDy = 1
	 BEQ      LOOP
	 MOVE.B	  RBA(A0),D0

	 MOVE.B   D0,OPR_CLR(A0) ;clr. bits, set pins
         NOT.B    D0
         MOVE.B   D0,OPR_SET(A0) ;set bits, clr. pins
         NOT.B    D0             ;restore D0

	 CMPI.B	  #$71,D0
	 BNE      SCAN

         TRAP	  #14
         END      SCAN
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~8~
