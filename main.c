#include <conio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAXLINELEN 40
#define INVSIZE 5
#define HELL_YEAH 1

/* --- Enums & Structs --- */

typedef enum {
  ITEM_NONE,
  ITEM_HAMMER,
  ITEM_M16,
  ITEM_CHEESEBURGER,
  ITEM_SPAM,
  ITEM_CURRYWURST,
  ITEM_BEEF_STROGANOV,
} ItemType;

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
  ROOM_MT_GREMLIN_BASE,
  ROOM_MT_GREMLIN_PEAK,
} Room;

typedef struct {
  uint8_t health;
  uint8_t damage;
  char name[MAXLINELEN];
} Enemy;

typedef struct {
  uint8_t health;
  uint8_t damage;
  Room room;
  char name[MAXLINELEN];
  char weapon_name[MAXLINELEN];
  ItemType inventory[INVSIZE];
} Player;

/* --- Globals --- */

char input[MAXLINELEN];
Enemy enemy;
Player player;
uint8_t room_cleared[12];
ItemType room_item[12];
uint8_t freedom = 0;

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
    if (isalpha(c) || isspace(c) || isdigit(c)) {
      if (slen < MAXLINELEN - 1) {
        instr[slen++] = toupper(c);
      }
    }
    c = getchar();
  }
  instr[slen] = '\0';
}

const char *item_name(ItemType type) {
  switch (type) {
  case ITEM_HAMMER:
    return "HAMMER";
  case ITEM_M16:
    return "M16";
  case ITEM_CHEESEBURGER:
    return "CHEESEBURGER";
  case ITEM_SPAM:
    return "SPAM";
  case ITEM_CURRYWURST:
    return "CURRYWURST";
  case ITEM_BEEF_STROGANOV:
    return "BEEF STROGANOV";
  default:
    return "NONE";
  }
}

void add_to_inventory(ItemType item) {
  int i;
  for (i = 0; i < INVSIZE; i++) {
    if (player.inventory[i] == ITEM_NONE) {
      player.inventory[i] = item;
      printf("\n%s ADDED TO INVENTORY.", item_name(item));
      return;
    }
  }
  printf("\nINVENTORY FULL!");
}

void show_stats(void) {
  printf("\n\n--- %s: %d HP | WEAPON: %s ---", player.name, player.health,
         player.weapon_name);
  if (enemy.health > 0) {
    printf("\n--- ENEMY %s: %d HP ---", enemy.name, enemy.health);
  }
}

void describe_encounter(void) {
  printf("\n");
  switch (player.room) {
  case ROOM_OUTSKIRTS_LONDIS:
    printf("A DISGRUNTLED PEASANT BRANDISHES A\nPROTEST SIGN AT YOU!\n'WHAT "
           "UTTER MADNESS' YOU THINK\nTO YOURSELF.");
    break;
  case ROOM_JOHNNY_FARM:
    printf("JOHNNY THE FARMER DROPS HIS\nPITCHFORK AND PULLS A SICKLE!\nHE "
           "LOOKS BUFF.\nBUT CLEARLY NOT AS CHISELED AS YOU.\n");
    break;
  case ROOM_CAR_FACTORY:
    printf("A MASSIVE GREEN OGRE IN RED OVERALLS\nSTEPS OUT FROM THE ASSEMBLY "
           "LINE!");
    break;
  case ROOM_MERLIN_WALL:
    printf("HANS THE REDISTRIBUTOR STEPS OUT,\nTRYING TO DIVIDE YOUR HEALTH\n"
           "BAR EQUALLY WITH THE ROOM!");
    break;
  case ROOM_IRON_WALL:
    printf("LITERAL BEARS, YES: BEARS,\nIN USHANKAS APPEAR!\nTHEY SEEM TO "
           "KNOW YOUR LAST NAME.");
    break;
  case ROOM_MT_GREMLIN_BASE:
    printf(
        "A SMALL MAN ON A LARGE HORSE\nRIDES OUT. HE IS STRANGELY\nSHIRTLESS. "
        "HIS BALD HEAD BLINDING\nYOU WITH THE SUN'S REFLECTION.");
    break;
  case ROOM_MT_GREMLIN_PEAK:
    printf("THE RED DRAGON RESTS PEACEFULLY ATOP\nMOUNT GREMLIN. CLEARLY TIRED "
           "FROM\nSCHEMING. IT SLOWLY OPENS ITS DEEP\nRED EYES.\nTHE RED "
           "DRAGON LETS OUT A ROAR THAT\nSOUNDS LIKE CENTRAL PLANNING!\n");
    break;
  default:
    break;
  }
}

