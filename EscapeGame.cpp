#include "EscapeGame.h"

extern int** map;
extern void gotoxy(int x, int y);
extern void setcolor(int color, int bgcolor);

// ���� ȭ�� ���� �Լ� 
void EscapeGame::StartScreen() {
	enum{START,INFO,OPTION,EXIT};
	int select = START;

	system("cls");

	while (_kbhit()) {
		_getch();
	}
	
	while (1) {
		gotoxy(0, 0);
		if (_kbhit()) {
			int ch = _getch();
			if (ch == 'w') {
				if (select == START) select = EXIT;
				else select--;
			}
			else if (ch == 's') {
				if (select == EXIT) select = START;
				else select++;
			}
			//����ڰ� ���� �Է½� ������ ��������
			else if (ch == 13) {
				if (select == START) {
					MapScreen();
					system("cls");
					break;
				}
				else if (select == INFO) {
					InfoScreen();
					gotoxy(0, 0);
				}
				else if (select == OPTION) {
					Option();
					gotoxy(0, 0);
				}
				else if (select == EXIT) {
					turn = false;
					break;
				}
			}
		}
		if (select == START) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� �޴��� �����ϼ���      ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��         ��  ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� �ɼ�              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if (select == INFO) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� �޴��� �����ϼ���      ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��         ��  ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� �ɼ�              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if (select == OPTION) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� �޴��� �����ϼ���      ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��         ��  ���� �ɼ�              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if (select == EXIT) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� �޴��� �����ϼ���      ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��             ���� �ɼ�              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��         ��  ���� ����              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		cout << "                                        " << endl;
		cout << endl;
		cout << "             �� �޴��� �̵�             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             �Ʒ� �޴��� �̵�           " << endl;
	}
}

//�� ����ȭ�� ���� �Լ�
void EscapeGame::MapScreen() {
	PlayerName(); //����ڿ��Լ� �̸��� ���� 
	player = new Player(name, playercolor); //�̸��� ����� ���� ������ player ��ü ���� 
	map = new Map(player);  
			
	enum{Map1,Map2,Map3,Map4,Map5};
	int select = Map1;
			
	while (_kbhit()) {
		_getch();
	}
			
	while (1) {
		gotoxy(0, 0);
		if (_kbhit()) {
			int ch = _getch();
			if (ch == 'w') {
				if (select == Map1) select = Map5;
					else select--;
			}
			else if (ch == 's') {
				if (select == Map5) select = Map1;
				else select++;
			}
			//���� �Է½� ������ ��� 
			else if (ch == 13) {
				if (select == Map1) {
					level=1;
					map->Mapping(level);
					gotoxy(0, 0);
					map->MapPrint(level);
					turn = true;
					system("cls");
					break;
				}
				else if (select == Map2) {
					level=2;
					map->Mapping(level);
					gotoxy(0, 0);
					map->MapPrint(level);
					turn = true;
					system("cls");
					break;
				}
				else if (select == Map3) {
					level=3;
					map->Mapping(level);
					gotoxy(0, 0);
					map->MapPrint(level);
					turn = true;
					system("cls");
					break;
				}
				else if (select == Map4) {
					level=4;
					map->Mapping(level);
					gotoxy(0, 0);
					map->MapPrint(level);
					turn = true;
					system("cls");
					break;
				}
				else if (select == Map5) {
					level=5;
					map->Mapping(level);
					gotoxy(0, 0);
					map->MapPrint(level);
					turn = true;
					system("cls");
					break;
				}
			}
		}
		
		if(select == Map1) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� ���� �����ϼ���        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��           ��  Map1                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map2                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map3                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map4                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map5                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if(select == Map2) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� ���� �����ϼ���        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map1                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��           ��  Map2                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map3                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map4                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map5                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if(select == Map3) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� ���� �����ϼ���        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map1                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map2                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��           ��  Map3                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map4                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map5                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if(select == Map4) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� ���� �����ϼ���        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map1                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map2                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map3                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��           ��  Map4                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map5                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		else if(select == Map5) {
			cout << "���������������������" << endl;
			cout << "��                                    ��" << endl;
			cout << "��       Welcome to Escape Game       ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��      ���ϴ� ���� �����ϼ���        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map1                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map2                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map3                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               Map4                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��           ��  Map5                 ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
		}
		cout << "                                        " << endl;
		cout << endl;
		cout << "             �� �޴��� �̵�             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             �Ʒ� �޴��� �̵�           " << endl;
	}
}

