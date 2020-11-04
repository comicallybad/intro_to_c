/* binaryio.c - demonstrate basic binary file I/O */

#include <stdio.h>
#include <math.h>
#include <string.h>

/* This structure defines a <del>Pok</del> small monster. */

struct small_monster_struct {
  char name[64];
  char type[64];
  char element[64];
  char native_region[64];
  float weight;
  unsigned int level;
};

typedef struct small_monster_struct small_monster;

/* Fills out an empty small monster structure. */

void fill_small_monster(small_monster *mon, char *new_name, char *new_type,
                        char *new_element, char *new_region, float new_weight, 
                        unsigned int new_level)
{
  strcpy(mon->name, new_name);
  strcpy(mon->type, new_type);
  strcpy(mon->element, new_element);
  strcpy(mon->native_region, new_region);
  mon->weight = new_weight;
  mon->level = new_level;
}

/* Print out a small monster record. */

void print_small_monster(small_monster *mon)
{
  printf("%s\n", mon->name);
  printf("  Level %u %s-type small monster, %.1f kg\n", mon->level, mon->type, mon->weight);
  printf("  Originally from %s region, %s element\n", mon->native_region, mon->element);
}

/* Main program. */

int main(void) {
  small_monster percival;
  small_monster other_percival;
  FILE *ofp, *ifp;

  fill_small_monster(&percival, "Percival", "Rubber Duck", "Water", "Knightrola", 0.2, 1);
  print_small_monster(&percival);

  /* To open a file for binary rather than text writing, we just add "b" to the "w".
     To write to a binary file, use fwrite rather than fprintf.  You will write bytes
     directly - use sizeof() to find the size of structures.

     fwrite has four parameters:

     * The address of the memory buffer you're writing from
     * The size of the records you're writing (almost always uses sizeof)
     * The number of records you're writing (always 1 unless it's an array)
     * The file you're writing to */

  ofp = fopen("monster-output.bin", "wb");
  fwrite(&percival, sizeof(small_monster), 1, ofp);
  fclose(ofp);

  /* Opening a file for binary reading, and using fread(), are similar.  The parameters
     of fread() are symmetric to those of fwrite(). */

  ifp = fopen("monster-output.bin", "rb");
  fread(&other_percival, sizeof(small_monster), 1, ifp);
  fclose(ifp);

  print_small_monster(&other_percival);

  return 0;
}