void spawn_enemy(uint8_t type) {
  switch (type) {
  case 0:
    enemy.health = 0;
    break;
  case 1:
    enemy.health = 1;
    enemy.damage = 1;
    strcpy(enemy.name, "THE PEASANT");
    break;
  case 2:
    enemy.health = 2;
    enemy.damage = 1;
    strcpy(enemy.name, "JOHNNY");
    break;
  case 3:
    enemy.health = 4;
    enemy.damage = 2;
    strcpy(enemy.name, "THE KOMBINAT OGRE");
    break;
  case 4:
    enemy.health = 6;
    enemy.damage = 3;
    strcpy(enemy.name, "HANS THE REDISTRIBUTOR");
    break;
  case 5:
    enemy.health = 10;
    enemy.damage = 3;
    strcpy(enemy.name, "THE KGBEARS");
    break;
  case 6:
    enemy.health = 14;
    enemy.damage = 3;
    strcpy(enemy.name, "PUTINI");
    break;
  case 7:
    enemy.health = 16;
    enemy.damage = 5;
    strcpy(enemy.name, "THE RED DRAGON");
    break;
  }
}

void check_for_encounter(void) {
  if (room_cleared[player.room]) {
    spawn_enemy(0);
    return;
  }

  switch (player.room) {
  case ROOM_OUTSKIRTS_LONDIS:
    spawn_enemy(1);
    break;
  case ROOM_JOHNNY_FARM:
    spawn_enemy(2);
    break;
  case ROOM_CAR_FACTORY:
    spawn_enemy(3);
    break;
  case ROOM_MERLIN_WALL:
    spawn_enemy(4);
    break;
  case ROOM_IRON_WALL:
    spawn_enemy(5);
    break;
  case ROOM_MT_GREMLIN_BASE:
    spawn_enemy(6);
    break;
  case ROOM_MT_GREMLIN_PEAK:
    spawn_enemy(7);
    break;
  default:
    spawn_enemy(0);
    break;
  }

  if (enemy.health > 0) {
    describe_encounter();
  }
}

/* --- Game Logic --- */

void init_player(void) {
  int i;
  player.health = 6;
  player.damage = 1;
  player.room = ROOM_WHITE_CASTLE;
  strcpy(player.weapon_name, "SWORD");
  for (i = 0; i < INVSIZE; i++) {
    player.inventory[i] = ITEM_NONE;
  }
  for (i = 0; i < 12; i++) {
    room_cleared[i] = 0;
    room_item[i] = ITEM_NONE;
  }

  room_item[ROOM_WHITE_CASTLE] = ITEM_CHEESEBURGER;
  room_item[ROOM_OUTSKIRTS_LONDIS] = ITEM_SPAM;
  room_item[ROOM_JOHNNY_FARMHOUSE] = ITEM_HAMMER;
  room_item[ROOM_BEACH] = ITEM_CURRYWURST;
  room_item[ROOM_MERLIN_WALL] = ITEM_M16;
  room_item[ROOM_MT_GREMLIN_BASE] = ITEM_BEEF_STROGANOV;
}

