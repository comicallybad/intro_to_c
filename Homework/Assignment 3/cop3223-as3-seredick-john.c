#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

double compute_y_value(double slope, double intercept, double *xValues, double *yValues, double increment)
{
   //Making user of Y=mx+b
   double max = 0;
   int counter = 0;

   if (increment == 1)
   {
      max = increment * 10;
      printf("Max: %lf Increment: %lf\n", max, increment);
      for (double i = 0.0; i <= max; i++)
      {
         xValues[counter] = i;
         yValues[counter] = ((slope * xValues[counter]) + intercept);
         printf("x: %05.2lf ", i);
         printf("y: %05.2lf\n", (slope * xValues[counter]) + intercept);
         counter++;
      }
   }
   else if (increment == -1)
   {
      max = increment * 10;
      printf("Max: %lf Increment: %lf\n", max, increment);
      for (double i = 0.0; i >= max; i--)
      {
         xValues[counter] = i;
         yValues[counter] = ((slope * xValues[counter]) + intercept);
         printf("x: %06.2lf ", i);
         printf("y: %06.2lf\n", (slope * xValues[counter]) + intercept);
         counter++;
      }
   }
   else if (increment == 10)
   {
      printf("Max: %lf Increment: %lf\n", max, increment);
      max = 1000000.0;
      xValues[counter] = 0.0;
      yValues[counter] = intercept;
      counter++;
      for (double i = 1.0; i <= max; i *= increment)
      {
         xValues[counter] = i;
         yValues[counter] = ((slope * xValues[counter]) + intercept);
         printf("x: %10.2E ", i);
         printf("y: %10.2E\n", (slope * xValues[counter]) + intercept);
         counter++;
      }
   }
   else if (increment == 0.1)
   {
      printf("Max: %lf Increment: %lf\n", max, increment);
      max = 0.00001;
      xValues[counter] = 0.0;
      yValues[counter] = intercept;
      counter++;
      for (double i = 1.0; i >= max; i *= increment)
      {
         xValues[counter] = i;
         yValues[counter] = ((slope * xValues[counter]) + intercept);
         printf("x: %10.2E ", i);
         printf("y: %10.2E\n", (slope * xValues[counter]) + intercept);
         counter++;
      }
   }
   return counter;
}

void output_to_file(char *title, double x1, double y1, double x2, double y2, double *xValues, double *yValues)
{
   double counter;
   //Open output file
   FILE *ofp;
   ofp = fopen("cop3223-as3output-seredick-john.txt", "w");

   //Print the title to output file followed by new line
   fprintf(ofp, title);
   fprintf(ofp, "\n");

   double slope = get_slope(x1, y1, x2, y2);
   double intercept = get_intercept(x1, y1, x2, y2);

   //Go through the arrays and print out the coordinates, slope, and intecept
   //Also %2.2lf to shorten to only 2 decimals
   fprintf(ofp, "Points Given: \n");
   fprintf(ofp, "(%2.2lf,%2.2lf),(%2.2lf,%2.2lf)\n", x1, y1, x2, y2);
   fprintf(ofp, "Slope: %2.2lf\n", slope);
   fprintf(ofp, "Intercept: %2.2lf\n", intercept);
   fprintf(ofp, "\n"); //to make it cleaner :)
   fprintf(ofp, "Computed Points: \n");

   fprintf(ofp, "Values from the line with an increment of 1\n");
   counter = compute_y_value(slope, intercept, xValues, yValues, 1.0);

   for (int i = 0; i < counter; i++)
   {
      fprintf(ofp, "(%05.2lf,%05.2lf)\n", xValues[i], yValues[i]);
   }

   printf("\n");
   fprintf(ofp, "\n");
   fprintf(ofp, "Values from the line with an increment of -1\n");

   counter = compute_y_value(slope, intercept, xValues, yValues, -1.0);

   for (int i = 0; i < counter; i++)
   {
      fprintf(ofp, "(%06.2lf,%06.2lf)\n", xValues[i], yValues[i]);
   }

   printf("\n");
   fprintf(ofp, "\n");
   fprintf(ofp, "Values from the line with increments of a times 10 multiplier\n");

   counter = compute_y_value(slope, intercept, xValues, yValues, 10.0);

   for (int i = 0; i < counter; i++)
   {
      fprintf(ofp, "(%10.2E,%10.2E)\n", xValues[i], yValues[i]);
   }

   printf("\n");
   fprintf(ofp, "\n");
   fprintf(ofp, "Values from the line with increments of a times 0.1 multiplier\n");

   counter = compute_y_value(slope, intercept, xValues, yValues, 0.1);

   for (int i = 0; i < counter; i++)
   {
      fprintf(ofp, "(%10.2E,%10.2E)\n", xValues[i], yValues[i]);
   }

   fclose(ofp);
}

int main(void)
{
   double x1, y1, x2, y2;
   char title[256];
   char buf[256];
   double xValues[50];
   double yValues[50];

   FILE *ifp;

   //Open input file for read mode
   ifp = fopen("cop3223-as3input.txt", "r");

   //Get the title on the first line
   fgets(title, 255, ifp);
   remove_crlf(title);
   printf("%s.\n", title);

   //Start counter at 0
   int n = 0;

   fgets(buf, 255, ifp);
   sscanf(buf, "(%lf,%lf),(%lf,%lf)", &x1, &y1, &x2, &y2);
   printf("(%lf,%lf),(%lf,%lf)\n", x1, y1, x2, y2);

   //Print out the slope and intercept using the current coordinates
   printf("Slope: %lf\n", get_slope(x1, y1, x2, y2));
   printf("Intercept: %lf\n", get_intercept(x1, y1, x2, y2));

   fclose(ifp);

   //Output to file
   output_to_file(title, x1, y1, x2, y2, xValues, yValues);

   return 0;
}