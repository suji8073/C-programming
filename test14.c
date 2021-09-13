#include <stdio.h>
int main(void)
{
    int s[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        printf("0^9 사이의 숫자 한번씩 입력하기 %d번째:",i+1);
        scanf_s("%d",&s[i]);//입력받은 값 차례대로 배열에 저장
    }
    printf("정렬 전 배열 a ==>");
    for (int i = 0; i < 10; i++)
        printf("%d ", s[i]);
    printf("\n");
    
    int num;//최소값 저장하는 변수
    
    for (int j = 0; j <10; j++) {//배열의 작은 인덱스부터 비교하여 작은 값을 저장, 큰값 또 비교
        for (int i = j + 1; i <10; i++)
        {
            if (s[j] > s[i])
            {
                num = s[i];
                s[i] = s[j];
                s[j] = num;
            }
        }
    }
    printf("정렬 후 배열 a ==>");
    for (int i = 0; i < 10; i++)
        printf("%d ", s[i]);
    printf("\n");
 
}
