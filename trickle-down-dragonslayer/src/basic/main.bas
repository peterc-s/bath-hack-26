REM **************************************************************************** 
REM *                      TRICKLE-DOWN DRAGONSLAYER                           *
REM *                         PETER CHAPLIN-SMITH                              *
REM *                         LOUIS LEAR-BELCHER                               *
REM *                           HEATH MITCHELL                                 *
REM **************************************************************************** 

REM PLAYER HEALTH
REM H = 4

REM INVENTORY WEAPON
REM 1 = SWORD
REM 2 = HAMMER
REM 3 = M16
REM W = 0

REM WEAPON DAMAGE
REM DIM WD(3)
REM WD(1) = 1
REM WD(2) = 2
REM WD(3) = 5
REM D = 1

REM ENEMY TYPE
REM 0 = NO ENEMY
REM 1 = PEASANT
REM 2 = BUFF PEASANT
REM 3 = KOMBINAT OGRE
REM 4 = HANS THE REDISTRIBUTOR
REM 5 = KGBEARS
REM 6 = PUTINI
REM 7 = RED DRAGON
REM E$ = ""

REM ENEMY HEALTH
REM 0 = DEAD
REM DIM EH(7)
REM EH(1) = 1 
REM EH(2) = 2
REM EH(3) = 4
REM EH(4) = 6
REM EH(5) = 10
REM EH(6) = 14
REM EH(7) = 20
REM M = 1

REM ENEMY DAMAGE
REM DIM ED(7)
REM ED(1) = 1
REM ED(2) = 1
REM ED(3) = 2
REM ED(4) = 3
REM ED(5) = 4
REM ED(6) = 4
REM ED(7) = 5
REM K = 1

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
REM H = 4
REM W = 0
REM D = 1
PRINT "YOUR NAME";
INPUT PN$
CALL -936
PRINT "ONCE UPON A TIME, IN THE LAND OF" : PRINT "WASHINGTONVILLE "; : PRINT PN$;
PRINT "," : PRINT "KING RE'GAAN'S MOST LOYAL SERVANT WAS" : PRINT "CHILLING OUT IN THE WHITE CASTLE WHEN" : PRINT "A MESSANGER DELIVERED THEM A SCROLL..."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "'BY JOVE!' "; : PRINT PN$; : PRINT " EXCLAIMED."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "'THE RED DRAGON? IN THIS ECONOMY?'"
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "YES, THE RED DRAGON WAS APPROACHING" : PRINT "THE IRON WALL WITH A MISSION TO" : PRINT "RADICALISE PEASANTS."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "'PEASANTS RIGHTS? IN THIS ECONOMY?'" : PRINT ""
FOR T = 1 TO 2000 : NEXT T
PRINT PN$; : PRINT " KNEW WHAT THEY MUST DO..." : PRINT "" : PRINT "PRESS ENTER TO CONTINUE..."
INPUT JK$
CALL -936
PRINT "THEY SET OUT ON THEIR QUEST TO" : PRINT "LIBERATE THE RED EMPIRE."
FOR T = 1 TO 2000 : NEXT T
PRINT "" : PRINT "PEGASUS FORCE ONE AWAITS TO TAKE" : PRINT "YOU TO OUR CLOSEST ALLY TO THE" : PRINT "IRON WALL: ENGLANDLAND."
FOR T = 1 TO 2000 : NEXT T
E$ = ""
GOSUB @READVERB
PRINT "END"
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
IF V$ = "USE" GOTO @READVERB_USE
PRINT "I DON'T KNOW "; : PRINT V$
GOTO @READVERB

<READVERB_ATTACK> GOSUB @READNOUN_ATTACK
RETURN

<READVERB_GOTO> PRINT "YOU GOTO"
RETURN

<READVERB_PICKUP> PRINT "YOU PICKUP"
RETURN

<READVERB_LOOK> PRINT "YOU LOOK"
RETURN

<READVERB_USE> PRINT "YOU USE"
RETURN
REM **************************************************************************** 

REM READNOUN_ATTACK
REM **************************************************************************** 
<READNOUN_ATTACK> IF E$ = "" GOTO @READNOUN_ATTACK_NOENEMY
PRINT "ATTACK "; : PRINT E$
RETURN

<READNOUN_ATTACK_NOENEMY> PRINT "THERE IS NO ENEMY"
RETURN

REM GETBIT BI BP -> BV
REM **************************************************************************** 
<GETBIT> BT = 2 ^ BP
BV = ((BI - (INT(BI / BT)) * BT) >= (2 ^ (BP - 1)))
RETURN
REM **************************************************************************** 

REM SETBIT BI BP
REM **************************************************************************** 
<SETBIT> GOSUB @GETBIT
IF BV = 0 THEN BI = BI + (2 ^ (BP - 1))
RETURN
REM **************************************************************************** 