void do_attack(char *noun) {
  *(void *)noun; /* explicit unused */
  if (enemy.health == 0) {
    printf("\nTHERE IS NOTHING TO ATTACK HERE.");
    return;
  }

  printf("\nYOU SWING YOUR %s AT %s!", player.weapon_name, enemy.name);

  if (enemy.health <= player.damage) {
    enemy.health = 0;
    room_cleared[player.room] = 1;
    printf("\nYOU DEFEATED %s!", enemy.name);
    if (player.room == ROOM_MT_GREMLIN_PEAK) {
      printf("\n\nVICTORY! FREEDOM FOR RUSKILAND!");
      freedom = HELL_YEAH;
    }
  } else {
    enemy.health -= player.damage;
    printf("\nTHE %s ATTACKS YOU FOR %d DAMAGE!", enemy.name, enemy.damage);
    if (player.health <= enemy.damage) {
      player.health = 0;
      printf("\nYOU HAVE FALLEN TO THE RED MENACE...\nGAME OVER.");
    } else {
      player.health -= enemy.damage;
    }
  }
}

void do_look(char *noun) {
  int empty;
  int i;
  if (noun != NULL && strcmp(noun, "INVENTORY") == 0) {
    printf("\nIN YOUR BAG: ");
    empty = 1;
    for (i = 0; i < INVSIZE; i++) {
      if (player.inventory[i] != ITEM_NONE) {
        printf("[%s] ", item_name(player.inventory[i]));
        empty = 0;
      }
    }
    if (empty)
      printf("NOTHING BUT DUST.");
    return;
  }

  if (noun == NULL || strcmp(noun, "AROUND") != 0) {
    printf("\nLOOK AT WHAT? (TRY 'LOOK AROUND')");
    return;
  }

  switch (player.room) {
  case ROOM_WHITE_CASTLE:
    printf("\nRUMPLE MCDUMPLE IS HANDING OUT\nCHEESEBURGERS. LONDIS LIES TO "
           "THE EAST.");
    break;
  case ROOM_OUTSKIRTS_LONDIS:
    printf("\nYOU STAND AT THE EDGE OF THE\nLARGEST CITY IN ENGLANDLAND.\nYOU "
           "HEAR THE DISCONTENT YOU WERE WARNED\nABOUT. THE WORKING PEOPLE OF "
           "LONDIS ARE\nTALKING OF OVERTHROWING THEIR LEADER:\nTHE ROOF "
           "THATCHER.\nTO THE NORTH OF YOU ARE FIELDS FULL\nOF DISCONTENT "
           "PEASANTS.\nTHE SMELL OF SPAM IS OVERWHELMING.");
    break;
  case ROOM_JOHNNY_FARM:
    printf("\nTO THE EAST IS A FARMHOUSE. NORTH IS\nTHE FERRY PIER.");
    break;
  case ROOM_JOHNNY_FARMHOUSE:
    printf(
        "\nA QUAINT FARMHOUSE.\nA BAD STEW HAS BEEN LEFT ON THE AGA AND\nANGRY "
        "LETTERS DETAILING QUOTAS ARE\nSTREWN AROUND.\nA HAMMER LIES BY THE "
        "DOOR.\nCOULD BE YOURS NOW.\nNOT LIKE HE BELIEVED IN "
        "PERSONAL\nPROPERTY ANYWAY.\nTHE FIELD IS BACK TO THE WEST.");
    break;
  case ROOM_FERRY_PIER:
    printf("\nYOU'RE AT THE PIER. THE FERRYMAN\nWAVES AND TELLS YOU THE "
           "TOLL\nIS 5 MONIES. YOU TELL HIM THAT\nYOUR MISSION TO "
           "RESTORE\nCAPITALISM TO THE WORLD IS MORE\nIMPORTANT THAN MONEY AND "
           "THAT\nHIS WORK WILL INDIRECTLY PROVIDE HIM\nWITH ALL HE NEEDS IN "
           "LIFE.\nTHE FARM IS BACK SOUTH.\nTHE FERRY LIES NORTH.");
    break;
  case ROOM_BEACH:
    printf("\nTHE BEERMAN DEADLY REPUBLIC,\nBDR FOR SHORT. THIS IS THE\nLAST "
           "COUNTRY BEFORE THE IRON WALL\nWHICH SURROUNDS RUSKYLAND AND MT "
           "\nGREMLIN.IT IS AN INDUSTRIOUS NATION\nINHABITED BY OGRES. THE "
           "WAVES\nARE CRASHING AGAINST THE SHORE.\nTO THE NORTH YOU SEE "
           "A\nFACTORY. IS THAT... CURRYWURST?");
    break;
  case ROOM_CAR_FACTORY:
    printf(
        "\nYOU ARE IN WHAT APPEARS TO BE A CAR\nFACTORY, BUT IT IS COMPLETELY "
        "EMPTY.\nYOU WONDER IF ANYONE IN THE RED EMPIRE\nEVER GETS A CAR.\n"
        "WEST IS A ROAD, EAST IS THE IRON WALL.\nTHE BEACH IS SOUTH.");
    break;
  case ROOM_MERLIN_WALL:
    printf("\nA HUGE WALL SEPARATES YOU FROM\nWESTERN BEERMANY.\nIT MUST BE "
           "THE RECENTLY ERECTED MERLIN\nWALL. YOU THINK TO YOURSELF "
           "'WHAT\nCAN BE MADE IN A DAY CAN BE BROUGHT\nDOWN IN A DAY, PERHAPS "
           "SERENADED\nBY A VERY STRANGE CHOICE OF\nMUSICIAN'. AN M16 LEANS "
           "AGAINST THE \nWALL. THE FACTORY IS BACK EAST.");
    break;
  case ROOM_IRON_WALL:
    printf("\nTURNS OUT THE IRON WALL WAS NOT\nA REAL WALL BUT JUST "
           "SOMETHING\nPEOPLE SAID. WELL, THE MORE YOU\nKNOW! NORTH IS THE "
           "ROAD TO MT GREMLIN.\nTHE FACTORY IS WEST.");
    break;
  case ROOM_MT_GREMLIN_BASE:
    printf(
        "A WHOLE LOAD OF NOTHINGNESS.\nYOU BARELY SEE A FEW FEET IN FRONT\nOF "
        "YOU. YOU FEEL YOUR LUSCIOUS\nBLONDE LOCKS FREEZING OVER.\nA STRONG, "
        "BEEFY, STROGANOVY SMELL\nOVERWHELMS YOUR NOSTRILS.\nNORTH "
        "LEADS TO THE PEAK. THE IRON WALL\nIS BACK SOUTH.");
    break;
  case ROOM_MT_GREMLIN_PEAK:
    printf("\nTHE RED DRAGON IS HERE.\nSTOP IT WHILE YOU CAN\n");
    break;
  }
}

