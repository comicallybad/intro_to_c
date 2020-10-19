/* scanf.c: Demonstrate scanf. */

#include <stdio.h>
#include <string.h>

void remove_crlf(char *s)
{
   char *t = s + strlen(s);

   t--;

   while ((t >= s) && (*t == '\n' || *t == '\r'))
   {
      *t = '\0';
      t--;
   }
}

void get_next_nonblank_line(char *buf, int max_length, FILE *ifp)
{
   strcpy(buf, "");

   while (strcmp(buf, "") == 0)
   {
      fgets(buf, max_length, ifp);
      remove_crlf(buf);
   }
}

int main(void)
{
   int i, j, k, l;
   char buf[256];

   /* scanf is the opposite of printf.  It accepts the same basic type specifiers that
     printf does. */

   printf("Enter a number: ");
   scanf("%d", &i);
   printf("The number is: %d\n", i);

   /* scanf can take more than one input at a time. */

   printf("Enter two numbers: ");
   scanf("%d %d", &i, &j);
   printf("The numbers are: %d and %d\n", i, j);

   /* scanf is, unfortunately, *very finicky* about input matching its format. */

   printf("Enter two numbers, and this time use a comma: ");
   scanf("%d,%d", &i, &j);
   printf("The numbers are: %d and %d\n", i, j);

   /* scanf has a corresponding fscanf.  Here we read from stdin, but you don't
     have to - it can read from any file. */

   printf("Enter two numbers: ");
   fscanf(stdin, "%d %d", &i, &j);
   printf("The numbers are: %d and %d\n", i, j);

   printf("Enter two numbers, and this time use a comma: ");
   fscanf(stdin, "%d,%d", &i, &j);
   printf("The numbers are: %d and %d\n", i, j);

   /* Sometimes you can run into issues with scanf and newlines.  There are
     ways to get scanf to deal with newlines as whitespace, but it can be 
     simpler to read in a line and *then* scan it.  You can do this with
     sscanf.
     
     You see here that there's theoretically nothing you can do with fgets
     that you can't do with fscanf - but if you fgets, you *know* that you've
     consumed the whole line, and the filepointer has been moved to the next
     line.  There will be no trash left that can mess up your next scan.

     Sometimes, with scanf, you'll find that important.
     
     So you can use sscanf - for (s)tring scanf - to scan a line you've 
     already read. */

   printf("Enter four numbers: ");
   get_next_nonblank_line(buf, 255, stdin);
   remove_crlf(buf);
   sscanf(buf, "%d %d %d %d", &i, &j, &k, &l);
   printf("The numbers are: %d, %d, %d, %d\n", i, j, k, l);

   return 0;
}