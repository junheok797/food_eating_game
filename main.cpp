#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "game_object.h"
#include "human.h"
#include "monster.h"
#include "food.h"
using namespace std;

int max_x = 20;
int max_y = 10;

void setCursorPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setTextAttribute(string color = "white")
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "blue")
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	else if (color == "red")
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	else if (color == "green")
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	else if (color == "yellow")
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	else // white
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void initScreen()
{
	system("cls");

	// Food Game
	setCursorPosition(6, 0);
	std::cout << "Food Game" << std::endl;

	// 위쪽 테두리
	setCursorPosition(0, 1);
	std::cout << "┌";
	for (int i = 0; i < max_x; i++)
		std::cout << "─";
	std::cout << "┐";

	// 양쪽 테두리
	for (int i = 2; i < max_y + 3; i++)
	{
		setCursorPosition(0, i);
		std::cout << "│";
		setCursorPosition(max_x + 1, i);
		std::cout << "│";
	}

	// 아래쪽 테두리
	setCursorPosition(0, max_y + 2);
	std::cout << "└";
	for (int i = 0; i < max_x; i++)
		std::cout << "─";
	std::cout << "┘";

	// 안내문구
	setCursorPosition(0, 14);
	setTextAttribute("blue");
	std::cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f)" << std::endl;
	std::cout << "왼쪽(←), 아래(↓), 위(↑), 오른쪽(→)" << std::endl;
	std::cout << "종료하려면, ESC 또는 Q 키를 누르세요." << std::endl;
	setTextAttribute();
}

void draw(Human& h, Monster& m, Food& f, time_t& start_time)
{
	time_t current_time = time(NULL);
	int elapsed_time = static_cast<int>(current_time - start_time);

	setCursorPosition(1, 2);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (h.getX() == i && h.getY() == j)
			{
				setTextAttribute("blue");
				cout << h.getShape();
				setTextAttribute();
			}
			else if (m.getX() == i && m.getY() == j)
			{
				setTextAttribute("red");
				cout << m.getShape();
				setTextAttribute();
			}
			else if (f.getX() == i && f.getY() == j)
			{
				setTextAttribute("green");
				cout << f.getShape();
				setTextAttribute();
			}
			else cout << '-';
		}
		if (i != 9) setCursorPosition(1, 3 + i);
		else setCursorPosition(6, 4 + i);
	}
	setTextAttribute("yellow");
	cout << "시간: " << elapsed_time << "초";
	setTextAttribute();
	setCursorPosition(0, 17);
}

void update(Human& h, Monster& m, Food& f)
{
	h.move();
	m.move();
	f.move();
}

int main()
{
	bool running = true;
	time_t start_time = time(NULL);
	Human h(0, 0, 1);
	Monster m(5, 5, 2);
	Food f(8, 9, 1);

	initScreen();
	//draw(h, m, f);

	while (running)
	{
		draw(h, m, f, start_time);
		if (m.collide(h))
		{
			setCursorPosition(0, 18);
			cout << "Human is Loser!!" << endl << "인간이 몬스터에게 잡혔습니다." << endl << endl;
			running = false;
			break;
		}
		else if (m.collide(f))
		{
			setCursorPosition(0, 18);
			cout << "Human is Loser!!" << endl << "몬스터가 음식을 먹었습니다." << endl << endl;
			running = false;
			break;
		}
		else if (h.collide(f))
		{
			setCursorPosition(0, 18);
			cout << "Human is Winner!!" << endl << "인간이 음식을 먹었습니다." << endl << endl;
			running = false;
			break;
		}

		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 0 || ch == 224) {
				ch = _getch();
				switch (ch) {
				case 72: // 위쪽 화살표
					h.putkey('d');
					break;
				case 80: // 아래쪽 화살표
					h.putkey('s');
					break;
				case 75: // 왼쪽 화살표
					h.putkey('a');
					break;
				case 77: // 오른쪽 화살표
					h.putkey('f');
					break;
				default:
					break;
				}
			}
			else if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'f')
			{
				h.putkey(ch);
			}
			else if (ch == 'q' || ch == 'Q') {
				running = false;
			}
		}
		else
		{
			Sleep(1000);
			h.putkey('p');
		}
		update(h, m, f);
	}

	return 0;
}