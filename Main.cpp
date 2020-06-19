#include "EscapeGame.h"
#include <windows.h> //������ �����Լ� ����� ���� include

//�� ����� ����������, ���� ����
int** map;

//�Է� Ŀ���� �Ⱥ��̰� �ϴ� CursorView
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//��ǥ�� �Ű��ִ� gotoxy 
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���� �ܰ��� ���� int�� �޾� ��¹��� ���� �ٲ��ش�. (������ ��� enum���� �����ϹǷ�) 
void setcolor(int color, int bgcolor) {
	    color &= 0xf;
	    bgcolor &= 0xf;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//���� ����� ���� �Լ�
int main() {
	EscapeGame escapegame;
	escapegame.GameRun();
	return 0;
}