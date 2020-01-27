/*
	DoTheG.c : 두더지 잡기 게임
	2017-11-10  2016920059 최시열 & 2017 김진호
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void intro_game(void);      // 게임 시작화면 불러오는 함수
void gotoxy(int x, int y);      // 커서를 원하는 장소로 이동시켜주는 함수
void array_design(void);        // 게임 틀을 만들어주는 함수
void create_number(void);

int score;

int main(void)
{
	system("color F5");     // 흰색 배경에 보라색 글씨로 설정하였다.
	srand((unsigned)time(NULL));
	intro_game();
	system("cls");  // 시작화면을 지워주고 바로 게임창으로 넘어가는명령어
	create_number();
	system("cls");      // 이전 까지의 화면을 지워주고 최종점수 표시해줌
	printf("최종점수 : %d\n", score);
	return 0;
}

void intro_game(void)  // 게임 시작화면 불러오는 함수
{
	printf("☆☆☆ 두더지 잡기 게임 ☆☆☆\n\n");
	printf("[게임 규칙]\n");
	printf("1. 화면에 나오는 알파벳을 누르세요.\n");
	printf("2. 1초 안에 입력해야 합니다.\n");
	printf("3. 맞추면 +10점 // 틀리면 -5점\n\n");
	array_design();
	printf("Press Any Key to start\n");
	getch();
}

void array_design(void)  // 게임 틀을 만들어주는 함수
{
	printf("┌────────────┐\n");
	printf("│                        │\n");
	printf("│                        │\n");
	printf("│                        │\n");
	printf("│                        │\n");
	printf("│                        │\n");
	printf("│                        │\n");
	printf("│                        │\n");
	printf("└────────────┘\n\n");
}

void create_number(void)
{
	char key;
	int count = 0;
	while (count < 15)
	{
		system("cls");
		array_design();
		printf("\n\n현재점수 : %d점\n", score);
		int rnd1 = rand() % 4 * 4 + 3;
		int rnd2 = rand() % 4 * 2 + 2;
		gotoxy(rnd1, rnd2);
		char alpha = rand() % 26 + 97;
		printf("◎(%c)◎", alpha);
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
					printf("두더지 : 으악! ◎(X)◎");
					Sleep(1000);        // 제한시간을 1000(=1초)로 해서 1초 안에 답을 입력하게 함
					score += 10;
					break;
				}
				else
				{
					gotoxy(1, 11);
					printf("두더지 : 장님이냐? ◎(U)◎");
					Sleep(1000);
					score -= 5;
					break;
				}
			}
			if ((clock() - start) / CLOCKS_PER_SEC > 1.0f)
			{
				gotoxy(1, 11);
				printf("두더지 : 너무 느려~ ◎(U)◎");
				Sleep(500);
				score -= 5;
				break;
			}
		}
		count++;
	}
	return score;
}

void gotoxy(int x, int y)  // 커서를 원하는 장소로 이동시켜주는 함수
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

