#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_crlf(char *s)
{
    char *t = s + strlen(s); // t begins at the null sentinel at the end of s.
    t--;
    /* t is now at the last character of s - unless s didn't contain any characters, in        
     which case, t is now *BEFORE* s.  We have to keep checking for that. */
    /* We repeat until EITHER t slides to the left of s, OR we find a character that is        
     not a line feed (\n) or a carriage return (\r). */
    while ((t >= s) && (*t == '\n' || *t == '\r'))
    {
        *t = '\0'; // Clobber the character t is pointing at.
        t--;       // Decrement t.
    }
}

struct line_struct
{
    float m, b;
    int count;
    double x, y;
};

typedef struct line_struct line;

line *make_line(float m, float b, int count, double x, double y)
{
    line *l = malloc(sizeof(line));
    l->m = m;
    l->b = b;
    l->count = count;
    l->x = x;
    l->y = y;

    return l;
}

line *read_line(FILE *ifp)
{
    line *l = malloc(sizeof(line));

    fread(l, sizeof(line), 1, ifp);
    return l;
}

void write_small_monster(FILE *ofp, line *l)
{
    fwrite(l, sizeof(line), 1, ofp);
}

void dispose_line(line *l)
{
    free(l);
}

void print_line(line *l)
{
    printf("m: %f\n", l->m);
    printf("b: %f\n", l->b);
    printf("count: %d\n", l->count);
    printf("x: %lf\n", l->x);
    printf("y: %lf\n", l->y);
}

int main(void)
{
    float m, b;
    int count;
    double x, y;
    char buf[256];

    FILE *ifp;

    ifp = fopen("as5input.txt", "r");

    fgets(buf, 255, ifp);
    sscanf(buf, "%f %f", &m, &b);
    printf("m:%f b:%f\n", m, b);

    fgets(buf, 255, ifp);
    sscanf(buf, "%d", &count);
    printf("count: %d\n", count);

    return 0;
}