#include <stdio.h>
typedef struct point
{
    int x;
    int y;
}POINT;
 
struct rectangle
{
    int width;
    POINT p[2];
};
int main(void)
{
    struct rectangle rect;
    POINT rightTop = { 7,10 };
    POINT leftDown = { 3,5 };
 
    rect.p[0] = rightTop;
    rect.p[1] = leftDown;
 
    int a;//가로
    int b;//세로
 
    if (rightTop.x <= leftDown.x)//  x의 크기 비교후 가로 길이를 a변수에 저장
        a = leftDown.x - rightTop.x;
    else
        a = rightTop.x - leftDown.x;
 
    if (rightTop.y <= leftDown.y)// y의 크기 비교후 세로 길이를 b변수에 저장
        b = leftDown.y - rightTop.y;
    else
        b = rightTop.y - leftDown.y;
 
    rect.width = a*b;//가로*세로를 넓이변수에 저장
 
    printf("가로:%d, 세로:%d, 사각형의 넓이 : %d이다\n", a, b, rect.width);
 
 
}
