#include "Data.h"
#include "Visual.h"
#include "Ship_placement.h"
#include "game_logic.h"
#include "File_operations.h"


int main() {
	srand(time(NULL));

	int player_field[10][10]{};
	int comp_field[10][10]{};
	int players_ships{ 10 }, comp_ships{ 10 };

	short menuItem = 0;

	const char* startMenu[] = {
		"	New game",
		"	Load game",
		"	Exit"
	};

	const char* placementMenu[] = {
		"	Randomly",
		"	By hand"
	};

	menuItem = menu(startMenu, 3);
	system("cls");

	switch (menuItem)
	{
	case 1:

		cout << "\tChoose ship's placement:\n\n";
		menuItem = menu(placementMenu, 2);

		switch (menuItem)
		{
		case 1: 
			ship_placement(player_field, place_ships_random);
			break;
		case 2: 
			system("cls");
			show_field(player_field);
			ship_placement(player_field, place_ships_hand);
			break;
		}

		ship_placement(comp_field, place_ships_random);

		save(player_field, comp_field, &players_ships, &comp_ships);
		break;

	case 2:
		load(player_field, comp_field, &players_ships, &comp_ships);
		break;
	case 3:
		return 0;
	}


	show_the_rules();

	system("cls");
	show_field(player_field, comp_field, players_ships, comp_ships);

	the_game_is_on(player_field, comp_field, players_ships, comp_ships);


}