#include "EscapeGame.h"

extern int** map;
extern void gotoxy(int x, int y);

//사용자의 키보드 입력에 따라 상하좌우 이동함 
void Player::Move(int ch) { 
	if (ch == 'w') { //w 입력시 상 
		if (map[y - 1][x] <= BLANK) {
			direction = UP;
			prevDirection = UP;
			Walk(x, y - 1); 
			y--;
		}
		else direction = UP;   
	}
	else if (ch == 'a') { //a 입력시 좌 
		if (map[y][x - 1] <= BLANK) {
			direction = LT;
			prevDirection = LT;
			Walk(x - 1, y); 
			x--;
		}
		else direction = LT;
	}
	else if (ch == 's') { //s 입력시 하 
		if (map[y + 1][x] <= BLANK) {
			direction = DN;
			prevDirection = DN;
			Walk(x, y + 1);
			y++;
		}
		else direction = DN;
	}
	else if (ch == 'd') { //d 입력시 우 
		if (map[y][x + 1] <= BLANK) {
			direction = RT;
			prevDirection = RT;
			Walk(x + 1, y);
			x++;
		}
		else direction = RT;
	}
	else if (ch == 'z') { //Z 입력시 해당 위치에 손전등이 있다면 손전등의 보유 수치를 1증가시키고 그 자리를 BLANK로 바꿈 
		if (ignore == FLS&&item[FLS] < 1) {
			item[FLS] = 1; //손전등 최대 보유 수량은 1로 고정 
			ignore = BLANK;
		}
		else if (ignore == KEY&&item[KEY] < keyMax) { //열쇠의 경우에도 마찬가지, 3개까지 보유 가능 
			item[KEY]++; 
			ignore = BLANK;
		}
	}
	else if (ch == 'f'&&item[FLS] == 1 && flashLight->GetStatus() == false) { //f 입력시 손전등을 가지고 있다면 sight=6이 된다. 
		sight = flashLight->ON();
	}
	
	else if (ch == 'f'&&item[FLS] == 1 && flashLight->GetStatus() == true) { //다시 f 입력시 손전등을 끌 수 있다. sight=4가 된다. 
		sight = normal_sight;  
		flashLight->OFF();
	}
	else if (ch == 'k'&&item[KEY] > 0) { //k 입력시 열쇠를 가지고 있고 
		if (direction == UP) { // 그 방향이 위쪽이며 
			if (map[y - 1][x] == DOOR) {  //그 방향에 문이 있을시 
				item[KEY]--;
				direction = UP;
				prevDirection = UP;
				Walk(x, y - 1);
				y--;
				ignore = BLANK; //move와 같이 처리하여 그 문의 자리로 이동한다. 문은 BLANK로 바뀐다. 
			}
			else direction = UP;
		}
		else if (direction == LT) {
			if (map[y][x - 1] == DOOR) {
				item[KEY]--;
				direction = LT;
				prevDirection = LT;
				Walk(x - 1, y);
				x--;
				ignore = BLANK;
			}
			else direction = LT;
		}
		else if (direction == DN) {
			if (map[y + 1][x] == DOOR) {
				item[KEY]--;
				direction = DN;
				prevDirection = DN;
				Walk(x, y + 1);
				y++;
				ignore = BLANK;
			}
			else direction = DN;
		}
		else if (direction == RT) {
			if (map[y][x + 1] == DOOR) {
				item[KEY]--;
				direction = RT;
				prevDirection = RT;
				Walk(x + 1, y);
				x++;
				ignore = BLANK;
			}
			else direction = RT;
		}
	}
}
void Player::Reset() { //Reset 함수는 sight, ignore 값, 손전등 켜져있는지 여부, 모든 아이템을 초기화한다. 
	sight = normal_sight;
	ignore = BLANK;
	flashLight->OFF();
	for (int i = 0; i < itemMax - 2; i++) {
		item[i] = 0;
	}
}
void Player::PrintItemCount() { //게임 화면에서 사용자가 가지고 있는 아이템을 보여주는 함수 
	gotoxy(43, 3);
	cout << "ⓕ 손전등 : " << item[FLS] << "개";
	gotoxy(43, 5);
	cout << " 열쇠  : " << item[KEY] << "개";
	gotoxy(43, 12);
	cout << "게임 방법을 보고 싶으시면 9를 눌러주세요.";
	gotoxy(43, 14);
	cout << "옵션을 보고 싶으시면 0를 눌러주세요.";
}
