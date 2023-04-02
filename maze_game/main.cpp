// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Maze game
// P.S: Maze generator dont main! Source: https://habr.com/ru/post/319532/
// V1.0
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#include "keyboard.h"
#include <iostream>
using namespace std;

bool deadend(int, int, int**, int, int); // Функция проверки тупиков
void visual(int **, int, int);  // Отображение лабиринта в терминале
void mazegen(int **, int, int); // Сам генератор лабиринта
const bool wall = false, pass = true;

int main() {
	srand(time(0));
	system("clear");

	int height = 0;
	int width  = 0;
	cout << "Правила размеры лабиринта могут быть только нечетными!\n";
	cout << "Используй клавишы 'a', 'd', 'w', 's' для перемещения и 'r' для перезапуска игры,\n а 'q' для выхода.\n";
	cout << "Если что здесь нет определенного финиша! Удачи =)\n";
	cout << "Set height: "; cin >> height; // get height of maze
	cout << "Set width:  "; cin >> width;  // get width of maze

	// create and init maze array
	int** maze = new int*[height]; 
	for(int i = 0; i < height; ++i) {
		maze[i] = new int[width];
	}
	mazegen(maze, height, width);
	// move
	short x = 1;
	short y = 1;
	while (true) {
		system("clear");	
		//printf("\033[%d;%dH", 28, 0);
		//cout << "PosX: " << x << '\n';
		//cout << "PosY: " << y << '\n';
		
		printf("\033[%d;%dH", 0, 0);
		visual(maze, height, width);

		printf("\033[%d;%dH", y+1, x+1);
		cout << "\e\[31m■\e[0m";		
		// get type switches
		switch (getch()) {
			case 'w': // Up
				--y;
				if (maze[y][x] == wall) ++y; // collision
		 		break;
			case 's': // Down
				++y;
				if (maze[y][x] == wall) --y; // collision
				break;
			case 'a': // Left
				--x;
				if (maze[y][x] == wall) ++x; // collision
				break;
			case 'd': // Right
				++x;
				if (maze[y][x] == wall) --x; // collision
				break;
			case 'q': // Exit
				printf("\033[%d;%dH", height+1, 0);
				exit(0);
				break;
			case 'r': // Restart game
				main();
				break;
			default:
				break;
		}
	}
	
	for(int i = 0; i < height; ++i) {
		delete[] maze[i];
		delete[] maze;
	}
	return 0;
}

void visual(int **maze, int height, int width) {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (maze[i][j] == wall) { cout << "█"; } else { cout << " "; }
		}
		cout << endl;
	}
}

void mazegen(int **maze, int height, int width) {
	int x, y, c, a;
	
	for(int i = 0; i < height; i++) { // Массив заполняется землей-ноликами
		for(int j = 0; j < width; j++) {
			maze[i][j] = wall;
		}
	}

	x = 3; y = 5; a = 0; // Начальные координаты и счетчик
	while(a < height*width) {
		maze[y][x] = pass; ++a;
		while(true){ // Бесконечный цикл, который прерывается только тупиком
			c = rand()%4; // Напоминаю, что крот прорывает
			switch(c) {	  // по две клетки в одном направлении за прыжок
				case 0: if(y != 1) { // Вверх
					if (maze[y-2][x] == wall) { // По две клетки за прижок 
						maze[y-1][x] = pass; // Делаем проход (ставим 1)
						maze[y-2][x] = pass; // Делаем проход (ставим 1)
						y -= 2;
					}
				} break;
				case 1: if(y != height-2) {      
					if(maze[y+2][x] == wall) { // Вниз
						maze[y+1][x] = pass;
						maze[y+2][x] = pass;
						y+=2;
					}
				} break;
				case 2: if(x != 1) {
					if(maze[y][x-2] == wall) { // Налево
						maze[y][x-1] = pass;
						maze[y][x-2] = pass;
						x-=2;
					}
				} break;
				case 3: if(x != width-2) {
					if(maze[y][x+2] == wall){ // Направо
						maze[y][x+1] = pass;
						maze[y][x+2] = pass;
						x+=2;
					}
				} break;
				default:
					cout << "Error! Generation!\n";
					break;
			}
			if(deadend(x,y,maze,height,width)) break;
		}
		
		if (deadend(x, y, maze, height, width)) {
			do {
				x = 2*(rand()%((width-1)/2))+1;
				y = 2*(rand()%((height-1)/2))+1;
			} while (maze[y][x] != pass);
		}
	}
}

bool deadend(int x, int y, int** maze, int height, int width){
	int a = 0;
	
	if(x != 1){
		if(maze[y][x-2] == pass)
			a+=1;
		}
	else a+=1;
	
	if(y != 1){
		if(maze[y-2][x] == pass)
			a+=1;
		}
	else a+=1;
	
	if(x != width-2){
		if(maze[y][x+2] == pass)
			a+=1;
		}
	else a+=1;
	
	if(y != height-2){
		if(maze[y+2][x] == pass)
			a+=1;
		}
	else a+=1;
	
	if(a == 4)
		return 1; // Мы в тупике
	else
		return 0; // all ok
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// The end program
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
