#include <stdio.h>
#pragma pack(1)
struct e1
{
	char a;//1
	int b;//4
	double c;//8
	char d;//1
};


struct e2
{
	char a;
	char d;
	int b;
	double c;
};

#pragma pack(pop)//정렬 설정을 기본값으로 되돌림
int main(void)
{
	struct e1 p1;
	printf("%d \n", sizeof(p1.a));//char는 1바이트
	printf("%d \n", sizeof(p1.b));//int는 4바이트
	printf("%d \n", sizeof(p1.c));//double는 8바이트
	printf("%d \n", sizeof(p1.d));//char는 1바이트
	printf("struct e1의 sizeof : %d\n", sizeof(p1));//총 14
	printf("주소 확인 ..\n");
	printf("%p %p %p %p \n", &p1.a, &p1.b, &p1.c, &p1.d);


	printf("\n");
	struct e2 p2;
	printf("%d \n", sizeof(p2.a));//char는 1바이트
	printf("%d \n", sizeof(p2.d));//char는 1바이트
	printf("%d \n", sizeof(p2.b));//int는 4바이트
	printf("%d \n", sizeof(p2.c));//double는 8바이트
	printf("struct e2의 sizeof : %d\n", sizeof(p2));//총 14
	printf("주소 확인 ..\n");
	printf("%p %p %p %p \n", &p2.a, &p2.d, &p2.b, &p2.c);


	return 0;
}
