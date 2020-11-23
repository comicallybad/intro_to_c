/* linked-list.c - very simple linked list */

#include <stdio.h>
#include <stdlib.h>

/* Structure for a list item with a single int as payload. */

struct item_struct {
  int n;
  struct item_struct *next;
};

typedef struct item_struct item;

/* Structure for a head-only linked list. */

struct linked_list_struct {
  item *head;
};

typedef struct linked_list_struct linked_list;

/* Constructor for item. */

item *new_item(int n) {
  item *it = malloc(sizeof(item));

  // Accept the payload, and set the next pointer to nothing.

  it->n = n;
  it->next = NULL;

  return it;
}

/* Destructor for item.  Just frees the item. */

void dispose_item(item *it) {
  free(it);
}

/* Printer for item.  Just prints the payload. */

void print_item(item *it) {
  printf("  Value: %d\n", it->n);
}

/* Constructor for list.  Just sets the head pointer to nothing. */

linked_list *new_list(void) {
  linked_list *l = malloc(sizeof(linked_list));

  l->head = NULL;

  return l;
}

/* Destructor for list.  We also get rid of all the items currently
   in the list. */

void dispose_list(linked_list *l) {
  item *it = l->head;
  item *next;

  /* it is now the head of the list, so if the list is empty,
     we do nothing. */

  while(it != NULL) {
    next = it->next;    // Grab it's next pointer
    dispose_item(it);   // Free it's memory
    it = next;          // Go to the next item
  }

  free(l);              // Free the list
}

/* Printer for list. */

void print_list(linked_list *l) {
  item *it = l->head;

  /* it is now the head of the list, so if the list is empty,
     we do nothing. */

  while(it != NULL) {
    print_item(it);     // Print out the item
    it = it->next;      // Go to the next item
  }
}

/* Add an item to the head (front) of list. */

void add_item_to_list(linked_list *l, item *it) {
  /* Set the new item's next pointer to point at the item
     that's currently the head. */

  it->next = l->head;

  /* Now, set the head pointer to point at the new item. */

  l->head = it;
}

/* Main program. */

int main(void) {
  linked_list *list;

  list = new_list();

  add_item_to_list(list, new_item(1));
  add_item_to_list(list, new_item(2));
  add_item_to_list(list, new_item(3));
  add_item_to_list(list, new_item(4));

  print_list(list);

  return 0;
}