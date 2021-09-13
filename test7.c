#include <stdio.h>
typedef struct person
{
	char name[20];
	char phoneNum[20];
	int age;
}Person;

void ShowPersonInfo(Person man)//출력
{
	printf("name : "); 
	fputs(man.name, stdout);
	//fgets을 사용하였기 때문에 입력 버퍼에는 데이터를 제외한 엔터가 남게됨.
	//따라서 fputs을 사용함으로써 굳이 줄바꿈인 \n을 해줄 필요가 없음.
	printf("phoneNum : "); 
	fputs(man.phoneNum, stdout);
	printf("age : %d\n", man.age);
}
Person ReadPersonInfo(void)
{
	Person man;
	printf("name? "); 
	fgets(man.name, sizeof(man.name), stdin);//스페이스바(띄어쓰기 및 공백)을 문자열에 포함하기 위해 scanf대신 fgets사용
	printf("phone? "); 
	fgets(man.phoneNum, sizeof(man.phoneNum), stdin);
	printf("age? "); scanf_s("%d", &man.age);
	return man; //구조체 변수 man이 통째로 반환
}
int main(void)
{
	Person man = ReadPersonInfo();
	putchar('\n');//줄바꿈
	ShowPersonInfo(man);
	return 0;
}
