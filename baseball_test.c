#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int IsNewNum(int num, int arr[], int size); //중복된 숫자가 있는지 확인하는 함수
void ShowIntArr(int arr[], int size);//배열 프린트하는 함수
int restart(char ch);//다시 재시작하는지 묻는 함수
int main()
{
	fputs("게임 방법------\n", stdout);
	//fputs("이름을 입력하면 게임이 시작됩니다.\n", stdout);//대충 구조체 넣어볼까 하는 중
	
	restart:
	printf("\n");
	fputs("게임 시작!\n", stdout);

	int size;
	fputs("자릿수 입력(1~9 외 입력시 종료): ", stdout);
	scanf_s(" %d", &size);//자릿수 입력	//1 2와 같이 공백 입력하면 오류
	if (size < 1 || size > 9)
	{
		fputs("종료\n", stdout);//11 입력해도 종료
		return 0;
	}
	
	int RandNum[10];//무작위로 선정된 숫자가 들어갈 배열
	for (int i = 0;; i++)
	{
		srand((unsigned int)time(NULL)); //난수 선정
		int temp = rand() % 9 + 1; //최소 1자리, 최대 9자리
		if (IsNewNum(temp, RandNum, size) == 0) //숫자가 중복되지 않았을 경우
			RandNum[i] = temp;//배열에 숫자가 들어감
		else //숫자가 중복되었을 경우
			i--; //배열에 숫자가 삽입되지 않아 숫자를 다시 선정해야 함
		if (i == size - 1) //배열에 자릿수만큼 숫자가 들어갔을 경우
			break; //반복문 빠져나옴
	}

	// 확인용*******************
	printf("난수: ");
	ShowIntArr(RandNum, size);
	// 확인용*******************

		
	int count = 1;//몇회차인지 출력
	char ch;// 재시작 여부
	
	
	for (int i = 0;; i++)
	{
		int Answer[10] = {0};//입력받은 숫자가 들어갈 배열
		printf("\n[%d회차 숫자 아구]\n", count++);// 반복문이 돌아갈 때 마다 count ++
		
		printf("%d개의 1~9 사이의 서로 다른 숫자를 입력: ", size);
		for (int j = 0; j < size; j++) {
			int temp = 0;
		return_back:
			for (int k = 0; k < size; k++) {
				Answer[k] = '\0';
			}
			scanf_s(" %d", &temp); //숫자 입력
			if (temp < 1 || temp > 9)
			{
				printf("%d개의 1~9 사이의 서로 다른 숫자를 입력해야함 \n", size);
				printf("다시 입력 \n");
				j = 0;
				goto return_back;

			}
			if (IsNewNum(temp, Answer, size) == 0)//숫자가 중복되지 않았을 경우
				Answer[j] = temp;//배열에 숫자가 들어감
			else//숫자가 중복되었을 경우
			{
				fputs("숫자는 중복해서 입력할 수 없습니다. 다시 입력하세요.\n", stdout);
				//spacebar로 공백 나타내면 여러번 출력되는 문제 있음
				//5자리 숫자를 1 1 1 1 1 2 2 3 4 5라 입력하면 1 2 3 4 5로 배열에 삽입됨
				printf("다시 입력 \n");
				j = 0;
				goto return_back;

			}
			if (j == size - 1) {//배열에 자릿수만큼 숫자가 들어갔을 경우
				break;//자릿수 이상 숫자를 입력했을 때 자릿수만큼만 배열에 삽입하고 반복문 빠져나옴
			}
		}

		//난수와 입력받은 숫자 비교
		int ball = 0;
		int strike = 0;
		for (int i = 0; i < size; i++)
		{
			if (Answer[i] == RandNum[i]) strike++; // 자리수와 숫자 같으면 strike
			else if (IsNewNum(Answer[i], RandNum, size)) ball++; // 숫자가 포함되어있으면 ball
		}
		// 확인용*******************
		printf("정답 배열: ");
		ShowIntArr(Answer, size);
		// 확인용*******************

		printf("%d strike, %d ball, %d out\n", strike, ball, size - strike - ball); //strike, ball,out 개수 출력
		printf("------------------------------------------\n");
		if (strike == size) {//자리수와 strike수가 같으면 승리
			printf("게임에서 승리하셨습니다!!! \n");
			printf("다시 게임을 시작하시겠습니까? Y/N : "); scanf_s(" %c", &ch);
			if (restart(ch) == 1) goto restart;//게임 시작으로 돌아감
			else return 0;//아니면 게임 종료
		}
	
		if (size <= 3) {//3자릿수 이하이면 게임 횟수9회로 제한
			if (i+1>= 9) {
				printf("게임에서 패배하셨습니다.\n");
				printf("정답 배열: ");
				ShowIntArr(Answer, size);
				printf("다시 게임을 시작하시겠습니까? Y/N : "); scanf_s(" %c", &ch);
				if (restart(ch) == 1)  goto restart;
				else return 0;
			}
		}
		else if (size >= 4) {// 4자릿수 이상이면 게임횟수 10(n-3)+9로 제한, 이때 n는 자릿수
			if (i + 1 >= 10 * (size - 3) + 9) {
				printf("게임에서 패배하셨습니다.\n");
				printf("정답 배열: ");
				ShowIntArr(Answer, size);
				printf("다시 게임을 시작하시겠습니까? Y/N : "); scanf_s(" %c", &ch);
				if (restart(ch) == 1)  goto restart;
				else return 0;
			}
		}
		
	}
	return 0;
}

int IsNewNum(int num, int arr[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
		if (num == arr[i]) return 1; //숫자가 중복되면 1 증가
	}
	return 0;
}

void ShowIntArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int restart(char ch)
{
	if (ch == 'Y')
		return 1;
	else if (ch == 'N')
		return 0;
}