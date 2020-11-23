/* selection-sort.c - selection sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int *get_some_random_integers(int n, int low, int high) {
  int *rands = malloc(sizeof(int) * n);

  for(int i = 0; i < n; i++) {
    rands[i] = (rand() % (high - low + 1)) + low;
  }

  return rands;
}

void dispose_random_integers(int *rands) {
  free(rands);
}

void print_int_array(int *ints, int n, char *title) {
  printf("%s\n", title);

  for(int i = 0; i < n; i++) {
    printf("  %d\n", ints[i]);
  }
}

void selection_sort_int_array(int *ints, int n) {
  /* We need to find the correct value for every array position 0..n.
     We actually only need to act up through (n-1), since we'll then have
     the nth value in place by process of elimination. */

  for(int i = 0; i < n - 1; i++) {
    /* Select the lowest value in the thus-far-unsorted list. */
    int lowest_val = ints[i];
    int lowest_pos = i;

    /* Loop through the thus-far-unsorted list. */
    for(int j = i + 1; j < n; j++) {
      /* Is this the new lowest so far? */
      if(ints[j] < lowest_val) {
        lowest_val = ints[j];
        lowest_pos = j;
      }
    }

    /* We now have our lowest value in lowest_val and our lowest position
       in lowest_pos.  Swap the values in lowest_pos and our target
       location. */
    
    ints[lowest_pos] = ints[i];
    ints[i] = lowest_val;
  }
}

int main(void) {
  srand(time(NULL));
  int *random_integers;

  random_integers = get_some_random_integers(20, 0, 10000);
   
  print_int_array(random_integers, 20, "Our random integers");
  sort_int_array(random_integers, 20);
  print_int_array(random_integers, 20, "Our sorted integers");

  dispose_random_integers(random_integers);

  return 0;
}