//���� ���� ȭ�� ���� �Լ� 
void EscapeGame::InfoScreen() {
	bool turn2 = true;
	int begin = 1, page = 1, last = 3;

	while (_kbhit()) {
		_getch();
	}
	
	while (turn2) {
		if (_kbhit()) {
			int ch = _getch();
			if (ch == 27) turn2 = false;
			else if (ch == 'a') {
				if (page > begin) page--;
			}
			else if (ch == 'd') {
				if (page < last) page++;
			}
		}
		gotoxy(0, 0);
		
		if (page == begin) {
			cout << "���������������������" << endl;
			cout << "��              ���� ���             ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                     �������� ESCŰ ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   C++ ���� �ۼ��� �� Ż�� ����   ��" << endl;
			cout << "��   �þ߰� ���ѵ� ��Ȳ���� ����      ��" << endl;
			cout << "��   ���� �ⱸ�� Ż���ϴ� ����        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   �÷��̾� : ��                    ��" << endl;
			cout << "��   ��乮: ��                       ��" << endl;
			cout << "��   �ⱸ : ��                        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   ������ ��� �����÷���           ��" << endl;
			cout << "��   dŰ�� ��������.                  ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
			cout << "                           ������ d ��  " << endl;
		}
		else if (page == 2) {
			cout << "���������������������" << endl;
			cout << "��              ���� ���             ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   ����Ű             �������� ESCŰ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��               (U P)                ��" << endl;
			cout << "��                 W                  ��" << endl;
			cout << "��       (LEFT) A  S  D (RIGHT)       ��" << endl;
			cout << "��              (DO WN)               ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   Z  : ������/���� �ݱ�            ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   F  : ������  Ű��/����           ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   K  : �� ����  (����  ������)     ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
			cout << "  �� a ����                ������ d ��  " << endl;
		}
		else if (page == last) {
			cout << "���������������������" << endl;
			cout << "��             ���� ���              ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   ����               �������� ESCŰ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   �� ������  : �þ߸� �����ݴϴ�.  ��" << endl;
			cout << "��      �ʸ��� �ִ� ���� ���� 1��     ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   �� ���� : ���� ���µ��� �ʿ��ϴ�.��" << endl;
			cout << "��      3�� ������ ��� �ٴ� �� �ִ�. ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
			cout << "  �� a ����                             " << endl;
		}
		cout << endl;
		cout << "             �� �޴��� �̵�             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             �Ʒ� �޴��� �̵�           " << endl;
	} 
}

//������� �̸���  �Է¹޴� �Լ� 
void EscapeGame::PlayerName() {
	char copyname[20];
	system("cls");
	while (1) {
		gotoxy(0, 0);
		cout << "���������������������" << endl;
		cout << "��                                    ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��  ����Ͻ� �̸��� �Է����ּ���(����)��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��    �� ��:                          ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "���������������������" << endl;
		gotoxy(13, 6);
		cin >> copyname;
		if (strlen(copyname) <= 10) {
			strcpy_s(name, copyname);
				break;
		}
		else {
			gotoxy(0, 12);
			cout << "�̸��� �ʹ� ��ϴ�." << endl;
		}
	}
	system("cls");
}

//���� ���� �Լ� 
void EscapeGame::GameRun() {
	StartScreen();
	while (_kbhit()) {
		_getch();
	}
	while (turn) {
		if (_kbhit()) {
			int ch = _getch();
			if (ch == '9') {
				system("cls");
				InfoScreen();
				system("cls");
			}
			else if (ch == '0') {
				system("cls");
				Option();
				system("cls");
			}
			player->Move(ch); //player ��ü�� Move �Լ��� ������� Ű���� �Է°��� ���� 
		}
		gotoxy(0, 0);
		map->MapPrint(level); //�� ��� 
		GameStatusCheck(); //���� Ŭ���� �ߴ� �� üũ 
	}
}
void EscapeGame::Option() {
	enum{COLOR};
	int select = COLOR;

	while (_kbhit()) {
		_getch();
	}
	while (1) {
		if (_kbhit()) {
			int ch = _getch();
			
			if (ch == 'a'&&select == COLOR) {
				if (playercolor > 1) playercolor--;
				if (player != 0) player->SetColor(playercolor); //Setcolor�� ����� ���� ���� Setter �Լ� 
			}
			else if (ch == 'd'&&select == COLOR) {
				if (playercolor < 15) playercolor++;
				if (player != 0) player->SetColor(playercolor);
			}
			else if (ch == 27) break; //ESC �Է½� Ż�� 
		}
		gotoxy(0, 0);
		if (select == COLOR) {
			setcolor(7, 0);
			cout << "���������������������" << endl;
			cout << "��                        ESC : �������" << endl;
			cout << "��              ���� �ɼ�             ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��   ĳ���� ����    : �� "; setcolor(playercolor, 0); cout << "��"; setcolor(7, 0); cout << " ��        ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "��                                    ��" << endl;
			cout << "���������������������" << endl;
			cout << "  �� a ����                ������ d ��  " << endl;
		}
		cout << endl;
		cout << "             �� �޴��� �̵�             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             �Ʒ� �޴��� �̵�           " << endl;
	}
}

