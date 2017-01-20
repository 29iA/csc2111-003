#include "Random.h"

#include <time.h>
#include <stdlib.h>

void randomInit()
{
   srand (time(NULL));
}

int getRandomInt(int lower, int upper)
{
   int diff = upper - lower + 1;
   int random_num = rand()%diff;  
   random_num = random_num + lower;  //gives a number between lower and upper, inclusive
   return random_num;
}

float getRandomFloat(float lower, float upper)
{
   float r_float_1 = (float) rand();
   float r_float_2 = (float) RAND_MAX;

   float random_normalized = r_float_1/r_float_2;  //between 0.0 and 1.0
   float random_float = lower + random_normalized*(upper - lower);
   return random_float;
}
