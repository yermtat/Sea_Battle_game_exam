#pragma once

#include "Data.h"
#include<conio.h>

enum controllers { UP = 72, DOWN = 80 };

short menu(const char* Menu[], short length) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;

	while (true)
	{

		menuPos %= length;
		if (menuPos < 0) menuPos = length - 1;

		for (size_t i = 0; i < length; i++)
		{
			if (i == menuPos) {
				SetConsoleTextAttribute(h, 79);
				cout << "> " << Menu[i] << setw(10) << right << ' ' << endl;
			}
			else {
				SetConsoleTextAttribute(h, 15);
				cout << " " << Menu[i] << setw(10) << right << ' ' << endl;
			}
		}



		key = _getch();
		if (key == 224) {

			key = _getch();
			switch (key)
			{
			case UP:
				menuPos--;
				break;
			case DOWN:
				menuPos++;
				break;
			}
		}
		else {
			if (key == 13) {

				SetConsoleTextAttribute(h, 15);
				return menuPos + 1;
			}
		}
		SetConsoleTextAttribute(h, 15);
		system("cls");
	}
}

void show_field(int player[10][10]) {  // одиночное поле

	h = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << setw(4) << 'A';
	for (size_t i = 0; i < 9; i++)
	{
		cout << ' ' << char('B' + i);
	}
	cout << endl;

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (j == 0) {
				cout << setw(2) << i + 1 << ' ';
			}

			if (player[i][j] == 0) {
				cout << char(176) << char(176);
			}
			else if (player[i][j] >= 1 && player[i][j] <= 4) {
				cout << char(219) << char(219);
			}
			else if (player[i][j] == 5) {
				cout << char(177) << char(177);
			}
		}
		cout << '\n';
	}
}

void show_field(int player[10][10], int comp[10][10], int players_ships, int comp_ships) {

	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);

	for (size_t i = 0; i < 2; i++)
	{
		cout << setw(4) << 'A';
		for (size_t i = 0; i < 9; i++)
		{
			cout << ' ' << char('B' + i);
		}
		cout << "\t\t\t\t";
	}
	cout << '\n';

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			SetConsoleTextAttribute(h, 7);
			if (j == 0) {
				cout << setw(2) << i + 1 << ' ';
			}

			if (player[i][j] == 0) {
				cout << char(176) << char(176);
			}
			else if (player[i][j] >= 1 && player[i][j] <= 4) { // корабли
				cout << char(219) << char(219);
			}
			else if (player[i][j] == 5) { // пустое место вокруг корабля
				cout << char(177) << char(177);
			}
			else if (player[i][j] == 6) { // подбитая палуба или корабль
				SetConsoleTextAttribute(h, 4);
				cout << char(219) << char(219);
			}
			else if (player[i][j] == 7) { // подбитое пустое место 
				SetConsoleTextAttribute(h, 4);
				cout << char(176) << char(176);
			}
			else if (player[i][j] == 8) { // область вокруг подбитого корабля
				SetConsoleTextAttribute(h, 74);
				cout << char(176) << char(176);
			}
		}

		cout << "\t\t\t\t";

		for (size_t j = 0; j < 10; j++)
		{
			SetConsoleTextAttribute(h, 7 | 0);
			if (j == 0) {
				cout << setw(2) << i + 1 << ' ';
			}

			if (comp[i][j] == 6) {
				SetConsoleTextAttribute(h, 4 | 0);
				cout << char(219) << char(219);
			}
			else if (comp[i][j] == 7) {
				SetConsoleTextAttribute(h, 4 | 0);
				cout << char(176) << char(176);
			}
			else if (comp[i][j] == 8) {
				SetConsoleTextAttribute(h, 74);
				cout << char(176) << char(176);
			}
			else {
				cout << char(176) << char(176);
			}

		}
		cout << '\n';
	}

	SetConsoleTextAttribute(h, 7 | 0);
	cout << "\nPlayer's ships left: " << players_ships << "\t\t\t\t" << "Computer's ships left: " << comp_ships << endl;
}

void show_the_rules() {
	system("cls");
	SetConsoleTextAttribute(h, 7);

	cout << char(176) << char(176) << " - empty cell\n" << endl;
	 // корабли
	cout << char(219) << char(219) << " - your ships\n" << endl;
	
	// пустое место вокруг корабля
	cout << char(177) << char(177) << " - space around your ship\n" << endl;
		
	// подбитая палуба или корабль
	SetConsoleTextAttribute(h, 4);
	cout << char(219) << char(219);
	SetConsoleTextAttribute(h, 7);
	cout << " - hitted deck\n" << endl;

	// подбитое пустое место 
	SetConsoleTextAttribute(h, 4);
	cout << char(176) << char(176);
	SetConsoleTextAttribute(h, 7);
	cout << " - you or the computer missed\n" << endl;
	
	// область вокруг подбитого корабля
	SetConsoleTextAttribute(h, 74);
	cout << char(176) << char(176);
	SetConsoleTextAttribute(h, 7);
	cout << " - space around drowned ship\n" << endl;

	system("pause");

}

