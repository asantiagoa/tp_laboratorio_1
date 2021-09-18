#include "libCalc.h"
#include <stdio.h>
#include <stdlib.h>

float calcSum(float x, float y)
{
    float totalSum;
    totalSum = x + y;
    return totalSum;
}
float calcRes(float x, float y)
{
    float totalRes;
    totalRes = x - y;
    return totalRes;
}
float calcMult(float x, float y)
{
    float totalMult;
    totalMult = x * y;
    return totalMult;
}
float calcDiv(float x, float y)
{
    float totalDiv;
    totalDiv = x / y;
    return totalDiv;
}
int calcFact(float x)
{
    int i1;
    int factNum1 = 1;
        for(i1=1;i1<=(int)x;i1++)
        {
            factNum1 = factNum1 * i1;
        }
    return factNum1;
}
