#include <stdio.h>
 
struct point //구조체 point의 정의
{
    int xpos;
    int ypos;
};
 
int main(void)
{
    struct point pos1, pos2;
    int s;
    int p1, p2;
    fputs("(x,y) 좌표 입력: ", stdout);
    scanf("%d %d", &pos1.xpos, &pos1.ypos);
 
    fputs("다른 (x,y) 좌표 입력: ", stdout);
    scanf("%d %d", &pos2.xpos, &pos2.ypos);
 
    if (pos1.xpos > pos2.xpos)//2개의 x좌표중 크기 비교하여 큰 값에서 작은 값 빼기
        p1 = pos1.xpos - pos2.xpos;
    else
        p1= pos2.xpos - pos1.xpos;
 
    if (pos1.ypos > pos2.ypos)//2개의 y좌표중 크기 비교하여 큰 값에서 작은 값 빼기
        p2 = pos1.ypos - pos2.ypos;
    else
        p2 = pos2.ypos - pos1.ypos;
    
    s = p1*p2;
    printf("직사각형의 넓이 :%d\n", s);
    return 0;
}