void do_go(char *noun) {
  Room next_room = player.room;
  uint8_t moved = 0;

  if (enemy.health > 0) {
    printf("\nYOU CANNOT LEAVE WHILE UNDER ATTACK!");
    return;
  }
  if (noun == NULL) {
    printf("\nGO WHERE? (NORTH, SOUTH, EAST, WEST)");
    return;
  }

  switch (player.room) {
  case ROOM_WHITE_CASTLE:
    if (strcmp(noun, "EAST") == 0) {
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
      printf("\nTHE FERRYMAN REFUSES TO GO BACK.");
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
      next_room = ROOM_MT_GREMLIN_BASE;
      moved = 1;
    } else if (strcmp(noun, "WEST") == 0) {
      next_room = ROOM_CAR_FACTORY;
      moved = 1;
    }
    break;
  case ROOM_MT_GREMLIN_BASE:
    if (strcmp(noun, "NORTH") == 0) {
      next_room = ROOM_MT_GREMLIN_PEAK;
      moved = 1;
    } else if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_IRON_WALL;
      moved = 1;
    }
    break;
  case ROOM_MT_GREMLIN_PEAK:
    if (strcmp(noun, "SOUTH") == 0) {
      next_room = ROOM_MT_GREMLIN_BASE;
      moved = 1;
    }
    break;
  }

  if (moved) {
    clrscr();
    player.room = next_room;
    printf("\nYOU ARRIVE AT YOUR DESTINATION.");
    check_for_encounter();
  } else if (strcmp(noun, "SOUTH") != 0 || player.room != ROOM_BEACH) {
    printf("\nTHAT WOULD BE SILLY.");
  }
}

