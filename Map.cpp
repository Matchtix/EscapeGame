#include "EscapeGame.h"

extern int** map;
extern void setcolor(int color, int bgcolor);

//fopen_s �� �̿��ؼ� ������ �ҷ����� �Լ� 
void Map::Mapping(int level) {
	char str[4];
	
	if (level == 1) fopen_s(&fp, "Map1.txt", "r");
	else if (level == 2) fopen_s(&fp, "Map2.txt", "r");
	else if (level == 3) fopen_s(&fp, "Map3.txt", "r");
	else if (level == 4) fopen_s(&fp, "Map4.txt", "r");
	else if (level == 5) fopen_s(&fp, "Map5.txt", "r");
	else fp = NULL;
	
	//enum�� ���ؼ� �迭�� ���ڷ� ġȯ�Ǿ� �� 
	if (fp != NULL) {
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				fgets(str, 3, fp);
				
				if (strcmp(str, "��") == 0) map[i][j] = FLS;  //0
				else if (strcmp(str, "��") == 0) map[i][j] = KEY;  //1
				else if (strcmp(str, "��") == 0) map[i][j] = EXIT;  //2
				else if (strcmp(str, "  ") == 0) map[i][j] = BLANK; //3
				else if (strcmp(str, "��") == 0) map[i][j] = DOOR; //4
				else if (strcmp(str, "��") == 0) map[i][j] = WALL; //7
				else if (strcmp(str, "��") == 0) {
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

//Map�� ������� sight�� ���� ������ִ� �Լ� 
void Map::MapPrint(int level) { 
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			// ����� ���� �þ� ���� ���� �ִ� map �� ���� �� �ֵ��� �� 
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

//map�� ����� �迭�� MapPrint�� ��Ģ�� �ٶ� ������ִ� �Լ� 
void Map::MapPrintObject(int i, int j) {
	if (map[i][j] == WALL) {
		setcolor(8, 0);
		cout << "��";
	}
	else if (map[i][j] == KEY) {
		setcolor(6, 0);
		cout << "��";
	}
	else if (map[i][j] == DOOR) {
		setcolor(6, 0);
		cout << "��";
	} 
	else if (map[i][j] == EXIT) {
		setcolor(3, 0);
		cout << "��";
	}
	else if (map[i][j] == BLANK) {
		setcolor(0, 0);
		cout << "  ";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == UP) {
		setcolor(player->GetColor(), 0);
		cout << "��";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == LT) {
		setcolor(player->GetColor(), 0);
		cout << "��";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == DN) {
		setcolor(player->GetColor(), 0);
		cout << "��";
	}
	else if (map[i][j] == PLAYER && player->GetDirection() == RT) {
		setcolor(player->GetColor(), 0);
		cout << "��";
	}
	else if (map[i][j] == FLS) {
		setcolor(3, 0);
		cout << "��";
	}
}
