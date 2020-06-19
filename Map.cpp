#include "EscapeGame.h"

extern int** map;
extern void setcolor(int color, int bgcolor);

//fopen_s 를 이용해서 파일을 불러오는 함수 
void Map::Mapping(int level) {
	char str[4];
	
	if (level == 1) fopen_s(&fp, "Map1.txt", "r");
	else if (level == 2) fopen_s(&fp, "Map2.txt", "r");
	else if (level == 3) fopen_s(&fp, "Map3.txt", "r");
	else if (level == 4) fopen_s(&fp, "Map4.txt", "r");
	else if (level == 5) fopen_s(&fp, "Map5.txt", "r");
	else fp = NULL;
	
	//enum에 의해서 배열에 숫자로 치환되어 들어감 
	if (fp != NULL) {
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				fgets(str, 3, fp);
				
				if (strcmp(str, "ⓕ") == 0) map[i][j] = FLS;  //0
				else if (strcmp(str, "ⓚ") == 0) map[i][j] = KEY;  //1
				else if (strcmp(str, "ⓔ") == 0) map[i][j] = EXIT;  //2
				else if (strcmp(str, "  ") == 0) map[i][j] = BLANK; //3
				else if (strcmp(str, "ⓓ") == 0) map[i][j] = DOOR; //4
				else if (strcmp(str, "■") == 0) map[i][j] = WALL; //7
				else if (strcmp(str, "▲") == 0) {
					map[i][j] = PLAYER; //6
					player->SetX(j);
					player->SetY(i);
				}
			}
			fgetc(fp);
		}
	}
	fclose(fp);
	player->BackUpDataInput();
}

//Map을 사용자의 sight에 따라 출력해주는 함수 
void Map::MapPrint(int level) { 
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			// 사용자 기준 시야 범위 내에 있는 map 만 보일 수 있도록 함 
			if (sqrt(pow(i - player->GetY(), 2) + pow(j - player->GetX(), 2)) <= player->GetSight()) {
				MapPrintObject(i, j);
			}
			else cout << "  ";
		}
		cout << endl;
	}
	setcolor(7, 0);

	player->PrintItemCount();
	cout << endl;
}

//map에 저장된 배열을 MapPrint의 규칙에 다라 출력해주는 함수 
void Map::MapPrintObject(int i, int j) {
	if (map[i][j] == WALL) {
		setcolor(8, 0);
		cout << "■";
	}
	else if (map[i][j] == KEY) {
		setcolor(6, 0);
		cout << "ⓚ";
	}
	else if (map[i][j] == DOOR) {
		setcolor(6, 0);
		cout << "ⓓ";
	} 
	else if (map[i][j] == EXIT) {
		setcolor(3, 0);
		cout << "ⓔ";
	}
	else if (map[i][j] == BLANK) {
		setcolor(0, 0);
		cout << "  ";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == UP) {
		setcolor(player->GetColor(), 0);
		cout << "▲";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == LT) {
		setcolor(player->GetColor(), 0);
		cout << "◀";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == DN) {
		setcolor(player->GetColor(), 0);
		cout << "▼";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == RT) {
		setcolor(player->GetColor(), 0);
		cout << "▶";
	}
	else if (map[i][j] == FLS) {
		setcolor(3, 0);
		cout << "ⓕ";
	}
}
