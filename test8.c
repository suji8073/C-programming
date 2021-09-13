#include <stdio.h>
typedef struct point
{
	int xpos;
	int ypos;
}Point;

void SwapPoint(Point* p)//배열의 p[0]와 p[1]에 저장된 x값과 y값을 서로 바꿔주는 함수 정의
{
	Point p1;
	p1 = p[0];
	p[0] = p[1];
	p[1] = p1;

}
void Showposition(Point* p)//출력을 도와주는 함수 정의
{
	for (int i = 0; i < 2; i++) {
		printf("[%d %d]\n", (p + i)->xpos, (p + i)->ypos);
	}
}

int main(void)
{
	Point pos[2];//변수 저장하는 배열
	printf("pos의 첫번째 변수 입력: "); scanf(" %d %d", &pos[0].xpos, &pos[0].ypos);
	printf("pos의 두번째 변수 입력: "); scanf(" %d %d", &pos[1].xpos, &pos[1].ypos);

	printf("변경전 \n");
	Showposition(&pos);//변경전 배열 출력
	SwapPoint(&pos);//배열에 저장된 값 교환
	printf("\n");
	printf("변경후 \n");
	Showposition(&pos);//변경 후 배열 출력
	return 0;
}
