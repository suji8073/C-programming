#include <stdio.h>
#include <math.h>

int power(int x, int y);
int main()
{
	int x, y;
	printf("정수 x를 입력하고 Enter>");
	scanf_s("%d", &x);
	printf("정수 y를 입력하고 Enter>");
	scanf_s("%d", &y);
	
	printf("x의 y승=%d\n", power(x, y));
	printf("y의 x승=%d\n", power(y, x));
}
int power(int x, int y)// int로 쓸 수 있는 pow함수
{
	int sum;//거듭제곱을 출력하는 변수
	sum = x;
	for (int i = 1; i < y; i++)//y번만큼
	{
		sum *= x;// x을 곱하기 sum에
	}
	return sum;
}
