#include <stdio.h>
#include <string.h>//strcmp함수를 출력하기 위함.
int main(void)
{
	char* emps[6][2] = { "김소미","서울 서초구 국립도서관",
					  "안재은","부산시 해운대",
					  "김원선", "서울시 강남구 역삼동 SDS 멀티 캠퍼스",
					  "진달래","속초시 대포항 바다 1번지",
					  "한송이","인천시 남구 새마을 아파트",
					  NULL,NULL };

	char name[10]; //검색할 성명을 저장하는 배열
	printf("검색할 성명 ? "); 
	gets(name);//name에 문자열을 입력받는다.
	//공백을 출력받도록 scanf 사용하지 않고 gets 사용

	for (int i = 0; i < 5; i++) 
	{
		if (strcmp(emps[i][0],name) == 0) { //emps[i][0]과 name이 같으면 0이 됨
			printf("\n%s, %s\n", name, emps[i][1]);//0이되면 출력
			return 0;//후 프로그램 종료
		}
	}
	printf("\n, 검색되지 않습니다\n"); //검색하지 못하면 이 문장 출력
	return 0;
}
