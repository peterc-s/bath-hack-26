REM **************************************************************************** 
REM *                      TRICKLE-DOWN DRAGONSLAYER                           *
REM *                         PETER CHAPLIN-SMITH                              *
REM *                         LOUIS LEAR-BELCHER                               *
REM *                           HEATH MITCHELL                                 *
REM **************************************************************************** 

REM MAIN
REM **************************************************************************** 
CALL -936
PRINT "        |(______     ______)|"
PRINT "        |`.----.|   |.----.`|"
PRINT "       } |      :} {:      | {"
PRINT "      | {        } {        } |"
PRINT "      } }      ) } { (      { {"
PRINT "     | {      |||}!{|||      } |"
PRINT "     } }     ( (.'^'.) )     { {"
PRINT "    | {       (d|   |b)       } |"
PRINT "    } }       ||~   ~||       { {"
PRINT "   | |        | |   | |        | |"
PRINT "  { {        _)(.   .)(_        } }"
PRINT "   } }      ||  `';'`  ||      { {"
PRINT "  | |      ||     (     ||      | |"
PRINT " { {      {(     -=)     )}      } }"
PRINT "  | |     |)    -=(=-     (|    | |"
PRINT "   `||  |'|    |-=||-|    |`|  ||'"
PRINT "     `|{  |   ( -===- )   |  }|'"
PRINT "       `  _|   |-===-|   |_  '"
PRINT "         (_(_(_)'-=-'(_)_)_)"
PRINT "         `'`'`'       '`'`'`"
PRINT "      TRICKLE-DOWN DRAGONSLAYER"
PRINT "YOUR NAME";
INPUT PLAYERNAME$
CALL -936
PRINT "ONCE UPON A TIME, IN THE LAND OF" : PRINT "WASHINGTONVILLE "; : PRINT PLAYERNAME$;
PRINT "," : PRINT "KING RE'GAAN'S MOST LOYAL SERVANT WAS" : PRINT "CHILLING OUT IN THE WHITE CASTLE WHEN" : PRINT "A MESSANGER DELIVERED THEM A SCROLL..."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "'BY JOVE!' "; : PRINT PLAYERNAME$; : PRINT " EXCLAIMED."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "'THE RED DRAGON? IN THIS ECONOMY?'"
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "YES, THE RED DRAGON WAS APPROACHING" : PRINT "THE IRON WALL WITH A MISSION TO" : PRINT "RADICALISE PEASANTS."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "'PEASANTS RIGHTS? IN THIS ECONOMY?'" : PRINT ""
FOR T = 1 TO 2000 : NEXT T
PRINT PLAYERNAME$; : PRINT " KNEW WHAT THEY MUST DO..." : PRINT "" : PRINT "PRESS ENTER TO CONTINUE..."
INPUT JK$
CALL -936
PRINT "THEY SET OUT ON THEIR QUEST TO" : PRINT "LIBERATE THE RED EMPIRE."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "PEGASUS FORCE ONE AWAITS TO TAKE" : PRINT "YOU TO OUR CLOSEST ALLY TO THE" : PRINT "IRON WALL: ENGLANDLAND."
FOR T = 1 TO 2000 : NEXT T
GOSUB @READVERB
END
REM **************************************************************************** 

REM READVERB
REM **************************************************************************** 
<READVERB> PRINT "WHAT DO YOU DO";
INPUT V$
IF V$ = "ATTACK" GOTO @READVERB_ATTACK
IF V$ = "GOTO" GOTO @READVERB_GOTO
IF V$ = "PICKUP" GOTO @READVERB_PICKUP
IF V$ = "LOOK" GOTO @READVERB_LOOK
PRINT "I DON'T KNOW "; : PRINT V$
GOTO @READVERB

<READVERB_ATTACK> PRINT "YOU ATTACK"
RETURN

<READVERB_GOTO> PRINT "YOU GOTO"
RETURN

<READVERB_PICKUP> PRINT "YOU PICKUP"
RETURN

<READVERB_LOOK> PRINT "YOU LOOK"
RETURN
REM **************************************************************************** 
