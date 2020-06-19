#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

enum { FLS, KEY, EXIT, BLANK, DOOR, PLAYER, WALL }; //FLS 는 FLASH, 손전등 
enum { LU, UP, RU, LT, RT, LD, DN, RD }; //

extern int** map; //map, 윈도우 콘솔용 함수는 main.cpp에 있음 
extern void CursorView(char show);

//도구 클래스, 손전등만 구현 
class Tool {
	protected:
		int sight;
		bool status;
	public:
		int ON() {
			status = true;
			return sight;
		}
		void OFF() {
			status = false;
		}
		bool GetStatus() {
			return status;
		}
}; 
class FlashLight : public Tool {
	public:
		FlashLight() {
			sight = 6;
			status = false;
		}
};

 
class Mover {
	protected:
		int x, y, direction, ignore, color;
	public:
		//2차원 첨자 교환으로 가고자 하는 방향으로 감   
		void Walk(int mover_x, int mover_y) {
			int temp = map[mover_y][mover_x];
			map[mover_y][mover_x] = map[y][x];
			map[y][x] = ignore;
			ignore = temp;
		}
		virtual void Move(int ch) = 0;
		virtual ~Mover() {}
		int GetX() {return x;}
		int GetY() {return y;}
		int GetDirection() {return direction;}
		int GetIgnore() {return ignore;}
		int GetColor() {return color;}
		virtual void Reset() {}
		virtual void BackUpDataInput() {}		
		virtual void BackUpDataOutput() {}
		virtual int GetPrevDirection() {return direction;}
		virtual int GetSight() {return 3;}
		virtual void PrintItemCount() {}
		void SetIgnore(int mover_ignore) {ignore = mover_ignore;}
		void SetX(int mover_x) {x = mover_x;}
		void SetY(int mover_y) {y = mover_y;}
		virtual void SetColor(int mover_color) {color = mover_color;}
};

class Player : public Mover {
	private:
		int sight, prevDirection; //시야, 이전 플레이어 방향 
		int normal_sight, itemMax, keyMax;
		int* item;
		char name[11];
		Tool* flashLight;
	public: 
		Player(char* playername, int playercolor) : normal_sight(4), itemMax(4), keyMax(3), prevDirection(UP) { //생성자, 사용자 이름과 색깔을 매개변수로 받음 
			strcpy_s(name, playername);
			flashLight = new FlashLight();
			item = new int[itemMax];
			for (int c = 0; c < itemMax; c++) item[c] = 0;
			direction = UP;
			ignore = BLANK;
			sight = normal_sight;
			color = playercolor;
		}
		~Player() { //소멸자 
			delete[] item;
			delete flashLight;
		}
		void Move(int ch); //Move 함수 
		void Reset(); //초기화 함수 
		void PrintItemCount(); //보유중인 도구 출력 함수 
		bool GetFlashLightStatus() { return flashLight->GetStatus(); }  
		int GetSight() {return sight;} 
		int GetItemMax() {return itemMax;}
		int GetPrevDirection() {return prevDirection;}
		void SetColor(int playercolor) {color = playercolor;}
		void BackUpDataInput() {prevDirection = direction;}
		void BackUpDataOutput() {direction = prevDirection;}	
};
class Map { //맵 클래스 
	private: 
		int row, column; //맵의 가로, 세로 각각 20 
		Mover* player; //
		FILE* fp; //맵 불러오기용 파일 포인터 
	public:
		Map(Mover* a) : player(a), row(20), column(20), fp(NULL) { //맵을 만들때 Mover로 부터 만듬, 맵 크기는 가로 20,세로 20으로 제한 
			map = new int*[column];
			for (int i = 0; i < column; i++) {
				map[i] = new int[row];
			}
			for (int i = 0; i < column; i++) {
				for (int j = 0; j < row; j++) {
					map[i][j] = 0;
				}
			}
		}
		~Map() { //소멸자로 동적할당 해제 
			for (int i = 0; i < row; i++) {
				delete[] map[i];
			}
			delete[] map;
		}
		void Mapping(int level);
		void MapPrint(int level);
		void MapPrintObject(int i, int j);
};

class EscapeGame {
	private:
		int level, maxlevel, playercolor;
		bool turn;
		char name[11];
		Mover* player;
		Map* map;
		FILE* fp;
	public:
		EscapeGame() : level(1), maxlevel(5), turn(false), fp(NULL), playercolor(2) {
			player = 0;
			map = 0;
			CursorView(0);
		}
		void StartScreen();
		void MapScreen();
		void InfoScreen();
		void PlayerName();
		void GameRun();
		void Option();
		void GameStatusCheck();
};
