#include <iostream>
using namespace std;

void drawMap(int map[]) {
	system("clear");
	string usrMap[] { "0", "1", "2", "3", "4", "5", "6", "7", "8" };
	for (int i = 0; i < 9; ++i) {
		if (i % 3 == 0) cout << endl; 
		if (map[i] == 3) {
			usrMap[i] = "\e[32mx\e[0m";
		}
		if (map[i] == 2) {
			usrMap[i] = "\e[31mo\e[0m";
		}
		cout << usrMap[i] << ' ';
	}
}

bool winCheck(int c, int map[]) {
	bool win = false;
	if (map[0] == c && map[1] == c && map[2] == c) win = true;
	if (map[3] == c && map[4] == c && map[5] == c) win = true;
	if (map[6] == c && map[7] == c && map[8] == c) win = true;

	if (map[0] == c && map[3] == c && map[6] == c) win = true;
	if (map[1] == c && map[4] == c && map[7] == c) win = true;
	if (map[2] == c && map[5] == c && map[8] == c) win = true;

	if (map[0] == c && map[4] == c && map[8] == c) win = true;
	if (map[6] == c && map[4] == c && map[2] == c) win = true;
	return win;
}
int main() {
	srand(time(0));
	int map[10] { 0 };
	while (true) {
		drawMap(map);
		// Player
		short player = 0;
		cout << "\nYou: ";
		cin >> ws >> player;
		if (map[player] == 0) {
			map[player] = 3;			
		}

		// AI
		short ai = 0;
		switch (player) {
			case 0:
				if (!(map[1] || map[3] || map[4] || map[2])) {
					ai = 1 + (rand() % 4);
					break;
				}
				if (!(map[4] || map[3])) { ai = 3 + (rand() % 4); break; }
				if (!(map[1] || map[4])) { ai = 4; break; }
				break;
			case 1:
				if (map[0] == 3 && map[2] == 0) { ai = 2; break; }
				if (map[2] == 3 && map[0] == 0) { ai = 0; break; }
				if (map[7] == 3 && map[4] == 0) { ai = 4; break; }
				if (map[4] == 3 && map[7] == 0) { ai = 7; break; }
				break;
			case 3:
				if (map[0] == 3 && map[6] == 0) { ai = 6; break; }
				if (map[6] == 3 && map[0] == 0) { ai = 0; break; }
				if (map[4] == 3 && map[5] == 0) { ai = 5; break; }
				break;
			case 4:
				if (map[5] == 3 && map[3] == 0) { ai = 3; break; }
				if (map[0] == 3 && map[8] == 0) { ai = 8; break; }
				if (map[2] == 3 && map[6] == 0) { ai = 6; break; }
				if (map[6] == 3 && map[2] == 0) { ai = 2; break; }
				if (map[8] == 3 && map[0] == 0) { ai = 0; break; }

				if (map[1] == 3 && map[7] == 0) { ai = 7; break; }
				if (map[3] == 3 && map[5] == 0) { ai = 5; break; }
				if (map[7] == 3 && map[1] == 0) { ai = 1; break; }
				
				break;
			case 5:
				if (map[2] == 0) ai = 2;
				if (map[4] == 3 && map[3] == 0) { ai = 3; break; }
				if (map[8] == 3 && map[2] == 0) { ai = 2; break; }

				break;
			case 6:
				if (map[2] == 0) { ai = 2; break; }
				if (map[7] == 0) { ai = 7; break; }
				break; 
			case 7:
				if (map[1] == 0) { ai = 1; break; }
				if (map[4] == 0) { ai = 4; break; }
				if (map[6] == 0) { ai = 6; break; }
				if (map[8] == 0) { ai = 8; break; }
				break;
			case 8:
				if (map[7] == 3 && map[6] == 0) { ai = 6; break; }
				if (map[2] == 3 && map[5] == 0) { ai = 5; break; }
				break;
			default:
				cout << "No, no!\n";
				break;
		}
		// Win check
		if (winCheck(3, map)) {
			drawMap(map);
			cout << "\nYou win!\n";
			break;
		} else {
			cout << "\nOK\n";
			break;
		}
		
		map[ai] = 2;
		// Win check
		if (winCheck(2, map)) {
			drawMap(map);
			cout << "\nYou lose!\n";
			break;
		} else {
			cout << "\nOK\n";
			break;
		}
	}
	
    return 0;
}