//���� Ŭ���� �ߴ��� �˻��ϴ� �Լ� 
void EscapeGame::GameStatusCheck() {
	enum{NEXTMAP, MAIN, RESTART};
	int select = NEXTMAP;
	
	if (player->GetIgnore() == EXIT) {
		
		while (_kbhit()) {
			_getch();
		}
		
		while (1) {
			gotoxy(0, 0);
			
			if (_kbhit()) {
				int ch = _getch();
				if (ch == 'w') {
					if (select == NEXTMAP) select = RESTART;
					else select--;
				}
				else if (ch == 's') {
					if (select == RESTART) select = NEXTMAP;
					else select++;
				}
				else if (ch == 13) {
					if (select == NEXTMAP) {
						level++;
						if(level ==maxlevel+1 ) { // ������ �� Ŭ����� 
							StartScreen(); //�ʱ� ȭ������ ���ƿ� 
						}
						else { //��ü ���� �� �ٽ� �Ҵ�, �ʱ�ȭ 
							delete map;
							player->Reset();
							map = new Map(player);
							map->Mapping(level);
							gotoxy(0, 0);
							map->MapPrint(level);
							turn = true;
							system("cls");
						}
						break;
					}
					if (select == MAIN) {
						delete player;
						player = 0;
						map = 0;
						StartScreen(); //�ʱ� ȭ������ ���ƿ� 
						system("cls");
						break;
					}
					else if (select == RESTART) { 
						player->Reset();
						player->BackUpDataOutput(); //���� �� �÷��̾��� �ʱ� ������ �ٽ� �� �� 
						map = new Map(player);
						map->Mapping(level);
						gotoxy(0, 0);
						map->MapPrint(level);
						turn = true;
						system("cls"); 
						break;
					}
				}
			}
			
			if (select == NEXTMAP) {
				cout << "���������������������" << endl;
				cout << "��   �����    ����  ���  ���� ��"<< endl;
				cout << "�� ��      ��    ��     ��  �� ��  �� ��" << endl;
				cout << "�� ��      ��    ����������� ��" << endl;
				cout << "�� ��      ��    ��    ��    ����   ��" << endl;
				cout << "��   �����������    ���  �� ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��         ��   NEXTMAP               ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��              MAIN                  ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��              RESTART               ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "���������������������" << endl;
			}
			else if (select == MAIN) {
				cout << "���������������������" << endl;
				cout << "��   �����    ����  ���  ���� ��"<< endl;
				cout << "�� ��      ��    ��     ��  �� ��  �� ��" << endl;
				cout << "�� ��      ��    ����������� ��" << endl;
				cout << "�� ��      ��    ��    ��    ����   ��" << endl;
				cout << "��   �����������    ���  �� ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��              NEXTMAP               ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��         ��   MAIN                  ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��              RESTART               ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "���������������������" << endl;
				
			}
			else if (select == EXIT) {
				cout << "���������������������" << endl;
				cout << "��   �����    ����  ���  ���� ��"<< endl;
				cout << "�� ��      ��    ��     ��  �� ��  �� ��" << endl;
				cout << "�� ��      ��    ����������� ��" << endl;
				cout << "�� ��      ��    ��    ��    ����   ��" << endl;
				cout << "��   �����������    ���  �� ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��              NEXTMAP               ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��              MAIN                  ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��         ��   RESTART               ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "��                                    ��" << endl;
				cout << "���������������������" << endl;
			}
			cout << "                                        " << endl;
			cout << endl;
			cout << "             �� �޴��� �̵�             " << endl;
			cout << "                  W                     " << endl;
			cout << "                  S                     " << endl;
			cout << "             �Ʒ� �޴��� �̵�           " << endl;
		}
	}
};
