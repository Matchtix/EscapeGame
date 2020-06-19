#pragma once

#include <iostream>
#include <conio.h>

using namespace std;

enum { FLS, KEY, EXIT, BLANK, DOOR, PLAYER, WALL }; //FLS �� FLASH, ������ 
enum { LU, UP, RU, LT, RT, LD, DN, RD }; //

extern int** map; //map, ������ �ֿܼ� �Լ��� main.cpp�� ���� 
extern void CursorView(char show);

//���� Ŭ����, ����� ���� 
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
		//2���� ÷�� ��ȯ���� ������ �ϴ� �������� ��   
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
		int sight, prevDirection; //�þ�, ���� �÷��̾� ���� 
		int normal_sight, itemMax, keyMax;
		int* item;
		char name[11];
		Tool* flashLight;
	public: 
		Player(char* playername, int playercolor) : normal_sight(4), itemMax(4), keyMax(3), prevDirection(UP) { //������, ����� �̸��� ������ �Ű������� ���� 
			strcpy_s(name, playername);
			flashLight = new FlashLight();
			item = new int[itemMax];
			for (int c = 0; c < itemMax; c++) item[c] = 0;
			direction = UP;
			ignore = BLANK;
			sight = normal_sight;
			color = playercolor;
		}
		~Player() { //�Ҹ��� 
			delete[] item;
			delete flashLight;
		}
		void Move(int ch); //Move �Լ� 
		void Reset(); //�ʱ�ȭ �Լ� 
		void PrintItemCount(); //�������� ���� ��� �Լ� 
		bool GetFlashLightStatus() { return flashLight->GetStatus(); }  
		int GetSight() {return sight;} 
		int GetItemMax() {return itemMax;}
		int GetPrevDirection() {return prevDirection;}
		void SetColor(int playercolor) {color = playercolor;}
		void BackUpDataInput() {prevDirection = direction;}
		void BackUpDataOutput() {direction = prevDirection;}	
};
class Map { //�� Ŭ���� 
	private: 
		int row, column; //���� ����, ���� ���� 20 
		Mover* player; //
		FILE* fp; //�� �ҷ������ ���� ������ 
	public:
		Map(Mover* a) : player(a), row(20), column(20), fp(NULL) { //���� ���鶧 Mover�� ���� ����, �� ũ��� ���� 20,���� 20���� ���� 
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
		~Map() { //�Ҹ��ڷ� �����Ҵ� ���� 
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
