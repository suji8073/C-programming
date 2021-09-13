#1.
#include <stdio.h>
int main(void)
{
    int score[5];//배열 선언
    for (int i = 0; i < 5; i++)
    {
        int num = 0;
        printf("%d, ", i + 1);
        printf("학생 점수(0^100) ? "); scanf("%d", &num);
        if (num < 0 || num>100)//0에서 100 사이가 아니면 다시 돌아감.
            i--;
        else
            score[i] = num; // 0에서 100사이이면 배열에 저장
    }
 
    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("%d, ", score[i]);
    printf("\n");
 
    int a = 0;//모든 점수 저장하는 배열
    int b = score[0], c = score[0];//b,c둘다 최저 최고 점수를 알아보기 위한 처음 배열의 입력값 저장
 
    for (int i = 0; i < 5; i++) {
        a += score[i];
        b = b >= score[i] ? b : score[i];
        c = c <= score[i] ? c : score[i];
    }
 
 
        printf("평균 점수 : %.2lf\n", (double)a/5);
        printf("최고 점수: %d, 최저 점수 : %d\n", b, c);
        return 0;
    
}
