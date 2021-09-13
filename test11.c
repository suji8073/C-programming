#include <stdio.h>
#include <math.h>
 
int main()
{
    double x, y;
    printf("실수 x를 입력하고 Enter>");
    scanf("%lf", &x);
    printf("실수 y를 입력하고 Enter>");
    scanf("%lf", &y);
 
    printf("x의 y승=%lf\n", pow(x, y));
    printf("y의 x승=%lf\n", pow(y, x));
}
