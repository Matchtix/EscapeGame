#include "EscapeGame.h"
#include <windows.h> //윈도우 응용함수 사용을 위해 include

//맵 저장용 이중포인터, 전역 변수
int** map;

//입력 커서를 안보이게 하는 CursorView
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
//좌표를 옮겨주는 gotoxy 
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//색과 외곽선 값을 int로 받아 출력문의 색을 바꿔준다. (보통의 경우 enum으로 선언하므로) 
void setcolor(int color, int bgcolor) {
	    color &= 0xf;
	    bgcolor &= 0xf;
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//게임 실행용 메인 함수
int main() {
	EscapeGame escapegame;
	escapegame.GameRun();
	return 0;
}