#include <conio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXLINELEN 40

/* --- Enums & Structs --- */

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

typedef struct {
  uint8_t health;
  uint8_t damage;
  char name[MAXLINELEN];
} Enemy;

typedef struct {
  uint8_t health;
  uint8_t damage;
  uint8_t weapon;
  Room room;
  char name[MAXLINELEN];
  char weapon_name[MAXLINELEN];
} Player;

/* --- Globals --- */

char input[MAXLINELEN];
Enemy enemy;
Player player;

/* --- Utility Functions --- */

void delay(unsigned int iterations) {
  volatile unsigned int i;
  for (i = 0; i < iterations; i++) {
    /* wait */
  }
}

void readline(char *instr) {
  int slen = 0;
  char c = getchar();

  while (c != '\n' && c != '\r') {
    if (isalpha(c) || isspace(c)) {
      if (slen < MAXLINELEN - 1) {
        instr[slen++] = toupper(c);
      }
    }
    c = getchar();
  }
  instr[slen] = '\0';
}

void spawn_enemy(uint8_t type) {
  switch (type) {
  case 0:
    enemy.health = 0;
    break;
  case 1:
    enemy.health = 1;
    enemy.damage = 1;
    strcpy(enemy.name, "PEASANT");
    break;
  case 2:
    enemy.health = 2;
    enemy.damage = 1;
    strcpy(enemy.name, "BUFF PEASANT");
    break;
  case 3:
    enemy.health = 4;
    enemy.damage = 2;
    strcpy(enemy.name, "KOMBINAT OGRE");
    break;
  case 4:
    enemy.health = 6;
    enemy.damage = 3;
    strcpy(enemy.name, "HANS THE REDISTRIBUTOR");
    break;
  case 5:
    enemy.health = 10;
    enemy.damage = 4;
    strcpy(enemy.name, "KGBEARS");
    break;
  case 6:
    enemy.health = 14;
    enemy.damage = 4;
    strcpy(enemy.name, "PUTINI");
    break;
  case 7:
    enemy.health = 20;
    enemy.damage = 5;
    strcpy(enemy.name, "THE RED DRAGON");
    break;
  }
}

/* --- Game Logic --- */

void init_player(void) {
  player.health = 4;
  player.damage = 1;
  player.room = ROOM_WHITE_CASTLE;
  player.weapon = WEAPON_SWORD;
  strcpy(player.weapon_name, "SWORD");
  spawn_enemy(0);
}

void do_attack(char *noun) {
  printf("%s", noun);
  if (enemy.health == 0) {
    printf("\nTHERE IS NOTHING TO ATTACK HERE.");
    return;
  }

  printf("\nYOU SWING YOUR %s AT THE %s!", player.weapon_name, enemy.name);

  if (enemy.health <= player.damage) {
    enemy.health = 0;
    printf("\nYOU DEFEATED THE %s!", enemy.name);
  } else {
    enemy.health -= player.damage;
    printf("\nTHE %s ATTACKS YOU FOR %d DAMAGE!", enemy.name, enemy.damage);
    if (player.health <= enemy.damage) {
      player.health = 0;
      printf("\nYOU HAVE FALLEN TO THE RED MENACE...\nGAME OVER.");
    } else {
      player.health -= enemy.damage;
      printf("\nYOU HAVE %d HEALTH LEFT.", player.health);
    }
  }
}