void do_pickup(char *noun) {
  ItemType item;
  if (noun == NULL) {
    printf("\nPICK UP WHAT?");
    return;
  }

  item = room_item[player.room];
  if (item == ITEM_NONE || strcmp(noun, item_name(item)) != 0) {
    printf("\nTHERE IS NO %s HERE.", noun);
    return;
  }

  if (item == ITEM_HAMMER) {
    player.damage = 3;
    strcpy(player.weapon_name, "HAMMER");
    printf("\nYOU EQUIP THE HAMMER! DAMAGE INCREASED.");
  } else if (item == ITEM_M16) {
    player.damage = 6;
    strcpy(player.weapon_name, "M16");
    printf("\nYOU EQUIP THE M16! FREEDOM INTENSIFIES.");
  } else {
    add_to_inventory(item);
  }
  room_item[player.room] = ITEM_NONE;
}

void do_use(char *noun) {
  int i;
  int j;
  if (noun == NULL) {
    printf("\nUSE WHAT?");
    return;
  }

  for (i = 0; i < INVSIZE; i++) {
    if (player.inventory[i] != ITEM_NONE &&
        strcmp(noun, item_name(player.inventory[i])) == 0) {
      ItemType used = player.inventory[i];
      uint8_t heal = 0;

      if (used == ITEM_CHEESEBURGER)
        heal = 3;
      else if (used == ITEM_SPAM)
        heal = 2;
      else if (used == ITEM_CURRYWURST)
        heal = 4;
      else if (used == ITEM_BEEF_STROGANOV)
        heal = 9;

      player.health += heal;
      printf("\nYOU USED THE %s AND RECOVERED %d HP!", item_name(used), heal);

      /* Shift inventory down */
      for (j = i; j < INVSIZE - 1; j++)
        player.inventory[j] = player.inventory[j + 1];
      player.inventory[INVSIZE - 1] = ITEM_NONE;
      return;
    }
  }
  printf("\nYOU DON'T HAVE A %s.", noun);
}

/* --- Commands --- */
typedef struct {
  const char *verb;
  void (*action)(char *noun);
} Command;

#define NUM_VERBS 5
const Command commands[NUM_VERBS] = {{"ATTACK", do_attack},
                                     {"GO", do_go},
                                     {"PICKUP", do_pickup},
                                     {"LOOK", do_look},
                                     {"USE", do_use}};

/* --- Main stuff --- */

void intro(void) {
  clrscr();
  printf("        \\(______      ______)/\n");
  printf("        /@.----.\\    /.----.@\\\n");
  printf("       } /      :} {:       \\ {\n");
  printf("      / {        } {        } \\\n");
  printf("      } }      ) } { (      { {\n");
  printf("     / {      /]\\}!{/[\\      } \\\n");
  printf("     } }     ( (.\"^\".) )     { {\n");
  printf("    / {       (O\\   /O)       } \\\n");
  printf("    } }        ]\\^ ^/[       { {\n");
  printf("   / /        ] )   ( [        \\ \\\n");
  printf("  { {        _)(,   ,)(_        } }\n");
  printf("   } }      //  @\";\"@  \\\\      { {\n");
  printf("  / /      //     (     \\\\      \\ \\\n");
  printf(" { {      {(     -=)     )}      } }\n");
  printf("  \\ \\      /)   -=(=-      (\\    / /\n");
  printf("   @\\\\  /'/    /-=[\\-\\    \\@\\  //'\n");
  printf("     @\\{  ]   ( -===- )   [  }/'\n");
  printf("       @  _\\   \\-===-/   /_  '\n");
  printf("         (_(_(_)'-=-'(_)_)_)\n");
  printf("         @\"@\"@\"        \"@\"@\"@\n");
  printf("      TRICKLE-DOWN DRAGONSLAYER\n\n");

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
    if (player.health <= 0 || freedom) {
      break;
    }
    if (enemy.health > 0) {
      show_stats();
    }
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
