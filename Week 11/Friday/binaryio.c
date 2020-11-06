/* binaryio.c - demonstrate basic binary file I/O */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* This structure defines a <del>Pok</del> small monster. */

struct small_monster_struct
{
  char name[64];
  char type[64];
  char element[64];
  char native_region[64];
  float weight;
  unsigned int level;
};

typedef struct small_monster_struct small_monster;

/* Fills out an empty small monster structure. */

small_monster *new_small_monster(char *new_name, char *new_type,
                                 char *new_element, char *new_region, float new_weight,
                                 unsigned int new_level)
{
  small_monster *mon = malloc(sizeof(small_monster));

  strcpy(mon->name, new_name);
  strcpy(mon->type, new_type);
  strcpy(mon->element, new_element);
  strcpy(mon->native_region, new_region);
  mon->weight = new_weight;
  mon->level = new_level;

  return mon;
}

small_monster *read_small_monster(FILE *ifp)
{
  small_monster *mon = malloc(sizeof(small_monster));
  fread(mon, sizeof(small_monster), 1, ifp);
  return mon;
}

small_monster *write_small_monster(FILE *ofp, small_monster *mon)
{
  fwrite(mon, sizeof(small_monster), 1, ofp);
}

/* Print out a small monster record. */

void print_small_monster(small_monster *mon)
{
  printf("%s\n", mon->name);
  printf("  Level %u %s-type small monster, %.1f kg\n", mon->level, mon->type, mon->weight);
  printf("  Originally from %s region, %s element\n", mon->native_region, mon->element);
}

void dispose_small_monster(small_monster *mon)
{
  free(mon);
}

/* Main program. */

int main(void)
{
  small_monster *percival;
  small_monster *other_percival;
  FILE *ofp, *ifp;

  // percival = malloc(sizeof(small_monster));
  other_percival = malloc(sizeof(small_monster));

  percival = new_small_monster("Percival", "Rubber Duck", "Water", "Knightrola", 0.2, 1);
  print_small_monster(percival);

  ofp = fopen("monster-output.bin", "wb");
  write_small_monster(ofp, percival);
  fclose(ofp);

  dispose_small_monster(percival);

  ifp = fopen("monster-output.bin", "rb");
  other_percival = read_small_monster(ifp);
  fclose(ifp);

  print_small_monster(other_percival);

  dispose_small_monster(other_percival);

  return 0;
}