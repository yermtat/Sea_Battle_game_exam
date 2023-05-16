#pragma once

#include "Data.h"
#include "Helper_functions.h"
#include "Visual.h"
#include "File_operations.h"

bool hit_the_ship(int field[10][10], int hit_numb, int hit_letter, int change_field[10][10], int& hit_decks) {

	if (field[hit_numb][hit_letter] >= 1 && field[hit_numb][hit_letter] <= 4) {
		hit_decks = change_field[hit_numb][hit_letter];
		change_field[hit_numb][hit_letter] = 6;
		return true;
	}

	change_field[hit_numb][hit_letter] = 7;
	return false;

}

bool is_ship_drowned(int player_field[10][10], int hit_numb, int hit_letter, int hit_decks) {

	int hit_decks_count = 1;

	if (hit_decks_count == hit_decks) return true;

	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb + i][hit_letter] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb + i][hit_letter] == 5 || player_field[hit_numb + i][hit_letter] == 7 || player_field[hit_numb + i][hit_letter] == 8 || hit_numb + i > 9)
		{
			break;
		}
	}
	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb - i][hit_letter] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb - i][hit_letter] == 5 || player_field[hit_numb - i][hit_letter] == 7 || player_field[hit_numb - i][hit_letter] == 8 || hit_numb - i < 0)
		{
			break;
		}
	}
	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb][hit_letter + i] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb][hit_letter + i] == 5 || player_field[hit_numb][hit_letter + i] == 7 || player_field[hit_numb][hit_letter + i] == 8 || hit_letter + i > 9)
		{
			break;
		}
	}
	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb][hit_letter - i] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb][hit_letter - i] == 5 || player_field[hit_numb][hit_letter - i] == 7 || player_field[hit_numb][hit_letter - i] == 8 || hit_letter - i < 0)
		{
			break;
		}
	}

	if (hit_decks_count == hit_decks) return true;

	return false;

}

void ship_fence(int player[10][10], int hit_numb, int hit_letter, int hit_decks) {

	int number1{}, number2{}, col_start{}, col_end{};

	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb + i][hit_letter] != 6) {
			number2 = hit_numb + i - 1;
			break;
		}
	}
	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb - i][hit_letter] != 6) {
			number1 = hit_numb - i + 1;
			break;
		}
	}
	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb][hit_letter + i] != 6) {
			col_end = hit_letter + i - 1;
			break;
		}
	}
	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb][hit_letter - i] != 6) {
			col_start = hit_letter - i + 1;
			break;
		}
	}

	if (number1 == number2)
	{
		for (size_t i = 0; i < hit_decks; i++)
		{
			if (number1 != 0)
				player[number1 - 1][col_start + i] = 8;

			if (number1 != 9)
				player[number1 + 1][col_start + i] = 8;

		}

		if (col_start != 0) {
			player[number1][col_start - 1] = 8;

			if (number1 != 0)
				player[number1 - 1][col_start - 1] = 8;

			if (number1 != 9)
				player[number1 + 1][col_start - 1] = 8;
		}

		if (col_end != 9) {
			player[number1][col_end + 1] = 8;

			if (number1 != 0)
				player[number1 - 1][col_end + 1] = 8;

			if (number1 != 9)
				player[number1 + 1][col_end + 1] = 8;
		}

	}
	else if (col_start == col_end) {

		for (size_t i = 0; i < hit_decks; i++)
		{

			if (col_start != 0)
				player[number1 + i][col_start - 1] = 8;

			if (col_start != 9)
				player[number1 + i][col_start + 1] = 8;

		}

		if (number1 != 0) {

			player[number1 - 1][col_start] = 8;

			if (col_start != 0)
				player[number1 - 1][col_start - 1] = 8;

			if (col_start != 9)
				player[number1 - 1][col_start + 1] = 8;
		}

		if (number2 != 9) {

			player[number2 + 1][col_start] = 8;

			if (col_start != 0)
				player[number2 + 1][col_start - 1] = 8;

			if (col_start != 9)
				player[number2 + 1][col_start + 1] = 8;

		}
	}

}

