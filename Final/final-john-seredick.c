#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//This function is to fix fgets
void remove_crlf(char *s)
{
  char *t = s + strlen(s);
  t--;
  while ((t >= s) && (*t == '\n' || *t == '\r'))
  {
    *t = '\0'; // Clobber the character t is pointing at.
    t--;       // Decrement t.
  }
}

void clear_all(FILE *ofp, double *store)
{
  for (int i = 0; i < 10; i++)
  {
    store[i] = 0;
  }
  return;
}

double back(FILE *ofp, double *memory, double *store, int count)
{
  char temp[4];
  strcpy(temp, "b");
  while (strcmp(temp, "b") == 0)
  {
    if (count == 0)
    {
      printf("Sorry you dont have anything else to go back to! Press enter to do math with %lf\n", memory[count]);
      fgets(temp, 3, stdin);
      remove_crlf(temp);
    }
    else
    {
      printf("Press b then enter to go back again or press enter to do math with %lf\n", memory[count]);
      fprintf(ofp, "b\n");
      fgets(temp, 3, stdin);
      remove_crlf(temp);
      count--;
    }
  }
  return memory[count + 1];
}

//This function does the math for the sine of the fitst value of the calculator
double sine_value(double result, FILE *ofp)
{
  printf("Sine %2.17lf = %2.17lf\n", result, sin(result));
  fprintf(ofp, "Sine %2.17lf = %2.17lf\n", result, sin(result));
  return sin(result);
}

//This function does the math for the cosine part of the calculator
double cosine_value(double result, FILE *ofp)
{
  printf("Cosine %2.17lf = %2.17lf\n", result, cos(result));
  fprintf(ofp, "Cosine %2.17lf = %2.17lf\n", result, cos(result));
  return cos(result);
}

//This function does the math for the tangent part of the calculator
double tangent_value(double result, FILE *ofp)
{
  printf("Tangent %2.17lf = %2.17lf\n", result, tan(result));
  fprintf(ofp, "Tangent %2.17lf = %2.17lf\n", result, tan(result));
  return tan(result);
}
//math for the inverse sine part of the calculator
double inverse_sine_value(double result, FILE *ofp)
{
  if (result > 1 || result < -1)
  {
    printf("Error.\n");
    fprintf(ofp, "Error.\n");
  }
  else
  {
    printf("The inverse sine %2.17lf = %2.17lf\n", result, asin(result));
    fprintf(ofp, "Thed inverse sine %2.17lf = %2.17lf\n", result, asin(result));
  }
  return asin(result);
}

//This function does the math for the inverse cosine part of the calculator
double inverse_cosine_value(double result, FILE *ofp)
{
  if (result > 1 || result < -1)
  {
    printf("Error.\n");
    fprintf(ofp, "Error.\n");
  }
  else
  {
    printf("The inverse cosine %2.17lf = %2.17lf\n", result, acos(result));
    fprintf(ofp, "The inverse cosine %2.17lf = %2.17lf\n", result, acos(result));
  }
  return acos(result);
}

//This function does the math for the inverse tangent part of the calculator
double inverse_tangent_value(double result, FILE *ofp)
{
  printf("The inverse tangent %2.17lf = %2.17lf\n", result, atan(result));
  fprintf(ofp, "The inverse tangent %2.17lf = %2.17lf\n", result, atan(result));
  return atan(result);
}

//This function does the math for the square root part of the calculator
double square_root_value(double result, FILE *ofp)
{
  if (result < 0)
  {
    printf("Error\n");
    fprintf(ofp, "Error\n");
  }
  else
  {
    printf("The square root of %2.17lf = %2.17lf\n", result, sqrt(result));
    fprintf(ofp, "The square root of %2.17lf = %2.17lf\n", result, sqrt(result));
  }
  return sqrt(result);
}

//This function does the math for the absolute value part of the calculator
double absolute_value_value(double result, FILE *ofp)
{
  printf("The absolute value of %2.17lf = %2.17lf\n", result, fabs(result));
  fprintf(ofp, "The absolute value of %2.17lf = %2.17lf\n", result, fabs(result));
  return fabs(result);
}

//This function does the math for the inverse part of the calculator
double inverse_value(double result, FILE *ofp)
{
  if (result == 0)
  {
    printf("Error.\n");
    fprintf(ofp, "Error.\n");
  }
  else
  {
    printf("The inverse of %2.17lf = %2.17lf\n", result, (1 / result));
    fprintf(ofp, "The inverse of %2.17lf = %2.17lf\n", result, (1 / result));
  }
  return (1 / result);
}

