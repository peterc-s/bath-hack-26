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

typedef enum {
  ROOM_WHITE_CASTLE,
  ROOM_OUTSKIRTS_LONDIS,
  ROOM_JOHNNY_FARM,
  ROOM_JOHNNY_FARMHOUSE,
  ROOM_FERRY_PIER,
  ROOM_BEACH,
  ROOM_CAR_FACTORY,
  ROOM_MERLIN_WALL,
  ROOM_IRON_WALL,
  ROOM_MOUNT_GREMLIN,
} Room;

#define NUM_VERBS 5
const char *VERBS[] = {"ATTACK", "GOTO", "PICKUP", "LOOK", "USE"};

typedef struct {
  byte health;
  byte damage;
  char name[MAXLINELEN];
} Enemy;

typedef struct {
  byte health;
  byte damage;
  byte weapon;
  Room room;
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
  player.room = ROOM_WHITE_CASTLE;
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

void do_attack(void) { printf("\nYOU SWING YOUR %s!", player.weapon_name); }
void do_goto(void) { printf("\nWHERE TO?"); }
void do_pickup(void) { printf("\nYOU PICKED IT UP."); }
void do_look(void) { printf("\nYOU SEE NOTHING BUT DEBT."); }
void do_use(void) { printf("\nYOU USED IT."); }

void (*verb_functions[])(void) = {do_attack, do_goto, do_pickup, do_look,
                                  do_use};

void prompt_action() {
  char *verb_part;
  char *noun_part;
  byte i;
  int found = 0;

  while (!found) {
    printf("\n\nWHAT WILL YOU DO? ");
    readline(input);

    verb_part = input;
    noun_part = strchr(input, ' ');
    if (noun_part != NULL) {
      *noun_part = '\0'; // Terminate the verb string at the space
      noun_part++;       // Move pointer to the start of the noun
    }
    for (i = 0; i < NUM_VERBS; ++i) {
      if (strcmp(verb_part, VERBS[i]) == 0) {
        verb_functions[i](); // Call the corresponding function
        found = 1;
        break;
      }
    }
    if (!found) {
      printf("\nI DON'T UNDERSTAND '%s'.", verb_part);
    }
  }
}

int main(void) {
  init_player();
  intro();
  prompt_action();
  cgetc();
  return 0;
}
