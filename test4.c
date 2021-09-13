#include <stdio.h>
struct e1
{
	char a;
	int b;
	double c;
	char d;
};


struct e2
{
	char a;
	char d;
	int b;
	double c;
};

int main(void)
{
	struct e1 p1;
	printf("struct e1의 저장공간 크기 : %d\n", sizeof(p1));//24
	printf("주소 확인 ..\n");
	printf("%p %p %p %p \n", &p1.a, &p1.b, &p1.c, &p1.d);
	// 가장 큰 자료형의 크기의 배수로 정렬 : double형
	// 주소로 확인 ->8바이트를 맞추기 위해  char a 뒤에 3바이트 공백, char d뒤에 남는 공간에 7바이트 공백


	struct e2 p2;
	printf("struct e2의 저장공간 크기 : %d\n", sizeof(p2));
	printf("주소 확인 ..\n");
	printf("%p %p %p %p \n", &p2.a, &p2.d, &p2.b, &p2.c);
	// 가장 큰 자료형의 크기의 배수로 정렬 : double형
	// 주소로 확인 -> 8바이트를 맞추기 위해 char d 뒤에 2바이트 공백
	return 0;
}