void do_look(char *noun) {
  if (noun == NULL || strcmp(noun, "AROUND") != 0) {
    printf("\nLOOK AT WHAT? (TRY 'LOOK AROUND')");
    return;
  }

  switch (player.room) {
  case ROOM_WHITE_CASTLE:
    printf("\nA CHEERY JESTER NAMED RUMPLE MCDUMPLE IS\nHANDING OUT "
           "CHEESEBURGERS.");
    break;
  case ROOM_OUTSKIRTS_LONDIS:
    printf(
        "\nYOU SEE A DISCARDED FULL CAN OF SPAM\nIN A FULL SHOPPING BASKET.");
    break;
  case ROOM_JOHNNY_FARM:
    printf("\nA PEASANT IS IN THE FIELDS BRUTALLY\nATTACKING THE GROUND WITH A "
           "PITCHFORK.\nTHIS WILL NOT STAND!");
    break;
  case ROOM_JOHNNY_FARMHOUSE:
    printf("\nA STEW HAS BEEN LEFT ON THE AGA. LETTERS\nDETAILING QUOTAS ARE "
           "STREWN AROUND. A\nHAMMER LIES BY THE DOOR.");
    break;
  case ROOM_FERRY_PIER:
    printf("\nTHE FERRYMAN WAVES AND TELLS YOU THE\nTOLL IS 5 MONIES. THE BOAT "
           "LIES TO THE\nNORTH.");
    break;
  case ROOM_BEACH:
    printf("\nTHE WAVES HAVE SEEMED TO HAVE WASHED AN\nALMOST UNTOUCHED CAN OF "
           "CURRYWURST\nASHORE.");
    break;
  case ROOM_CAR_FACTORY:
    printf("\nTHE FACTORY IS COMPLETELY EMPTY. YOU\nWONDER IF ANYONE EVER GETS "
           "A CAR.");
    if (enemy.health > 0) {
      printf("\nAN OGRE JUMPS OUT AT YOU!");
    }
    break;
  case ROOM_MERLIN_WALL:
    printf("\nYOU SEE AN UNATTENDED M16 LEANING\nAGAINST THE WALL.");
    break;
  case ROOM_IRON_WALL:
    printf("\nTURNS OUT THE IRON WALL WAS NOT A REAL\nWALL BUT JUST SOMETHING "
           "PEOPLE SAID.\nNORTH IS THE ROAD TO MT GREMLIN.");
    break;
  case ROOM_MOUNT_GREMLIN:
    printf("\nTHE LAIR OF THE RED DRAGON.");
    break;
  }
}

void do_goto(char *noun) {
  Room next_room = player.room;
  uint8_t moved = 0;

  if (noun == NULL) {
    printf("\nGO WHERE? (NORTH, SOUTH, EAST, WEST)");
    return;
  }

  switch (player.room) {
  case ROOM_WHITE_CASTLE:
    if (strcmp(noun, "EAST") == 0) {
      printf("\nYOU RIDE A FLYING PIG TO LONDIS!");
      next_room = ROOM_OUTSKIRTS_LONDIS;
      moved = 1;
    }
    break;

  case ROOM_OUTSKIRTS_LONDIS:
    if (strcmp(noun, "NORTH") == 0) {
      next_room = ROOM_JOHNNY_FARM;
      moved = 1;
    } else if (strcmp(noun, "WEST") == 0) {
      next_room = ROOM_WHITE_CASTLE;
      moved = 1;
    }
    break;

  case ROOM_JOHNNY_FARM:
    if (strcmp(noun, "EAST") == 0) {
      next_room = ROOM_JOHNNY_FARMHOUSE;
      moved = 1;
    } else if (strcmp(noun, "NORTH") == 0) {
      next_room = ROOM_FERRY_PIER;
      moved = 1;
    } else if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_OUTSKIRTS_LONDIS;
      moved = 1;
    }
    break;

  case ROOM_JOHNNY_FARMHOUSE:
    if (strcmp(noun, "WEST") == 0) {
      next_room = ROOM_JOHNNY_FARM;
      moved = 1;
    }
    break;

  case ROOM_FERRY_PIER:
    if (strcmp(noun, "NORTH") == 0) {
      printf("\nTHE BOAT TAKES YOU ACROSS THE WATER.");
      next_room = ROOM_BEACH;
      moved = 1;
    } else if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_JOHNNY_FARM;
      moved = 1;
    }
    break;

  case ROOM_BEACH:
    if (strcmp(noun, "NORTH") == 0) {
      next_room = ROOM_CAR_FACTORY;
      moved = 1;
    } else if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_FERRY_PIER;
      moved = 1;
    }
    break;

  case ROOM_CAR_FACTORY:
    if (strcmp(noun, "WEST") == 0) {
      next_room = ROOM_MERLIN_WALL;
      moved = 1;
    } else if (strcmp(noun, "EAST") == 0) {
      next_room = ROOM_IRON_WALL;
      moved = 1;
    } else if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_BEACH;
      moved = 1;
    }
    break;

  case ROOM_MERLIN_WALL:
    if (strcmp(noun, "EAST") == 0) {
      next_room = ROOM_CAR_FACTORY;
      moved = 1;
    }
    break;

  case ROOM_IRON_WALL:
    if (strcmp(noun, "NORTH") == 0) {
      next_room = ROOM_MOUNT_GREMLIN;
      moved = 1;
    } else if (strcmp(noun, "WEST") == 0) {
      next_room = ROOM_CAR_FACTORY;
      moved = 1;
    }
    break;

  case ROOM_MOUNT_GREMLIN:
    if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_IRON_WALL;
      moved = 1;
    }
    break;
  }

  if (moved) {
    player.room = next_room;
    spawn_enemy(0);
    printf("\nYOU ARRIVE AT YOUR DESTINATION.");
  } else {
    printf("\nTHAT WOULD BE SILLY.");
  }
}

