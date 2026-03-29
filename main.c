#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short word;

#define MAXLINELEN 40

typedef enum {
  WEAPON_SWORD,
  WEAPON_HAMMER,
  WEAPON_GUN,
} Weapon;

typedef struct {
  byte health;
  byte damage;
  char name[MAXLINELEN];
} Enemy;

typedef struct {
  byte health;
  byte damage;
  byte weapon;
  char name[MAXLINELEN];
  char weapon_name[MAXLINELEN];
} Player;

char input[MAXLINELEN];
Enemy enemy;
Player player;

void delay(unsigned int iterations) {
  unsigned int i;
  for (i = 0; i < iterations; i++) {
  }
}

void readline(char *instr) {
  char c;
  int slen = 0;

  c = getchar();
  while (c != '\n') {
    if (isalpha(c) || isspace(c))
      instr[slen++] = toupper(c);
    if (slen > MAXLINELEN - 1) {
      printf("Exceeded Max Line Length\n");
    }
    c = getchar();
  }
  instr[slen] = '\0';
}

void init_player() {
  player.health = 4;
  player.damage = 1;
  player.weapon = WEAPON_SWORD;
  strcpy(player.weapon_name, "SWORD");
}

void intro() {
  printf("       \\(______     ______)/\n");
  printf("       /`.----.\\   /.----.`\\\n");
  printf("      } /      :} {:      \\ {\n");
  printf("     / {        } {        } \\\n");
  printf("     } }      ) } { (      { {\n");
  printf("    / {      /|\\}!{/|\\      } \\\n");
  printf("    } }     ( (.\"^\".) )     { {\n");
  printf("   / {       (d\\   /b)       } \\\n");
  printf("   } }       |\\~   ~/|       { {\n");
  printf("  / /        | )   ( |        \\ \\\n");
  printf(" { {        _)(,   ,)(_        } }\n");
  printf("  } }      //  `\";\"`  \\\\      { {\n");
  printf(" / /      //     (     \\\\      \\ \\\n");
  printf("{ {      {(     -=)     )}      } }\n");
  printf(" \\ \\     /)    -=(=-     (\\    / /\n");
  printf("  `\\\\  /'/    /-=|\\-\\    \\`\\  //'\n");
  printf("    `\\{  |   ( -===- )   |  }/'\n");
  printf("      `  _\\   \\-===-/   /_  '\n");
  printf("        (_(_(_)'-=-'(_)_)_)\n");
  printf("        `\"`\"`\"       \"`\"`\"`\n");
  printf("     TRICKLE-DOWN DRAGONSLAYER\n");
  delay(30000);
  printf("YOUR NAME? ");
  readline(input);
  strcpy(player.name, input);
  clrscr();
  printf("ONCE UPON A TIME, IN THE LAND OF\nWASHINGTONVILLE, %s, KING "
         "RE'GAAN'S MOST LOYAL SERVANT WAS\nCHILLING OUT IN THE WHITE CASTLE "
         "WHEN\nA MESSENGER DELIVERED THEM A SCROLL...\n",
         player.name);
  delay(30000);
  printf("\n'BY JOVE!' %s EXCLAIMED.\n", player.name);
  delay(30000);
  printf("\n'THE RED DRAGON? IN THIS ECONOMY?'\n");
  delay(30000);
  printf("\nYES, THE RED DRAGON WAS APPROACHING\nTHE IRON WALL WITH A MISSION "
         "TO\nRADICALISE PEASANTS.\n");
  delay(30000);
  printf("\n'PEASANTS RIGHTS? IN THIS ECONOMY?'\n");
  delay(30000);
  printf("\n%s KNEW WHAT THEY MUST DO...\n\nPRESS ENTER TO CONTINUE...",
         player.name);
  cgetc();
}

int main(void) {
  init_player();
  intro();
  printf("%s", player.name);
  return 0;
}
