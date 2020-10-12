
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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

int main(void)
{
    FILE *ifp;
    FILE *ofp;
    char read_buffer[128];
    int found_bob = 0;

    ofp = fopen("output.txt", "a");
    ifp = fopen("input.txt", "r");

    printf("Let's see if this file has Bob in it.\n");

    while (feof(ifp) == 0)
    {
        fgets(read_buffer, 127, ifp);
        remove_crlf(read_buffer);
        printf("This person is %s.\n", read_buffer);

        if (strcasecmp(read_buffer, "bob") == 0)
        {
            printf("This person is named Bob.\n");
            found_bob = 1;
        }
        else
        {
            printf("This person is not named Bob.\n");
        }
    }

    if (found_bob)
    {
        printf("We did, in fact, find Bob.\n");
    }
    else
    {
        printf("We never found Bob. How sad.");
    }

    fprintf(ofp, "Huh uh suh dude!\n");

    fclose(ofp);
    fclose(ifp);

    return 0;
}