void do_pickup(char *noun) {
  if (noun != NULL)
    printf("\nYOU PICKED UP THE %s.", noun);
  else
    printf("\nPICK UP WHAT?");
}

void do_use(char *noun) {
  if (noun != NULL)
    printf("\nYOU USED THE %s.", noun);
  else
    printf("\nUSE WHAT?");
}

/* --- Commands --- */
typedef struct {
  const char *verb;
  void (*action)(char *noun);
} Command;

#define NUM_VERBS 5
const Command commands[NUM_VERBS] = {{"ATTACK", do_attack},
                                     {"GOTO", do_goto},
                                     {"PICKUP", do_pickup},
                                     {"LOOK", do_look},
                                     {"USE", do_use}};

/* --- Main stuff --- */

void intro(void) {
  clrscr();
  printf("        \\(______      ______)/\n");
  printf("        /`.----.\\    /.----.`\\\n");
  printf("       } /      :} {:       \\ {\n");
  printf("      / {        } {        } \\\n");
  printf("      } }      ) } { (      { {\n");
  printf("     / {      /|\\}!{/|\\      } \\\n");
  printf("     } }     ( (.\"^\".) )     { {\n");
  printf("    / {       (d\\   /b)       } \\\n");
  printf("    } }        |\\~  ~/|       { {\n");
  printf("   / /         | )   ( |        \\ \\\n");
  printf("  { {         _)(,   ,)(_        } }\n");
  printf("   } }       //  `\";\"`  \\\\      { {\n");
  printf("  / /       //     (     \\\\      \\ \\\n");
  printf(" { {       {(     -=)     )}      } }\n");
  printf("  \\ \\      /)   -=(=-      (\\    / /\n");
  printf("   `\\\\  /'/    /-=|\\-\\    \\`\\  //'\n");
  printf("     `\\{  |   ( -===- )   |  }/'\n");
  printf("       `  _\\   \\-===-/   /_  '\n");
  printf("         (_(_(_)'-=-'(_)_)_)\n");
  printf("         `\"`\"`\"        \"`\"`\"`\n");
  printf("      TRICKLE-DOWN DRAGONSLAYER\n");

  delay(30000);

  printf("YOUR NAME? ");
  readline(input);
  strcpy(player.name, input);
  clrscr();

  printf("ONCE UPON A TIME, IN THE LAND OF\n"
         "WASHINGTONVILLE, %s, KING RE'GAAN'S\n"
         "MOST LOYAL SERVANT WAS CHILLING OUT\n"
         "IN THE WHITE CASTLE WHEN A MESSENGER\n"
         "DELIVERED THEM A SCROLL...\n",
         player.name);
  delay(30000);

  printf("\n'BY JOVE!' %s EXCLAIMED.\n", player.name);
  delay(30000);

  printf("\n'THE RED DRAGON? IN THIS ECONOMY?'\n");
  delay(30000);

  printf("\nYES, THE RED DRAGON WAS APPROACHING\n"
         "THE IRON WALL WITH A MISSION TO\n"
         "RADICALISE PEASANTS.\n");
  delay(30000);

  printf("\n'PEASANTS RIGHTS? IN THIS ECONOMY?'\n");
  delay(30000);

  printf("\n%s KNEW WHAT THEY MUST DO...\n\n"
         "PRESS ENTER TO CONTINUE...",
         player.name);
  cgetc();
}

void prompt_action(void) {
  char *verb_part;
  char *noun_part;
  uint8_t i;
  uint8_t found;

  while (1) {
    found = 0;
    printf("\n\nWHAT WILL YOU DO? ");
    readline(input);

    verb_part = input;
    noun_part = strchr(input, ' ');

    if (noun_part != NULL) {
      *noun_part = '\0';
      noun_part++;
    }

    for (i = 0; i < NUM_VERBS; ++i) {
      if (strcmp(verb_part, commands[i].verb) == 0) {
        commands[i].action(noun_part);
        found = 1;
        break;
      }
    }

    if (!found && strlen(verb_part) > 0) {
      printf("\nI DON'T UNDERSTAND '%s'.", verb_part);
    }
  }
}

int main(void) {
  init_player();
  intro();
  prompt_action();
  return 0;
}
