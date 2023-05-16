#pragma once

#include "Data.h"

void save(int player_field[10][10], int comp_field[10][10], int* players_ships, int* comp_ships) {
	fopen_s(&file, "sea_battle.dat", "wb");

	fwrite((char*)player_field, sizeof(int), 100, file);
	fwrite((char*)comp_field, sizeof(int), 100, file);
	fwrite((char*)players_ships, sizeof(int), 1, file);
	fwrite((char*)comp_ships, sizeof(int), 1, file);

	fclose(file);
}


void load(int player_field[10][10], int comp_field[10][10], int* players_ships, int* comp_ships) {
	fopen_s(&file, "sea_battle.dat", "rb");

	fread((char*)player_field, sizeof(int), 100, file);
	fread((char*)comp_field, sizeof(int), 100, file);
	fread((char*)players_ships, sizeof(int), 1, file);
	fread((char*)comp_ships, sizeof(int), 1, file);

	fclose(file);
}

