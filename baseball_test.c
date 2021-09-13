#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int IsNewNum(int num, int arr[], int size); //�ߺ��� ���ڰ� �ִ��� Ȯ���ϴ� �Լ�
void ShowIntArr(int arr[], int size);//�迭 ����Ʈ�ϴ� �Լ�
int restart(char ch);//�ٽ� ������ϴ��� ���� �Լ�
int main()
{
	fputs("���� ���------\n", stdout);
	//fputs("�̸��� �Է��ϸ� ������ ���۵˴ϴ�.\n", stdout);//���� ����ü �־�� �ϴ� ��
	
	restart:
	printf("\n");
	fputs("���� ����!\n", stdout);

	int size;
	fputs("�ڸ��� �Է�(1~9 �� �Է½� ����): ", stdout);
	scanf_s(" %d", &size);//�ڸ��� �Է�	//1 2�� ���� ���� �Է��ϸ� ����
	if (size < 1 || size > 9)
	{
		fputs("����\n", stdout);//11 �Է��ص� ����
		return 0;
	}
	
	int RandNum[10];//�������� ������ ���ڰ� �� �迭
	for (int i = 0;; i++)
	{
		srand((unsigned int)time(NULL)); //���� ����
		int temp = rand() % 9 + 1; //�ּ� 1�ڸ�, �ִ� 9�ڸ�
		if (IsNewNum(temp, RandNum, size) == 0) //���ڰ� �ߺ����� �ʾ��� ���
			RandNum[i] = temp;//�迭�� ���ڰ� ��
		else //���ڰ� �ߺ��Ǿ��� ���
			i--; //�迭�� ���ڰ� ���Ե��� �ʾ� ���ڸ� �ٽ� �����ؾ� ��
		if (i == size - 1) //�迭�� �ڸ�����ŭ ���ڰ� ���� ���
			break; //�ݺ��� ��������
	}

	// Ȯ�ο�*******************
	printf("����: ");
	ShowIntArr(RandNum, size);
	// Ȯ�ο�*******************

		
	int count = 1;//��ȸ������ ���
	char ch;// ����� ����
	
	
	for (int i = 0;; i++)
	{
		int Answer[10] = {0};//�Է¹��� ���ڰ� �� �迭
		printf("\n[%dȸ�� ���� �Ʊ�]\n", count++);// �ݺ����� ���ư� �� ���� count ++
		
		printf("%d���� 1~9 ������ ���� �ٸ� ���ڸ� �Է�: ", size);
		for (int j = 0; j < size; j++) {
			int temp = 0;
		return_back:
			for (int k = 0; k < size; k++) {
				Answer[k] = '\0';
			}
			scanf_s(" %d", &temp); //���� �Է�
			if (temp < 1 || temp > 9)
			{
				printf("%d���� 1~9 ������ ���� �ٸ� ���ڸ� �Է��ؾ��� \n", size);
				printf("�ٽ� �Է� \n");
				j = 0;
				goto return_back;

			}
			if (IsNewNum(temp, Answer, size) == 0)//���ڰ� �ߺ����� �ʾ��� ���
				Answer[j] = temp;//�迭�� ���ڰ� ��
			else//���ڰ� �ߺ��Ǿ��� ���
			{
				fputs("���ڴ� �ߺ��ؼ� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.\n", stdout);
				//spacebar�� ���� ��Ÿ���� ������ ��µǴ� ���� ����
				//5�ڸ� ���ڸ� 1 1 1 1 1 2 2 3 4 5�� �Է��ϸ� 1 2 3 4 5�� �迭�� ���Ե�
				printf("�ٽ� �Է� \n");
				j = 0;
				goto return_back;

			}
			if (j == size - 1) {//�迭�� �ڸ�����ŭ ���ڰ� ���� ���
				break;//�ڸ��� �̻� ���ڸ� �Է����� �� �ڸ�����ŭ�� �迭�� �����ϰ� �ݺ��� ��������
			}
		}

		//������ �Է¹��� ���� ��
		int ball = 0;
		int strike = 0;
		for (int i = 0; i < size; i++)
		{
			if (Answer[i] == RandNum[i]) strike++; // �ڸ����� ���� ������ strike
			else if (IsNewNum(Answer[i], RandNum, size)) ball++; // ���ڰ� ���ԵǾ������� ball
		}
		// Ȯ�ο�*******************
		printf("���� �迭: ");
		ShowIntArr(Answer, size);
		// Ȯ�ο�*******************

		printf("%d strike, %d ball, %d out\n", strike, ball, size - strike - ball); //strike, ball,out ���� ���
		printf("------------------------------------------\n");
		if (strike == size) {//�ڸ����� strike���� ������ �¸�
			printf("���ӿ��� �¸��ϼ̽��ϴ�!!! \n");
			printf("�ٽ� ������ �����Ͻðڽ��ϱ�? Y/N : "); scanf_s(" %c", &ch);
			if (restart(ch) == 1) goto restart;//���� �������� ���ư�
			else return 0;//�ƴϸ� ���� ����
		}
	
		if (size <= 3) {//3�ڸ��� �����̸� ���� Ƚ��9ȸ�� ����
			if (i+1>= 9) {
				printf("���ӿ��� �й��ϼ̽��ϴ�.\n");
				printf("���� �迭: ");
				ShowIntArr(Answer, size);
				printf("�ٽ� ������ �����Ͻðڽ��ϱ�? Y/N : "); scanf_s(" %c", &ch);
				if (restart(ch) == 1)  goto restart;
				else return 0;
			}
		}
		else if (size >= 4) {// 4�ڸ��� �̻��̸� ����Ƚ�� 10(n-3)+9�� ����, �̶� n�� �ڸ���
			if (i + 1 >= 10 * (size - 3) + 9) {
				printf("���ӿ��� �й��ϼ̽��ϴ�.\n");
				printf("���� �迭: ");
				ShowIntArr(Answer, size);
				printf("�ٽ� ������ �����Ͻðڽ��ϱ�? Y/N : "); scanf_s(" %c", &ch);
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
		if (num == arr[i]) return 1; //���ڰ� �ߺ��Ǹ� 1 ����
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