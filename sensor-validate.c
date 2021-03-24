#include "sensor-validate.h"

int lastButOneIndex;
double* nextValue;

/* FUNCTION TO CHECK IF THE POINTER VALUE IS NULL*/
int funcpointercalc(double* nextValue)
{
if(nextValue != NULL) ? return 0 : return 1 ;
  
}

/* FUNCTION TO CALCULATE THE INDEX TO AVOID DUPLICATION*/
int IndexCalculator( int numOfValues)
{
  lastButOneIndex = numOfValues - 1;
  return lastButOneIndex;
}

/*FUNCTION RENAMED TO VALIDATE TOLERANCE RANGE*/
int toleranceRangeValidation(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateSOCreadings(double* values, int numOfValues) {
  IndexCalculator(numOfValues);
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!toleranceRangeValidation(values[i], values[i + 1], 0.05)) {
      return 0;
    }
  }
  return 1;
}

int validateCurrentreadings(double* values, int numOfValues) {
  IndexCalculator(numOfValues);
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!toleranceRangeValidation(values[i], values[i + 1], 0.1)) {
      return 0;
    }
  }
  return 1;
}
