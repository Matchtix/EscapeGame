#include "EscapeGame.h"

extern int** map;
extern void gotoxy(int x, int y);
extern void setcolor(int color, int bgcolor);

// 시작 화면 구성 함수 
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
			//사용자가 엔터 입력시 루프를 빠져나감
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
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 메뉴를 선택하세요      ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■         ▶  게임 시작              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 정보              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 옵션              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 종료              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if (select == INFO) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 메뉴를 선택하세요      ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 시작              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■         ▶  게임 정보              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 옵션              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 종료              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if (select == OPTION) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 메뉴를 선택하세요      ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 시작              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 정보              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■         ▶  게임 옵션              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 종료              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if (select == EXIT) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 메뉴를 선택하세요      ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 시작              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 정보              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■             게임 옵션              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■         ▶  게임 종료              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		cout << "                                        " << endl;
		cout << endl;
		cout << "             위 메뉴로 이동             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             아래 메뉴로 이동           " << endl;
	}
}

//맵 선택화면 구현 함수
void EscapeGame::MapScreen() {
	PlayerName(); //사용자에게서 이름을 받음 
	player = new Player(name, playercolor); //이름과 사용자 설정 색으로 player 객체 생성 
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
			//엔터 입력시 루프를 벗어남 
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
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 맵을 선택하세요        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■           ▶  Map1                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map2                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map3                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map4                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map5                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if(select == Map2) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 맵을 선택하세요        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map1                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■           ▶  Map2                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map3                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map4                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map5                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if(select == Map3) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 맵을 선택하세요        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map1                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map2                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■           ▶  Map3                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map4                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map5                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if(select == Map4) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 맵을 선택하세요        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map1                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map2                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map3                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■           ▶  Map4                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map5                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		else if(select == Map5) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■       Welcome to Escape Game       ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■      원하는 맵을 선택하세요        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map1                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map2                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map3                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               Map4                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■           ▶  Map5                 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		}
		cout << "                                        " << endl;
		cout << endl;
		cout << "             위 메뉴로 이동             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             아래 메뉴로 이동           " << endl;
	}
}

//게임 정보 화면 구성 함수 
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
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■              게임 방법             ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                     나가려면 ESC키 ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   C++ 언어로 작성된 맵 탈출 게임   ■" << endl;
			cout << "■   시야가 제한된 상황에서 문을      ■" << endl;
			cout << "■   열어 출구로 탈출하는 게임        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   플레이어 : ▲                    ■" << endl;
			cout << "■   잠긴문: ⓓ                       ■" << endl;
			cout << "■   출구 : ⓔ                        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   설명을 계속 들으시려면           ■" << endl;
			cout << "■   d키를 누르세요.                  ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "                           오른쪽 d →  " << endl;
		}
		else if (page == 2) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■              게임 방법             ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   조작키             나가려면 ESC키■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■               (U P)                ■" << endl;
			cout << "■                 W                  ■" << endl;
			cout << "■       (LEFT) A  S  D (RIGHT)       ■" << endl;
			cout << "■              (DO WN)               ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   Z  : 손전등/열쇠 줍기            ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   F  : 손전등  키기/끄기           ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   K  : 문 열기  (열쇠  소유시)     ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "  ← a 왼쪽                오른쪽 d →  " << endl;
		}
		else if (page == last) {
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■             게임 방법              ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   도구               나가려면 ESC키■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   ⓕ 손전등  : 시야를 넓혀줍니다.  ■" << endl;
			cout << "■      맵마다 최대 개수 제한 1개     ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   ⓚ 열쇠 : 문을 여는데에 필요하다.■" << endl;
			cout << "■      3개 까지만 들고 다닐 수 있다. ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "  ← a 왼쪽                             " << endl;
		}
		cout << endl;
		cout << "             위 메뉴로 이동             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             아래 메뉴로 이동           " << endl;
	} 
}

