#include <stdio.h>

struct instance_struct
{
    char title[64];
    float m;
    float b;
    double x[10];
    double y[10];
};

typedef struct instance_struct instance;

void instance_print(instance *is)
{
    int i;

    printf("\nInstance: %s\n", is->title);
    printf("  y = %lf x + %lf\n", is->m, is->b);

    for (i = 0; i < 10; i = i + 1)
    {
        printf("  x: %lf   y: %lf\n", is->x[i], is->y[i]);
    }
}

int main(void)
{
    FILE *ifp;
    instance is;

    ifp = fopen("as4output-seredick-john.bin", "rb");

    while (!feof(ifp))
    {
        if (fread(&is, sizeof(instance), 1, ifp))
        {
            instance_print(&is);
        }
    }

    fclose(ifp);
}