#include "sensor-validate.h"
#include <cstddef>

int lastButOneIndex;
double* nextValue;

int funcpointercalc(double* nextValue)
{
if(nextValue != NULL)
{
  return 0;
}
else
{
    return 1;
}
  
}
int IndexCalculator( int numOfValues)
{
  lastButOneIndex = numOfValues - 1;
  return lastButOneIndex;
}
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
