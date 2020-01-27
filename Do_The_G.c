/*
	DoTheG.c : �δ��� ��� ����
	2017-11-10  2016920059 �ֽÿ� & 2017 ����ȣ
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void intro_game(void);      // ���� ����ȭ�� �ҷ����� �Լ�
void gotoxy(int x, int y);      // Ŀ���� ���ϴ� ��ҷ� �̵������ִ� �Լ�
void array_design(void);        // ���� Ʋ�� ������ִ� �Լ�
void create_number(void);

int score;

int main(void)
{
	system("color F5");     // ��� ��濡 ����� �۾��� �����Ͽ���.
	srand((unsigned)time(NULL));
	intro_game();
	system("cls");  // ����ȭ���� �����ְ� �ٷ� ����â���� �Ѿ�¸�ɾ�
	create_number();
	system("cls");      // ���� ������ ȭ���� �����ְ� �������� ǥ������
	printf("�������� : %d\n", score);
	return 0;
}

void intro_game(void)  // ���� ����ȭ�� �ҷ����� �Լ�
{
	printf("�١١� �δ��� ��� ���� �١١�\n\n");
	printf("[���� ��Ģ]\n");
	printf("1. ȭ�鿡 ������ ���ĺ��� ��������.\n");
	printf("2. 1�� �ȿ� �Է��ؾ� �մϴ�.\n");
	printf("3. ���߸� +10�� // Ʋ���� -5��\n\n");
	array_design();
	printf("Press Any Key to start\n");
	getch();
}

void array_design(void)  // ���� Ʋ�� ������ִ� �Լ�
{
	printf("����������������������������\n");
	printf("��                        ��\n");
	printf("��                        ��\n");
	printf("��                        ��\n");
	printf("��                        ��\n");
	printf("��                        ��\n");
	printf("��                        ��\n");
	printf("��                        ��\n");
	printf("����������������������������\n\n");
}

void create_number(void)
{
	char key;
	int count = 0;
	while (count < 15)
	{
		system("cls");
		array_design();
		printf("\n\n�������� : %d��\n", score);
		int rnd1 = rand() % 4 * 4 + 3;
		int rnd2 = rand() % 4 * 2 + 2;
		gotoxy(rnd1, rnd2);
		char alpha = rand() % 26 + 97;
		printf("��(%c)��", alpha);
		clock_t start = clock();
		while (1)
		{
			gotoxy(1, 10);
			if (kbhit())
			{
				key = getch();
				start = clock();
				if (key == alpha)
				{
					gotoxy(1, 11);
					printf("�δ��� : ����! ��(X)��");
					Sleep(1000);        // ���ѽð��� 1000(=1��)�� �ؼ� 1�� �ȿ� ���� �Է��ϰ� ��
					score += 10;
					break;
				}
				else
				{
					gotoxy(1, 11);
					printf("�δ��� : ����̳�? ��(U)��");
					Sleep(1000);
					score -= 5;
					break;
				}
			}
			if ((clock() - start) / CLOCKS_PER_SEC > 1.0f)
			{
				gotoxy(1, 11);
				printf("�δ��� : �ʹ� ����~ ��(U)��");
				Sleep(500);
				score -= 5;
				break;
			}
		}
		count++;
	}
	return score;
}

void gotoxy(int x, int y)  // Ŀ���� ���ϴ� ��ҷ� �̵������ִ� �Լ�
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

