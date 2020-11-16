/* malloc.c - demonstrate basic memory allocation */

#include <stdio.h>
#include <stdlib.h>
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

/* Allocates and fills out an empty small monster structure.  This returns an
   already-allocated small_monster pointer with variables filled out as given.
   
   This pattern is called a CONSTRUCTOR, and you will see it over and over again
   in all sorts of languages. */

small_monster *new_small_monster(char *new_name, char *new_type, char *new_element,
                                 char *new_region, float new_weight, 
                                 unsigned int new_level)
{
  /* malloc() - the (M)emory (ALLOC)ator function - sets aside a region of memory
     of the size you ask for, and gives you back a pointer to it.  You set *your*
     pointer equal to *this* pointer.  It's less complicated than it sounds: */

  small_monster *mon = malloc(sizeof(small_monster));

  /* mon now points at a region of memory that's been set aside for us.  That
     region of memory will survive this function going out of scope - even though
     the mon pointer itself won't!  But that's okay, because we copy the mon
     pointer when we return it. */

  strcpy(mon->name, new_name);
  strcpy(mon->type, new_type);
  strcpy(mon->element, new_element);
  strcpy(mon->native_region, new_region);
  mon->weight = new_weight;
  mon->level = new_level;

  return mon;
}

/* This constructor allocates a new small_monster structure and reads its contents
   in from ifp. */

small_monster *read_small_monster(FILE *ifp)
{
  small_monster *mon = malloc(sizeof(small_monster));

  /* The parameters of fread() are symmetric to those of fwrite(). */

  fread(mon, sizeof(small_monster), 1, ifp);
  return mon;
}

/* This function writes out a small monster to ofp. */

void write_small_monster(FILE *ofp, small_monster *mon)
{
  /* To write to a binary file, use fwrite rather than fprintf.  You will write bytes
     directly - use sizeof() to find the size of structures.

     fwrite has four parameters:

     * The address of the memory buffer you're writing from
     * The size of the records you're writing (almost always uses sizeof)
     * The number of records you're writing (always 1 unless it's an array)
     * The file you're writing to */

  fwrite(mon, sizeof(small_monster), 1, ofp);
}

/* Just as we have constructors, we have DESTRUCTORS. */

void dispose_small_monster(small_monster *mon)
{
  /* Whenever you malloc() memory, you need to free() it.  free() takes the memory and
     returns it to the available memory space so that it can be allocated to something
     else.  If you don't free(), it creates a memory leak. */

  free(mon);
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
  /* The basics of malloc are really simple.  Normally, when you declare a variable,
     the compiler sets aside memory for it and names it.  When you declare only a
     pointer, the name is there, but the memory hasn't been set aside. */

  small_monster *percival;
  small_monster *other_percival;
  FILE *ofp, *ifp;

  /* We'll use the constructor to create and fill percival. */

  percival = new_small_monster("Percival", "Rubber Duck", "Water", "Knightrola", 0.2, 1);
  print_small_monster(percival);

  /* To open a file for binary rather than text writing, we just add "b" to the "w". */

  ofp = fopen("monster-output.bin", "wb");
  write_small_monster(ofp, percival);
  fclose(ofp);

  /* We're done with percival, so we use the destructor to deallocate it. */

  dispose_small_monster(percival);

  /* Opening a file for binary reading is just like opening it for binary writing. */

  ifp = fopen("monster-output.bin", "rb");
  other_percival = read_small_monster(ifp);
  fclose(ifp);

  print_small_monster(other_percival);
  dispose_small_monster(other_percival);

  return 0;
}