//사용자의 이름을  입력받는 함수 
void EscapeGame::PlayerName() {
	char copyname[20];
	system("cls");
	while (1) {
		gotoxy(0, 0);
		cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■  사용하실 이름을 입력해주세요(영어)■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■    이 름:                          ■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■                                    ■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
		gotoxy(13, 6);
		cin >> copyname;
		if (strlen(copyname) <= 10) {
			strcpy_s(name, copyname);
				break;
		}
		else {
			gotoxy(0, 12);
			cout << "이름이 너무 깁니다." << endl;
		}
	}
	system("cls");
}

//게임 실행 함수 
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
			player->Move(ch); //player 객체의 Move 함수에 사용자의 키보드 입력값을 전달 
		}
		gotoxy(0, 0);
		map->MapPrint(level); //맵 출력 
		GameStatusCheck(); //맵을 클리어 했는 지 체크 
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
				if (player != 0) player->SetColor(playercolor); //Setcolor는 사용자 색에 대한 Setter 함수 
			}
			else if (ch == 'd'&&select == COLOR) {
				if (playercolor < 15) playercolor++;
				if (player != 0) player->SetColor(playercolor);
			}
			else if (ch == 27) break; //ESC 입력시 탈출 
		}
		gotoxy(0, 0);
		if (select == COLOR) {
			setcolor(7, 0);
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■                        ESC : 나가기■" << endl;
			cout << "■              게임 옵션             ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■   캐릭터 색깔    : ◀ "; setcolor(playercolor, 0); cout << "▲"; setcolor(7, 0); cout << " ▶        ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■                                    ■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "  ← a 왼쪽                오른쪽 d →  " << endl;
		}
		cout << endl;
		cout << "             위 메뉴로 이동             " << endl;
		cout << "                  W                     " << endl;
		cout << "                  S                     " << endl;
		cout << "             아래 메뉴로 이동           " << endl;
	}
}

//맵을 클리어 했는지 검사하는 함수 
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
						if(level ==maxlevel+1 ) { // 마지막 맵 클리어시 
							StartScreen(); //초기 화면으로 돌아옴 
						}
						else { //객체 해제 및 다시 할당, 초기화 
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
						StartScreen(); //초기 화면으로 돌아옴 
						system("cls");
						break;
					}
					else if (select == RESTART) { 
						player->Reset();
						player->BackUpDataOutput(); //리셋 후 플레이어의 초기 방향을 다시 잡 음 
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
				cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
				cout << "■   ■■■■    ■■■  ■■  ■■■ ■"<< endl;
				cout << "■ ■      ■    ■     ■  ■ ■  ■ ■" << endl;
				cout << "■ ■      ■    ■■■■■■■■■■ ■" << endl;
				cout << "■ ■      ■    ■    ■    ■■■   ■" << endl;
				cout << "■   ■■■■■■■■■■    ■■  ■ ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■         ▶   NEXTMAP               ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■              MAIN                  ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■              RESTART               ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			}
			else if (select == MAIN) {
				cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
				cout << "■   ■■■■    ■■■  ■■  ■■■ ■"<< endl;
				cout << "■ ■      ■    ■     ■  ■ ■  ■ ■" << endl;
				cout << "■ ■      ■    ■■■■■■■■■■ ■" << endl;
				cout << "■ ■      ■    ■    ■    ■■■   ■" << endl;
				cout << "■   ■■■■■■■■■■    ■■  ■ ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■              NEXTMAP               ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■         ▶   MAIN                  ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■              RESTART               ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
				
			}
			else if (select == EXIT) {
				cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
				cout << "■   ■■■■    ■■■  ■■  ■■■ ■"<< endl;
				cout << "■ ■      ■    ■     ■  ■ ■  ■ ■" << endl;
				cout << "■ ■      ■    ■■■■■■■■■■ ■" << endl;
				cout << "■ ■      ■    ■    ■    ■■■   ■" << endl;
				cout << "■   ■■■■■■■■■■    ■■  ■ ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■              NEXTMAP               ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■              MAIN                  ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■         ▶   RESTART               ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■                                    ■" << endl;
				cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
			}
			cout << "                                        " << endl;
			cout << endl;
			cout << "             위 메뉴로 이동             " << endl;
			cout << "                  W                     " << endl;
			cout << "                  S                     " << endl;
			cout << "             아래 메뉴로 이동           " << endl;
		}
	}
};
