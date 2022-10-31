/*****+---*----**-*-------*---***-**-*--***-*--*****************************
 *
 *  Homework #:05
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source,
 *  either modified or unmodified.  Neither have I provided access to my code
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: Uses a series of randomly generated codes with parameters input by the user in order to calculate the maximum value of the digits produced
 *
 ******+---*----**-*-------*---***-**-*--***-*--****************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LOOPMAX 20

void input(int* seedValue, int* powerLimit);
void processCodes(int seedValue, int powerLimit, int *max, int *min, int *maxIndex, int *minIndex);
int generateCode(int ceiling);
int calcSum(int code);
void printOutput(int max, int maxIndex, int min, int minIndex);

int main(void)
{
  int seedValue; // The value of the seed input by the user (used in srand())
  int powerLimit; // The value of the power limit input by the user, controls 10^powerLimit
  int max;  // The maximum value produced
  int min;  // The minimum value produced
  int maxIndex; // The index of the maximum value
  int minIndex; // The index of the minimum value

  input(&seedValue, &powerLimit);
  srand(seedValue);

  processCodes(seedValue, powerLimit, &max, &min, &maxIndex, &minIndex);

  printOutput(max, maxIndex, min, minIndex);
  return 0;
}

/*****+-*-----**--*-*-*-*-*-*--*---****--**-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: processCodes
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int seedValue - the value of the seed input by the user
 *    2. int powerLimit - the value of the power limit input by the user
 *    3. int* max - pointer to the maximum sum produced
 *    4. int* min - pointer to the minimum sum produced
 *    5. int* maxIndex - pointer to the index of the maximum sum
 *    6. int* minIndex - pointer to the index of the minimum sum
 *  Function Description: Creates and sums a total of LOOPMAX codes and finds the maximum and minimum
 *
 ******+-*-----**--*-*-*-*-*-*--*---****--**-*--****************************/
void processCodes(int seedValue, int powerLimit, int* max, int* min, int* maxIndex, int* minIndex)
{ 
  int i; // Used as iterator
  int sum;  // Keeps track of total sum
  int code; // Value of randomly generated code

  code = generateCode(powerLimit);
  *max = calcSum(code);
  *min = calcSum(code);
  *maxIndex = 1;
  *minIndex = 1;

  for(i = 0; i < LOOPMAX - 1; i++)
  {
    code = generateCode(powerLimit);
    printf("\n%d\n",code);
    
    sum = calcSum(code);

    if(sum > *max)
    {
      *max = sum;
      *maxIndex = i + 1;
    } else if(sum < *min)
    {
      *min = sum;
      *minIndex = i + 1;
    }
  }
}

/*****+-*-----**--*-*-*-*-*-*--*---****--**-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: calcSum
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int code - represents the code to be processsed
 *
 *  Function Description: Calculates the total of the digits of a number (code)
 *
 ******+-*-----**--*-*-*-*-*-*--*---****--**-*--****************************/

int calcSum(int code)
{
  int sum; // Value to be returned, keeps track of total sum of digits in code
  sum = 0;

  do
  {
    sum += code % 10;
    code /= 10;
  } while (code > 0);

  return sum;
}

/*****+-*-----**--*-*-*-*-*-*--*---****--**-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: input
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int* seedValue - the seed input by the user
 *    2.int* powerLimit - the power limit (base 10) input by the user
 *
 *  Function Description: Takes input from the user and stores it in variables
 *
 ******+-*-----**--*-*-*-*-*-*--*---****--**-*--****************************/

void input(int* seedValue, int* powerLimit)
{
  printf("Enter the seed value -> ");
  scanf("%d", seedValue);
  printf("Enter the power of 10 limit -> ");
  scanf("%d", powerLimit);
  *powerLimit = (int) pow(10, *powerLimit);
}

/*****+-*-----**--*-*-*-*-*-*--*---****--**-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: generateCode
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.int ceiling - represents the highest number that can be generated by the code 
 *
 *  Function Description: Generates a random code of maximum 'ceiling'
 *
 ******+-*-----**--*-*-*-*-*-*--*---****--**-*--****************************/

int generateCode(int ceiling)
{
  return (rand() % (ceiling) + 1);
}

/*****+-*-----**--*-*-*-*-*-*--*---****--**-*--*****************************
 *
 *  Function Information
 *
 *  Name of Function: printOutput
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int max - the maximum value produced
 *    2. int min - the minimum value produced
 *    3. int maxIndex - the index of the maximum value
 *    4. int minIndex - the index of the minimum value 
 *  Function Description: Prints the required output
 *
 ******+-*-----**--*-*-*-*-*-*--*---****--**-*--****************************/

void printOutput(int max, int maxIndex, int min, int minIndex)
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nSmallest Sum #%d:%4d", minIndex, min);
  printf("\nLargest Sum #%d:%5d", maxIndex, max);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-");
}