/* malloc-arrays.c - demonstrate malloc for dynamically allocated arrays */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/* This structure defines a <del>Pok</del> small monster. */

struct small_monster_struct {
  char name[64];
  char type[64];
  char element[64];
  char native_region[64];
  float weight;
  unsigned int level;
  unsigned int shininess;
};

typedef struct small_monster_struct small_monster;

/* Fill out a small monster's struct with random values. */

void fill_random_small_monster(small_monster *mon) {
  int monster_name_number = rand();                    // Random monster name (see below)
  int monster_type_number = rand();                    // Random monster type (see below)
  float weight = (float) ((rand() % 1000) + 1) / 10.0; // Weight from 0.1 to 100kg
  int level = (rand() % 30) + 1;                       // Level from 1 to 30
  int element_number = rand() % 10;
  int region_number = rand() % 5;
  int shininess = rand() % 5;
  char *element;
  char *region;

  if(element_number == 0) { element = "Earth"; }
  else if(element_number == 1) { element = "Fire"; }
  else if(element_number == 2) { element = "Air"; }
  else if(element_number == 3) { element = "Water"; }
  else if(element_number == 4) { element = "Grass"; }
  else if(element_number == 5) { element = "Bread"; }
  else if(element_number == 6) { element = "Parking Ticket"; }
  else if(element_number == 7) { element = "Electric Scooter"; }
  else if(element_number == 8) { element = "Ice Cream"; }
  else if(element_number == 9) { element = "Swamp"; }

  if(region_number == 0) { region = "Knightrola"; }
  else if(region_number == 1) { region = "Tauroto"; }
  else if(region_number == 2) { region = "Gatorva"; }
  else if(region_number == 3) { region = "Owlville"; }
  else if(region_number == 4) { region = "Eagleland"; }

  sprintf(mon->name, "Monster #%010d", monster_name_number);
  sprintf(mon->type, "Type #%010d", monster_type_number);
  strcpy(mon->element, element);
  strcpy(mon->native_region, region);
  mon->weight = weight;
  mon->level = level;
  mon->shininess = shininess;
}

/* Print out a small monster record. */

void print_small_monster(small_monster *mon)
{
  printf("%s\n", mon->name);
  printf("  Level %u %s-type small monster, %.1f kg\n", mon->level, mon->type, mon->weight);
  printf("  Originally from %s region, %s element\n", mon->native_region, mon->element);
  if(mon->shininess == 0) { printf("  This monster is not shiny.\n"); }
  if(mon->shininess == 1) { printf("  This monster is a bit shiny.\n"); }
  if(mon->shininess == 2) { printf("  This monster is shiny.\n"); }
  if(mon->shininess == 3) { printf("  This monster is very shiny.\n"); }
  if(mon->shininess == 4) { printf("  This monster is blindingly shiny.\n"); }
}

// Create n random small monsters and return them in an allocated array.

small_monster *make_some_monsters(int n)
{
  /* Allocate enough space for n small monsters.  We now have a DYNAMICALLY allocated
     ARRAY specified by our n value. */

  small_monster *mons = (small_monster *) malloc(n * sizeof(small_monster));

  /* Fill our small monster array. */

  for(int i = 0; i < n; i++) {
    /* We fill each small monster separately, so we need to pass a pointer to the
       *element* of the array we want to fill. */

    fill_random_small_monster(&mons[i]);
  }

  return mons;
}

// Print out a bunch of small monsters.

void print_small_monsters(small_monster *mons, int n)
{
  for(int i = 0; i < n; i++) {
    print_small_monster(&mons[i]);
  }
}

/* Main program. */

int main(void) {
  /* The basics of malloc are really simple.  Normally, when you declare a variable,
     the compiler sets aside memory for it and names it.  When you declare only a
     pointer, the name is there, but the memory hasn't been set aside. */

  small_monster *mon;
  int n;

  srand(time(NULL)); // Seed the random number generator

  n = (rand() % 100) + 1;

  printf("Here are %d small monsters:\n", n);

  mon = make_some_monsters(n);
  print_small_monsters(mon, n);
  free(mon);

  return 0;
}