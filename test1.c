#include <stdio.h>
#include <string.h>

struct stu
{
	int hak;//학번
	char name[20];//이름
};


struct ce
{
	struct stu a;
	char grade;//학년
};


int main()
{
	struct ce p1;

	printf("학년 입력 : "); scanf("%c", &(p1.grade));
	printf("학번 입력 : "); scanf("%d", &(p1.a.hak));
	printf("이름 입력 : "); scanf("%s", p1.a.name);



	printf("학년 : %c \n", p1.grade);
	printf("학번 : %d \n", p1.a.hak);
	printf("이름 : %s \n", p1.a.name);

	return 0;
}