//This function does the math for the log base 10 part of the calculator
double log_10_value(double result, FILE *ofp)
{
  if (result < 0)
  {
    printf("Error.\n");
    fprintf(ofp, "Error.\n");
  }
  else
  {
    printf("The log base 10 of %2.17lf = %2.17lf\n", result, log10(result));
    fprintf(ofp, "The log base 10 of %2.17lf = %2.17lf\n", result, log10(result));
  }
  return log10(result);
}

//This function does the math for the log base 2 part of the calculator
double log_2_value(double result, FILE *ofp)
{
  if (result < 0)
  {
    printf("Error.\n");
    fprintf(ofp, "Error.\n");
  }
  else
  {
    printf("The log of base 2 of %2.17lf = %2.17lf", result, log2(result));
    fprintf(ofp, "The log of base 2 of %2.17lf = %2.17lf", result, log2(result));
  }
  return log2(result);
}

//Save value to memory
int save(double *memory, int count, double value)
{
  count++;
  memory = realloc(memory, sizeof(double) * (count + 1));
  memory[count] = value;
  return count;
}

//First step
double first_step(FILE *ofp, double *memory, double *store, int count)
{
  while (1)
  {
    double value;
    char value_char[128];
    printf("\nPlease input a value: \n");
    fgets(value_char, 127, stdin);
    remove_crlf(value_char);

    fprintf(ofp, "%s\n", value_char);

    //Allow for pi input
    if (strcmp(value_char, "pi") == 0 || strcmp(value_char, "pie") == 0)
    {
      value = M_PI;
      memory[count] = value;
      return value;
      break;
    }
    //Allow for e input
    else if (strcmp(value_char, "e") == 0)
    {
      value = M_E;
      memory[count] = value;
      return value;
      break;
    }
    //Clear and print 0
    else if (strcmp(value_char, "c") == 0 || strcmp(value_char, "clear") == 0)
    {
      printf("0\n");
      fprintf(ofp, "0\n");
      first_step(ofp, memory, store, count);
      break;
    }
    //Exit the program and close file
    else if (strcmp(value_char, "q") == 0 || strcmp(value_char, "quit") == 0)
    {
      free(memory);
      fclose(ofp);
      exit(0);
    }
    //Clear all stored variables
    else if (strcmp(value_char, "ca") == 0 || strcmp(value_char, "clear all") == 0)
    {
      clear_all(ofp, store);
      printf("All memory has been cleared.\n");
      fprintf(ofp, "All memory has been cleared.\n");
      first_step(ofp, memory, store, count);
    }
    //Call back function to go back through the inputs and outputs
    else if (strcmp(value_char, "b") == 0 || strcmp(value_char, "back") == 0)
    {
      value = back(ofp, memory, store, count - 1);
      return value;
      break;
    }
    //Store last double in inputted location
    else if (strcmp(value_char, "sto") == 0 || strcmp(value_char, "store") == 0)
    {
      char temp[256];
      int input;
      printf("Please input a number 0-9.\n");
      fprintf(ofp, "Please input a number 0-9.\n");
      fgets(temp, 255, stdin);
      input = atoi(temp);

      if (input >= 0 && input <= 9)
      {
        printf("%lf has been stored in location %d.\n", memory[count], input);
        fprintf(ofp, "%lf has been stored in location %d.\n", memory[count], input);
        store[input] = memory[count];
        count = save(memory, count, store[input]);
      }
      else
      {
        printf("Error.\n");
        fprintf(ofp, "Error.\n");
      }
    }
    //Recall double from memory location
    else if (strcmp(value_char, "rcl") == 0 || strcmp(value_char, "recall") == 0)
    {
      char temp[256];
      int input;
      printf("Please input a number 0-9.\n");
      fprintf(ofp, "Please input a number 0-9.\n");
      fgets(temp, 255, stdin);
      input = atoi(temp);

      if (input >= 0 && input <= 9)
      {
        printf("%lf has been recalled from location %d.\n", store[input], input);
        fprintf(ofp, "%lf has been recalled from location %d.\n", store[input], input);
        count = save(memory, count, store[input]);
        return store[input];
        break;
      }
      else
      {
        printf("Error.\n");
        fprintf(ofp, "Error.\n");
      }
    }
    //Take input double
    else
    {
      value = atof(value_char);
      memory[count] = value;
      return value;
      break;
    }
  }
}

