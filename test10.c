#include <stdio.h>
int sumFunc(int count);//합계를 구하는 재귀함수 선언
int main()
{
    int n;//합계를 원하는 정수 저장
    printf("합계를 원하는 정수를 입력하세요: ");
    scanf("%d", &n);
    
    printf("%d 부터 %d 까지의 합 : %d\n", 1, n, sumFunc(n));
}
int sumFunc(int count)
{
    int sum=0;
    for (int i = 0; i <= count; i++)
    {
        sum += i;
    }
    return sum;
}