bool is_win(int player_ships, int comp_ships) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (comp_ships == 0) {

		for (size_t i = 0; i < 10; i++)
		{
			SetConsoleTextAttribute(h, 79);
			cout << "";
			Sleep(200);
			cout << "\nCONGRATULATIONS!! YOU'VE WON!!" << endl;
			Sleep(500);
			SetConsoleTextAttribute(h, 7);
			system("cls");
		}

		return true;
	}
	else if (player_ships == 0) {

		SetConsoleTextAttribute(h, 79);
		cout << "\nYOU'VE LOST. GAME OVER." << endl;
		SetConsoleTextAttribute(h, 7);
		return true;
	}
}

void the_game_is_on(int player_field[10][10], int comp_field[10][10], int& players_ships, int& comp_ships) {

	bool win{}, player_move{ true }, comp_move{ false }; 
	int hit_numb{}, hit_letter{};
	char letter{};
	bool ship_hitted{};
	int prev_numb{}, prev_let{};
	int hit_decks{};

	while (players_ships > 0 && comp_ships > 0) {

		while (player_move) {

			cout << "\nYour turn.";
			do {
				cout << "\nEnter the coordinate to hit: ";
				cin >> letter >> hit_numb;

				hit_numb--;

				hit_letter = make_numb_letter(letter);
			} while (hit_numb > 9 || hit_numb < 0 || hit_letter > 9 || hit_letter < 0 ||
				comp_field[hit_numb][hit_letter] == 6 || comp_field[hit_numb][hit_letter] == 7 || comp_field[hit_numb][hit_letter] == 8);

			player_move = hit_the_ship(comp_field, hit_numb, hit_letter, comp_field, hit_decks);

			if (player_move != true) {
				comp_move = true;
			}
			else {
				if (is_ship_drowned(comp_field, hit_numb, hit_letter, hit_decks)) {
					ship_fence(comp_field, hit_numb, hit_letter, hit_decks);
					comp_ships--;
				}
			}


			system("cls");
			show_field(player_field, comp_field, players_ships, comp_ships);
			save(player_field, comp_field, &players_ships, &comp_ships);

			if (is_win(players_ships, comp_ships)) break;
		}
		while (comp_move) {

			hit_numb = 0;
			hit_letter = 0;
			cout << "\nComputers turn." << endl;

			do {
				if (ship_hitted) {
					do {
						hit_numb = prev_numb + rand() % 7 - 3;
						hit_letter = prev_let + rand() % 7 - 3;
					} while (hit_numb != prev_numb && hit_letter != prev_let ||
						hit_numb > 9 || hit_numb < 0 || hit_letter > 9 || hit_letter < 0);
				}
				else {
					hit_numb = rand() % 10;
					hit_letter = rand() % 10;
				}
			} while (player_field[hit_numb][hit_letter] == 6 || player_field[hit_numb][hit_letter] == 7 || player_field[hit_numb][hit_letter] == 8);

			comp_move = hit_the_ship(player_field, hit_numb, hit_letter, player_field, hit_decks);

			if (comp_move) {
				ship_hitted = true;
				prev_numb = hit_numb;
				prev_let = hit_letter;

				if (is_ship_drowned(player_field, hit_numb, hit_letter, hit_decks)) {
					ship_hitted = false;
					ship_fence(player_field, hit_numb, hit_letter, hit_decks);
					players_ships--;

				}

			}
			else {
				player_move = true;
			}

			save(player_field, comp_field, &players_ships, &comp_ships);
			Sleep(1000);
			system("cls");
			show_field(player_field, comp_field, players_ships, comp_ships);
			

			if (is_win(players_ships, comp_ships)) break;
		}
	}
}
