#include "EscapeGame.h"

extern int** map;
extern void gotoxy(int x, int y);

//������� Ű���� �Է¿� ���� �����¿� �̵��� 
void Player::Move(int ch) { 
	if (ch == 'w') { //w �Է½� �� 
		if (map[y - 1][x] <= BLANK) {
			direction = UP;
			prevDirection = UP;
			Walk(x, y - 1); 
			y--;
		}
		else direction = UP;   
	}
	else if (ch == 'a') { //a �Է½� �� 
		if (map[y][x - 1] <= BLANK) {
			direction = LT;
			prevDirection = LT;
			Walk(x - 1, y); 
			x--;
		}
		else direction = LT;
	}
	else if (ch == 's') { //s �Է½� �� 
		if (map[y + 1][x] <= BLANK) {
			direction = DN;
			prevDirection = DN;
			Walk(x, y + 1);
			y++;
		}
		else direction = DN;
	}
	else if (ch == 'd') { //d �Է½� �� 
		if (map[y][x + 1] <= BLANK) {
			direction = RT;
			prevDirection = RT;
			Walk(x + 1, y);
			x++;
		}
		else direction = RT;
	}
	else if (ch == 'z') { //Z �Է½� �ش� ��ġ�� �������� �ִٸ� �������� ���� ��ġ�� 1������Ű�� �� �ڸ��� BLANK�� �ٲ� 
		if (ignore == FLS&&item[FLS] < 1) {
			item[FLS] = 1; //������ �ִ� ���� ������ 1�� ���� 
			ignore = BLANK;
		}
		else if (ignore == KEY&&item[KEY] < keyMax) { //������ ��쿡�� ��������, 3������ ���� ���� 
			item[KEY]++; 
			ignore = BLANK;
		}
	}
	else if (ch == 'f'&&item[FLS] == 1 && flashLight->GetStatus() == false) { //f �Է½� �������� ������ �ִٸ� sight=6�� �ȴ�. 
		sight = flashLight->ON();
	}
	
	else if (ch == 'f'&&item[FLS] == 1 && flashLight->GetStatus() == true) { //�ٽ� f �Է½� �������� �� �� �ִ�. sight=4�� �ȴ�. 
		sight = normal_sight;  
		flashLight->OFF();
	}
	else if (ch == 'k'&&item[KEY] > 0) { //k �Է½� ���踦 ������ �ְ� 
		if (direction == UP) { // �� ������ �����̸� 
			if (map[y - 1][x] == DOOR) {  //�� ���⿡ ���� ������ 
				item[KEY]--;
				direction = UP;
				prevDirection = UP;
				Walk(x, y - 1);
				y--;
				ignore = BLANK; //move�� ���� ó���Ͽ� �� ���� �ڸ��� �̵��Ѵ�. ���� BLANK�� �ٲ��. 
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
void Player::Reset() { //Reset �Լ��� sight, ignore ��, ������ �����ִ��� ����, ��� �������� �ʱ�ȭ�Ѵ�. 
	sight = normal_sight;
	ignore = BLANK;
	flashLight->OFF();
	for (int i = 0; i < itemMax - 2; i++) {
		item[i] = 0;
	}
}
void Player::PrintItemCount() { //���� ȭ�鿡�� ����ڰ� ������ �ִ� �������� �����ִ� �Լ� 
	gotoxy(43, 3);
	cout << "�� ������ : " << item[FLS] << "��";
	gotoxy(43, 5);
	cout << " ����  : " << item[KEY] << "��";
	gotoxy(43, 12);
	cout << "���� ����� ���� �����ø� 9�� �����ּ���.";
	gotoxy(43, 14);
	cout << "�ɼ��� ���� �����ø� 0�� �����ּ���.";
}