//Second step
void second_step(FILE *ofp, double *store, int count)
{
  char operations[256];
  double first;
  double second;
  double result;
  double *memory = malloc(sizeof(double));

  //Start by getting first number
  first = (first_step(ofp, memory, store, count));

  //Loop so the program continues
  while (1)
  {
    //This removed random 0 input's or computations I was getting
    if (memory[count] != 0)
    {
      first = memory[count];
    }

    //For debugging
    printf("memory[%d] = %lf", count, memory[count]);
    //Allocate memory for next inpuyt
    memory = realloc(memory, sizeof(double) * (count + 1));

    //Get operation
    printf("\nWhat operation do you want to use?\n");
    fgets(operations, 255, stdin);
    remove_crlf(operations);

    //Print out first value and operation to tape
    fprintf(ofp, "%lf\n", first);
    fprintf(ofp, "%s\n", operations);

    //Addition operation
    if (strcmp(operations, "+") == 0 || strcmp(operations, "addition") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * (count + 1));
      second = (first_step(ofp, memory, store, count));
      count = save(memory, count, (first + second));
      fprintf(ofp, "%lf\n", second);
      printf("The result of %2.17lf + %2.17lf = %2.17lf\n", first, second, first + second);
      fprintf(ofp, "The result of %2.17lf + %2.17lf = %2.17lf\n", first, second, first + second);
    }
    //Subtraction operation
    else if (strcmp(operations, "-") == 0 || strcmp(operations, "subtaction") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * (count + 1));
      second = (first_step(ofp, memory, store, count));
      count = save(memory, count, (first - second));
      fprintf(ofp, "%lf\n", second);
      printf("The result of %2.17lf - %2.17lf = %2.17lf\n", first, second, first - second);
      fprintf(ofp, "The result of %2.17lf - %2.17lf = %2.17lf\n", first, second, first - second);
    }
    //Multiplication operation
    else if (strcmp(operations, "x") == 0 || strcmp(operations, "multiplication") == 0 || strcmp(operations, "*") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * (count + 1));
      second = (first_step(ofp, memory, store, count));
      count = save(memory, count, (first * second));
      fprintf(ofp, "%lf\n", second);
      printf("The result of %lf x %2.17lf = %2.17lf\n", first, second, first * second);
      fprintf(ofp, "The result of %2.17lf x %2.17lf = %2.17lf\n", first, second, first * second);
    }
    //Division operation
    else if (strcmp(operations, "/") == 0 || strcmp(operations, "division") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * (count + 1));
      second = (first_step(ofp, memory, store, count));
      if (second == 0)
      {
        printf("Error.\n");
        fprintf(ofp, "Error.\n");
      }
      else
      {
        count = save(memory, count, (first / second));
        fprintf(ofp, "%lf\n", second);
        printf("The result of %2.17lf / %2.17lf = %2.17lf\n", first, second, first / second);
        fprintf(ofp, "The result of %2.17lf / %2.17lf = %2.17lf\n", first, second, first / second);
      }
    }
    //Exponentiation operation
    else if (strcmp(operations, "^") == 0 || strcmp(operations, "exponentiation") == 0)
    {
      second = (first_step(ofp, memory, store, count));
      count++;
      fprintf(ofp, "%lf\n", second);
      printf("The result of %2.17lf ^ %2.17lf = %2.17lf\n", first, second, pow(first, second));
      fprintf(ofp, "The result of %2.17lf ^ %2.17lf = %2.17lf\n", first, second, pow(first, second));
    }
    //Sine operation
    else if (strcmp(operations, "sin") == 0 || strcmp(operations, "sine") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, sine_value(first, ofp));
      first = sine_value(first, ofp);
    }
    //Cosine operation
    else if (strcmp(operations, "cos") == 0 || strcmp(operations, "cosine") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, cosine_value(first, ofp));
      first = cosine_value(first, ofp);
    }
    //Tangent operation
    else if (strcmp(operations, "tan") == 0 || strcmp(operations, "tangent") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, tangent_value(first, ofp));
      first = tangent_value(first, ofp);
    }
    //Inverse sine operation
    else if (strcmp(operations, "arcsin") == 0 || strcmp(operations, "inverse sine") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, inverse_sine_value(first, ofp));
      first = inverse_sine_value(first, ofp);
    }
    //Inverse cosine operation
    else if (strcmp(operations, "arccos") == 0 || strcmp(operations, "inverse cosine") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, inverse_cosine_value(first, ofp));
      first = inverse_cosine_value(first, ofp);
    }
    //Inverse tangent operation
    else if (strcmp(operations, "arctan") == 0 || strcmp(operations, "inverse tangent") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, inverse_tangent_value(first, ofp));
      first = inverse_tangent_value(first, ofp);
    }
    //Square roote operation
    else if (strcmp(operations, "root") == 0 || strcmp(operations, "square root") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, square_root_value(first, ofp));
      first = square_root_value(first, ofp);
    }
    //Absolute value operation
    else if (strcmp(operations, "abs") == 0 || strcmp(operations, "remove sign") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, absolute_value_value(first, ofp));
      first = absolute_value_value(first, ofp);
    }
    //Inverse operation
    else if (strcmp(operations, "inv") == 0 || strcmp(operations, "1/x") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, inverse_value(first, ofp));
      first = inverse_value(first, ofp);
    }
    //Log base 10 operation
    else if (strcmp(operations, "log") == 0 || strcmp(operations, "log10x") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, log_10_value(first, ofp));
      first = log_10_value(first, ofp);
    }
    //Log base 2 operation
    else if (strcmp(operations, "log2") == 0 || strcmp(operations, "log2x") == 0)
    {
      count++;
      memory = realloc(memory, sizeof(double) * count + 1);
      count = save(memory, count, log_2_value(first, ofp));
      first = log_2_value(first, ofp);
    }
    //Print 0 and ask for new number
    else if (strcmp(operations, "c") == 0 || strcmp(operations, "clear") == 0)
    {
      first = 0;
      printf("0\n");
      fprintf(ofp, "0\n");
      first_step(ofp, memory, store, count);
    }
    //Clear all memory stored
    else if (strcmp(operations, "ca") == 0 || strcmp(operations, "clear all") == 0)
    {
      clear_all(ofp, store);
      printf("All memory has been cleared.\n");
      fprintf(ofp, "All memory has been cleared.\n");
      first_step(ofp, memory, store, count);
    }
    //Back function to get previous input or computation
    else if (strcmp(operations, "b") == 0 || strcmp(operations, "back") == 0)
    {
      first = back(ofp, memory, store, count);
    }
    //Store last number in an inputted location
    else if (strcmp(operations, "sto") == 0 || strcmp(operations, "store") == 0)
    {
      char temp[256];
      int input;
      printf("Please input a number 0-9.\n");
      fprintf(ofp, "Please input a number 0-9.\n");
      fgets(temp, 255, stdin);
      input = atoi(temp);

      if (input >= 0 && input <= 9)
      {
        printf("%lf has been stored in location %d.\n", memory[count], input);
        fprintf(ofp, "%lf has been stored in location %d.\n", memory[count], input);
        store[input] = memory[count];
        count = save(memory, count, store[input]);
      }
      else
      {
        printf("Error.\n");
        fprintf(ofp, "Error.\n");
      }
    }
    //Recall memory from inputted location
    else if (strcmp(operations, "rcl") == 0 || strcmp(operations, "recall") == 0)
    {
      char temp[256];
      int input;
      printf("Please input a number 0-9.\n");
      fprintf(ofp, "Please input a number 0-9.\n");
      fgets(temp, 255, stdin);
      input = atoi(temp);

      if (input >= 0 && input <= 9)
      {
        printf("%lf has been recalled from location %d.\n", store[input], input);
        fprintf(ofp, "%lf has been recalled from location %d.\n", store[input], input);
        first = store[input];
        count = save(memory, count, store[input]);
      }
      else
      {
        printf("Error.\n");
        fprintf(ofp, "Error.\n");
      }
    }
    //Quit program by exiting while loop
    else if (strcmp(operations, "q") == 0 || strcmp(operations, "quit") == 0)
    {
      break;
    }
    //Invalid operation
    else
    {
      printf("You have enetered an Invalid Operator \n");
      fprintf(ofp, "You have enetered an Invalid Operator \n");
    }
  }

  //Free memory
  free(memory);
  fclose(ofp);
}

int main()
{
  double store[10];
  int count = 0;
  FILE *ofp = fopen("tape.txt", "w");

  //Initialize and start with second step which calls first step
  second_step(ofp, store, count);

  fclose(ofp);
  return 0;
}