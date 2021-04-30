#include<iostream>
#include<conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	tailX[100] = NULL;
	tailY[100] = NULL;
}

void Draw() {
	system("cls");

	for (int i = 0; i < width + 1; i++) 
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) 
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						print = true;
					}
				}
				if(!print)
					cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch ())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;

	/*if (x >= width - 1)    // you can go beyond the boundaries
		x = 0;
	else if (x < 0)
		x = width - 2;
	
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 2;*/

	for (int i = 0; i < nTail; i++) {
		if (x == tailX[i] && y == tailY[i])
			gameOver = true;
	}

	if (x == fruitX && y == fruitY) {
	 score += 10;
	 fruitX = rand() % width;
	 fruitY = rand() % height;
	 nTail++;
	}
}

void GameOver() {
	system("cls");
	cout << "   GGGGGGG" << "          " << "       AAAAAA" << "             " << "MMMM            MMMM" << "        " << "EEEEEEEEEEEEEEEEE" << endl;
	cout << " GGGGGGGGGGG" << "          " << "   AAAAAAAAAA" << "           " << "MMMMMM        MMMMMM" << "        " << "EEEEEEEEEEEEEEEEE" << endl;
	cout << " GGG     GGG" << "          " << "AAAAA      AAAAA" << "        " << "MMMM MMM    MMM MMMM" << "        " << "EEEEE" << endl;
	cout << "GGG" << "          " << "         AAAAA      AAAAA" << "        " << "MMMM  MMMMMMMM  MMMM" << "        " << "EEEEE" << endl;
	cout << "GGG" << "        " << "           AAAAA      AAAAA" << "        " << "MMMM    MMMM    MMMM" << "        " << "EEEEEEEEEEEEEEEEE" << endl;
	cout << "GGG    GGGGGGG" << "        " << "AAAAAAAAAAAAAAAA" << "        " << "MMMM     MM     MMMM" << "        " << "EEEEEEEEEEEEEEEEE" << endl;
	cout << "GGG       GGGG" << "        " << "AAAAAAAAAAAAAAAA" << "        " << "MMMM	      MMMM" << "        " << "EEEEE" << endl;
	cout << "  GGG	   GGG" << "        " << "AAAAA      AAAAA" << "        " << "MMMM	      MMMM" << "        " << "EEEEE" << endl;
	cout << "   GGGGGGGGGGG" << "        " << "AAAAA      AAAAA" << "        " << "MMMM	      MMMM" << "        " << "EEEEEEEEEEEEEEEEE" << endl;
	cout << "     GGGGGG" << "          " << " AAAAA      AAAAA" << "        " << "MMMM	      MMMM" << "        " << "EEEEEEEEEEEEEEEEE" << endl;

	cout << endl << endl << endl;

	cout << "     OOOOOOO" << "          " << "VVVV           VVVV" << "     " << "EEEEEEEEEEEEEEEEE" << "        " << "RRRRRRRRRRRRRRRR" << endl;
	cout << "   OOOOOOOOOOO" << "        " << "VVVV	     VVVV" << "     " << "EEEEEEEEEEEEEEEEE" << "        " << "RRRRRRRRRRRRRRRR" << endl;
	cout << " OOO         OOO" << "      " << "VVVV	     VVVV" << "     " << "EEEEE" << "                    " << "RRRR	     RRRRR" << endl;
	cout << "OOOO         OOOO" << "     " << "VVVV	     VVVV" << "     " << "EEEEE" << "                    " << "RRRR	     RRRRR" << endl;
	cout << "OOOO         OOOO" << "     " << " VVVV         VVVV" << " " << "     EEEEEEEEEEEEEEEEE" << "        " << "RRRR	   RRRRRRR" << endl;
	cout << "OOOO         OOOO" << "     " << "  VVVV       VVVV" << "  " << "     EEEEEEEEEEEEEEEEE" << "        " << "RRRR	RRR" << endl;
	cout << "OOOO         OOOO" << "     " << "   VVVV     VVVV" << "   " << "     EEEEE" << "                    " << "RRRRRRRRRRR" << endl;
	cout << " OOO         OOO" << "      " << "    VVVV   VVVV" << "   " << "      EEEEE" << "                    " << "RRRRRRRRRRRRRR" << endl;
	cout << "   OOOOOOOOOOO" << "        " << "     VVVV VVVV" << "  " << "        EEEEEEEEEEEEEEEEE" << "        " << "RRRR      RRRRRRR" << endl;
	cout << "     OOOOOOO" << "          " << "      VVVVVVV	" << "  " << "    EEEEEEEEEEEEEEEEE" << "        " << "RRRR	  RRRRRRR" << endl;
}
void gameManager() {
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}

	bool chek = true;
	while (chek) {
		if (_kbhit())
			if (_getch() == 'e')
				chek = false;
		GameOver();
	}
}

int main() {

	while (true) {
		Setup();
		gameManager();
	}
	return 0;
}