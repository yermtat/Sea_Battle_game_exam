#pragma once

#include "Data.h"
#include "Visual.h"
#include "Helper_functions.h"

void ship_placement(int player_field[10][10], void(*placement)(int player_field[10][10], int, int)) {

	int decks{ 4 }, ships{ 1 };

	while (decks > 0 && ships < 5)
	{
		placement(player_field, decks, ships);
		decks--;
		ships++;
	}
}

void ships_and_spaces(int player[10][10], int decks, int number1, int number2, int col_start, int col_end, bool& ship_placed) {

	ship_placed = false;

	if (number1 == number2)
	{
		for (size_t i = 0; i < decks; i++)
		{
			player[number1 - 1][col_start + i] = decks;

			if (number1 != 1)
				player[number1 - 1 - 1][col_start + i] = 5;

			if (number1 != 10)
				player[number1 - 1 + 1][col_start + i] = 5;

		}
		ship_placed = true;

		if (col_start != 0) {
			player[number1 - 1][col_start - 1] = 5;

			if (number1 != 1)
				player[number1 - 1 - 1][col_start - 1] = 5;

			if (number1 != 10)
				player[number1 - 1 + 1][col_start - 1] = 5;
		}

		if (col_end != 9) {
			player[number1 - 1][col_end + 1] = 5;

			if (number1 != 1)
				player[number1 - 1 - 1][col_end + 1] = 5;

			if (number1 != 10)
				player[number1 - 1 + 1][col_end + 1] = 5;
		}


	}
	else if (col_start == col_end) {

		for (size_t i = 0; i < decks; i++)
		{
			player[number1 - 1 + i][col_start] = decks;

			if (col_start != 0)
				player[number1 - 1 + i][col_start - 1] = 5;

			if (col_start != 9)
				player[number1 - 1 + i][col_start + 1] = 5;

		}
		ship_placed = true;

		if (number1 != 1) {

			player[number1 - 1 - 1][col_start] = 5;

			if (col_start != 0)
				player[number1 - 1 - 1][col_start - 1] = 5;

			if (col_start != 9)
				player[number1 - 1 - 1][col_start + 1] = 5;
		}

		if (number2 != 10) {

			player[number2 - 1 + 1][col_start] = 5;

			if (col_start != 0)
				player[number2 - 1 + 1][col_start - 1] = 5;

			if (col_start != 9)
				player[number2 - 1 + 1][col_start + 1] = 5;

		}
	}
}

void place_ships_hand(int player[10][10], int decks, int ships) {


	char letter1{}, letter2{};
	int number1{}, number2{}, col_start{}, col_end{};
	int count{};
	bool ship_placed{};

	while (count != ships)
	{
		cout << "\nPlace " << decks << " deck ships " << ships - count << " times\n" << endl;

		cout << "Enter the first and the last coordinate of the ship (Example: A7A9 (3 decks), H5H5 (1 deck) etc.): " << endl;
		cin >> letter1 >> number1 >> letter2 >> number2;

		col_start = make_numb_letter(letter1);
		col_end = make_numb_letter(letter2);

		if (number1 == number2 && col_end - col_start != decks - 1 || col_end == col_start && number2 - number1 != decks - 1) {
			cout << "The ship is not " << decks << " deck. Try again";
			continue;
		}

		if (free_check(player, number1 - 1, col_start, number2 - 1, col_end) != true) {
			cout << "The cell is not empty, try again" << endl;
			continue;
		}

		ships_and_spaces(player, decks, number1, number2, col_start, col_end, ship_placed);

		if (ship_placed) {
			count++;
			system("cls");
			show_field(player);
		}
		else {
			cout << "Incorrect coordinate. Try again." << endl;
		}
	}
}

void place_ships_random(int	field[10][10], int decks, int ships) {

	int count{};
	int start_numb{}, end_numb{}, start_let{}, end_let{};
	bool ship_placed{};

	while (count != ships)
	{
		do {
			start_numb = rand() % 10 + 1;
			end_numb = rand() % 10 + 1;
			start_let = rand() % 10;
			end_let = rand() % 10;
		} while (start_numb != end_numb && start_let != end_let);


		if (start_numb == end_numb && end_let - start_let != decks - 1) {

			while (end_let - start_let != decks - 1) {
				start_let = rand() % 10;
				end_let = rand() % 10;
			}
		}
		else if (end_let == start_let && end_numb - start_numb != decks - 1) {
			while (end_numb - start_numb != decks - 1) {
				start_numb = rand() % 10 + 1;
				end_numb = rand() % 10 + 1;
			}
		}

		if (free_check(field, start_numb - 1, start_let, end_numb - 1, end_let) != true) {
			continue;
		}

		ships_and_spaces(field, decks, start_numb, end_numb, start_let, end_let, ship_placed);

		if (ship_placed) {
			count++;
		}
	}
}


