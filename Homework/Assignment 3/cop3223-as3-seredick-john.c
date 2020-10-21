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

void get_next_nonblank_line(char *buf, int max_length, FILE *ifp)
{
   strcpy(buf, "");

   while (strcmp(buf, "") == 0)
   {
      fgets(buf, max_length, ifp);
      remove_crlf(buf);
   }
}

//Get the slope of the line
double get_slope(double x1, double y1, double x2, double y2)
{
   //sope = x2-x1/y2-y1
   double slope;

   slope = (x2 - x1) / (y2 - y1);

   return slope;
}

//Get the y intercept
double get_intercept(double x1, double y1, double x2, double y2)
{
   //intercept = y2-y1=m(x2-x1)
   //y=mx+b
   double intercept;

   intercept = (get_slope(x1, y1, x2, y2) * x1 * -1) + y1;

   return intercept;
}

int main(void)
{
   double x1, y1, x2, y2;
   char title[256];
   char buf[256];
   double x1Array[50];
   double y1Array[50];
   double x2Array[50];
   double y2Array[50];

   FILE *ifp;

   //Open input file for read mode
   ifp = fopen("cop3223-as3input.txt", "r");

   //Get the title on the first line
   fgets(title, 255, ifp);
   remove_crlf(title);
   printf("%s.\n", title);

   //Start counter at 0
   int n = 0;

   while (feof(ifp) == 0)
   {
      //Get new line and assign coordinates x1,y1,x2,y2
      //Print out the coordinates found
      fgets(buf, 255, ifp);
      sscanf(buf, "(%lf,%lf),(%lf,%lf)", &x1, &y1, &x2, &y2);
      printf("(%lf,%lf),(%lf,%lf)\n", x1, y1, x2, y2);

      //Assign coordinates into an array
      x1Array[n] = x1;
      y1Array[n] = y1;
      x2Array[n] = x2;
      y2Array[n] = y2;

      //Print out the slope and intercept using the current coordinates
      printf("Slope: %lf\n", get_slope(x1, y1, x2, y2));
      printf("Intercept: %lf\n", get_intercept(x1, y1, x2, y2));
      n++;
   }

   fclose(ifp);

   //Open output file
   FILE *ofp;
   ofp = fopen("cop3223-as3output-seredick-john.txt", "w");

   //Print the title to output file followed by new line
   fprintf(ofp, title);
   fprintf(ofp, "\n");

   //Go through the arrays and print out the coordinates, slope, and intecept
   //Also %2.2lf to shorten to only 2 decimals
   for (int i = 0; i < n; i++)
   {
      fprintf(ofp, "Points Given: \n");
      fprintf(ofp, "(%2.2lf,%2.2lf),(%2.2lf,%2.2lf)\n", x1Array[i], y1Array[i], x2Array[i], y2Array[i]);
      fprintf(ofp, "Slope: %2.2lf\n", get_slope(x1Array[i], y1Array[i], x2Array[i], y2Array[i]));
      fprintf(ofp, "Intercept: %2.2lf\n", get_intercept(x1Array[i], y1Array[i], x2Array[i], y2Array[i]));
      fprintf(ofp, "\n"); //to make it cleaner :)
   }

   fclose(ofp);

   return 0;
}