#include <stdio.h>
struct e1
{
	int a;
	char b[5];
	char c;
};


struct e2
{
	struct e1 aa;
	char bb;   //int, double일 때도 확인해보기
};

struct e2_1
{
	struct e1 aa;
	int bb;   //int, double일 때도 확인해보기
};
struct e2_2
{
	struct e1 aa;
	double bb;   //int, double일 때도 확인해보기
};


int main(void)
{
	struct e1 p1;
	printf("struct e1의 저장공간 크기 : %d\n", sizeof(p1));
	printf("주소 확인 ..\n");
	printf("%p %p %p\n", &p1.a, &p1.b, &p1.c);
	// 가장 큰 자료형의 크기의 배수로 정렬 : int형
	// 주소로 확인 -> 공백 char c 뒤에 4바이트를 맞추기 위해 남는 공간에 2바이트가 더 들어감. 

	struct e2 p2;
	printf("struct e2의 저장공간 크기 : %d\n", sizeof(p2));
	printf("주소 확인 ..\n");
	printf("%p %p \n", &p2.aa,&p2.bb);
	// 가장 큰 자료형의 크기의 배수로 정렬 : int형
	// 주소로 확인 -> 공백 char bb 뒤에 4바이트를 맞추기 위해 남는 공간에 3바이트가 더 들어감. 

	struct e2_1 p2_1;
	printf("struct e2의 저장공간 크기 : %d\n", sizeof(p2_1));
	printf("주소 확인 ..\n");
	printf("%p %p \n", &p2_1.aa, &p2_1.bb);
	// 가장 큰 자료형의 크기의 배수로 정렬 : int형
	// 주소로 확인 -> 공백 없음.

	struct e2_2 p2_2;
	printf("struct e2의 저장공간 크기 : %d\n", sizeof(p2_2));
	printf("주소 확인 ..\n");
	printf("%p %p \n", &p2_2.aa, &p2_2.bb);
	// 가장 큰 자료형의 크기의 배수로 정렬 : double형
	// 주소로 확인 -> 공백 struct e1 aa 뒤에 8바이트를 맞추기 위해 남는 공간에 4바이트가 더 들어감. 
	return 0;
}
