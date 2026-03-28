REM **************************************************************************** 
REM                        TRICKLE-DOWN DRAGONSLAYER
REM                           PETER CHAPLIN-SMITH
REM                           LOUIS LEAR-BELCHER
REM                             HEATH MITCHELL
REM **************************************************************************** 

REM MAIN
REM **************************************************************************** 
<MAIN> GOSUB @BORDER
PRINT "        \(______     ______)/"
PRINT "        /`.----.\   /.----.`\"
PRINT "       } /      :} {:      \ {"
PRINT "      / {        } {        } \"
PRINT "      } }      ) } { (      { {"
PRINT "     / {      /|\}!{/|\      } \"
PRINT "     } }     ( (.'^'.) )     { {"
PRINT "    / {       (d\   /b)       } \"
PRINT "    } }       |\~   ~/|       { {"
PRINT "   / /        | )   ( |        \ \"
PRINT "  { {        _)(,   ,)(_        } }"
PRINT "   } }      //  `';'`  \\      { {"
PRINT "  / /      //     (     \\      \ \"
PRINT " { {      {(     -=)     )}      } }"
PRINT "  \ \     /)    -=(=-     (\    / /"
PRINT "   `\\  /'/    /-=|\-\    \`\  //'"
PRINT "     `\{  |   ( -===- )   |  }/'"
PRINT "       `  _\   \-===-/   /_  '"
PRINT "         (_(_(_)'-=-'(_)_)_)"
PRINT "         `'`'`'       '`'`'`"
PRINT "      TRICKLE-DOWN DRAGONSLAYER"
FOR WAIT = 1 TO 2500 : NEXT WAIT
CALL -936
PRINT "TEST"
END
REM **************************************************************************** 

REM BORDER
REM **************************************************************************** 
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
RETURN
REM **************************************************************************** 
