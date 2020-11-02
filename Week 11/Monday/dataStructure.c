#include <stdio.h>
#include <math.h>
#include <strings.h>
#include <string.h>

struct complex_number
{
    float real_part;
    float imaginary_part;
};

struct small_monster_struct
{
    char name[64];
    char type[64];
    char element[64];
    char native_region[64];
    float weight;
    unsigned int level;
};

void print_complex_number(struct complex_number c)
{
    printf("%0.3f+%0.3fi", c.real_part, c.imaginary_part);
}

void print_complex_number_with_pointer(struct complex_number *c)
{
    printf("%0.3f+ %f0.3i", c->real_part, c->imaginary_part);
}

void fill_small_monster(struct small_monster_struct *mon, char *new_name, char *new_type, char *new_element, char *new_region, float new_weight, unsigned int new_level)
{
    strcpy(mon->name, new_name);
    strcpy(mon->type, new_type);
    strcpy(mon->element, new_element);
    strcpy(mon->native_region, new_region);
    mon->weight = new_weight;
    mon->level = new_level;
}

void print_small_monster(struct small_monster_struct *mon)
{
    printf("%s\n", mon->name);
    printf("    Level %u %s-type small monster, %f kg\n", mon->level, mon->type, mon->weight);
    printf("    Originally from %s region, %s element", mon->native_region, mon->element);
}

int main(void)
{
    struct complex_number c;
    struct small_monster_struct percival;

    c.real_part = 5.0;
    c.imaginary_part = 6.3;

    printf("Printed without pointer :");
    print_complex_number(c);
    printf("\n");

    printf("Printed with pointer :");
    print_complex_number_with_pointer(&c);
    printf("\n");

    printf("A small monster's record is %ld bytes long.\n", sizeof(percival));
    printf("A small monster's record is %ld bytes long.\n", sizeof(&percival));

    fill_small_monster(&percival, "Percival", "Rubber Duck", "Water", "Knightrola", 0.2, 1);
    print_small_monster(&percival);

    return 0;
}