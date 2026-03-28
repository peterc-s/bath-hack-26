REM **************************************************************************** 
REM                        TRICKLE-DOWN DRAGONSLAYER
REM                           PETER CHAPLIN-SMITH
REM                           LOUIS LEAR-BELCHER
REM                             HEATH MITCHELL
REM **************************************************************************** 

<START> GOSUB @BORDER
<LOOP> PRINT "HELLO";
GOTO @LOOP
END

<BORDER> POKE 35,255
PRINT "########################################";
FOR I = 1 TO 22 : PRINT "#                                      #"; : NEXT I
PRINT "########################################";

REM LEFT
POKE 32,1
REM WIDTH
POKE 33,38
REM TOP
POKE 34,1
REM BOTTOM
POKE 35,23

REM CLEAR
CALL -936
HOME

RETURN
