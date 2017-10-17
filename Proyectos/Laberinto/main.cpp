#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include "Colas_dinamicas.h"
#include "Pilas_dinamicas.h"

#define MAX_ROW 100
#define MAX_COL 100

#define UP 0
#define RIGHT 1
#define LEFT 2
#define DOWN 3

#define meta 3

using namespace std;

void init(int &row, int &col, int &posy_j, int &posx_j, int &posy_m, int &posx_m, int m[MAX_ROW][MAX_COL]);
void print(int row, int col, int posy_j, int posx_j, int posy_m, int posx_m, int m[MAX_ROW][MAX_COL]);
void update(int &posy_j, int &posx_j, int posy_m, int posx_m, int &dir, int m[MAX_ROW][MAX_COL]);
bool yesOrNo(float probabilityOfYes, int &val);

	Colas_dinamicas<int> ordenCola;
	Pilas_dinamicas<int> ordenPila;

int main() {
	
	srand(time(NULL));
	int m[MAX_ROW][MAX_COL];
	int dir = UP;
	
	int row = 0, col = 0;
	int posy_j, posx_j;
	int posy_m, posx_m;
	
	init(row, col, posy_j, posx_j, posy_m, posx_m, m);
	print(row, col, posy_j, posx_j, posy_m, posx_m, m);
	while (posy_j != posy_m || posx_j != posx_m) {
		update(posy_j, posx_j, posy_m, posx_m, dir, m);
		print(row, col, posy_j, posx_j, posy_m, posx_m, m);
	}	
	cout << "Objetos recojidos en orden en cola: " << endl; ordenCola.Imprimir(); cout << endl << endl;
	cout << "Objetos recojidos en orden en pila: " << endl; ordenPila.Imprimir(); cout << endl << endl;
	system("pause");
	return 0;
}

void init(int &row, int &col, int &posy_j, int &posx_j, int &posy_m, int &posx_m, int m[MAX_ROW][MAX_COL]) {
	fstream file;
	string line;
	bool flag = false;
	int val = 0;
	
	file.open("maze.txt", ios::in);
	
	if(file.fail()) {
		cout << "Error al abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	} else {
		while(getline(file, line)) {
			if(!flag) {
				col = line.size(); flag = true;
			}		
			for (int i = 0; i < line.size(); i++) {
				m[row][i] = line[i]-48;
				if(m[row][i] == 2) {
					posy_j = row; posx_j = i;
				}
				if(m[row][i] == 3) {
					posy_m = row; posx_m = i;
				}
				if(m[row][i] == 0)
					if (yesOrNo(0.05, val))
						m[row][i] = val;
			}
			row++;
		}
		file.close();
	}		
}

bool yesOrNo(float probabilityOfYes, int &val) {
	val = (rand()%89) + 10;
	return rand()%100 < (probabilityOfYes * 100);
}

void print(int row, int col, int posy_j, int posx_j, int posy_m, int posx_m, int m[MAX_ROW][MAX_COL]) {
	system("cls");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (m[i][j] == 1) cout << (char)219 << (char)219;
			else if (m[i][j] == 46) cout << (char)46 << " ";
			else if (i == posy_m && j == posx_m) cout << (char)176 << " ";
			else if (i == posy_j && j == posx_j) cout << (char)158 << " ";
			else if (m[i][j] >= 10 && m[i][j] <=99) cout << m[i][j];
			else cout << "  ";
		}
		cout << endl;
	}
//	system("pause");
	Sleep(100);
	cout << endl;
}

void update(int &posy_j, int &posx_j, int posy_m, int posx_m, int &dir, int m[MAX_ROW][MAX_COL]) {
	
	int old_posy_j,old_posx_j;

	old_posy_j = posy_j;
	old_posx_j = posx_j;

	int up, down, left, right;

	up = m[posy_j-1][posx_j];
	down = m[posy_j+1][posx_j];
	right = m[posy_j][posx_j+1];
	left = m[posy_j][posx_j-1];

	if (right == meta) dir = RIGHT;
	else if (left == meta) dir = LEFT;
	else if (up == meta) dir = UP;
	else if (down == meta) dir = DOWN;
	
	else if (dir == DOWN) {
		if (down != 1 && left == 1) {}
		else if (left != 1) dir = LEFT;
		else if (right != 1) dir = RIGHT;
		else dir = UP;
	} else if (dir == LEFT) {
		if (left != 1 && up == 1) {}
		else if (up != 1) dir = UP;
		else if (down != 1) dir = DOWN;
		else dir = RIGHT;
	} else if (dir == UP) {
		if (right == 1 && up != 1) {}
		else if (right != 1) dir = RIGHT;
		else if (left != 1) dir = LEFT;
		else dir = DOWN;
	} else if (dir == RIGHT) {
		if (down == 1 && right != 1) {}
		else if (down != 1) dir = DOWN;
		else if (up != 1) dir = UP;
		else dir = LEFT;
	}

	m[old_posy_j][old_posx_j] = 46;
	
	int y = 0;
	int x = 0;
	
	switch(dir) {
		case 0:
			y = posy_j-1;
			x = posx_j;
			if (m[y][x] != 0 && m[y][x] != 46 && m[y][x] != 3) {
				ordenCola.Anadir(m[y][x]);
				ordenPila.Anadir(m[y][x]);	
			}
			m[y][x] = 2;
			posy_j--;
			break;
		case 1:
			y = posy_j;
			x = posx_j+1;
			if (m[y][x] != 0 && m[y][x] != 46 && m[y][x] != 3) {
				ordenCola.Anadir(m[y][x]);
				ordenPila.Anadir(m[y][x]);	
			}
			m[y][x] = 2;
			posx_j++;
			break;
		case 2:
			y = posy_j;
			x = posx_j-1;
			if (m[y][x] != 0 && m[y][x] != 46 && m[y][x] != 3) {
				ordenCola.Anadir(m[y][x]);
				ordenPila.Anadir(m[y][x]);	
			}
			m[y][x] = 2;
			posx_j--;
			break;
		case 3:
			y = posy_j+1;
			x = posx_j;
			if (m[y][x] != 0 && m[y][x] != 46 && m[y][x] != 3) {
				ordenCola.Anadir(m[y][x]);
				ordenPila.Anadir(m[y][x]);	
			}
			m[y][x] = 2;
			posy_j++;
			break;
	}
}
