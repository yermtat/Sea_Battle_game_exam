#pragma once

#include "Data.h"

int make_numb_letter(char letter) {

	char columns[10]{ 'a', 'b', 'c', 'd', 'e', 'f','g','h', 'i', 'j' };

	for (size_t i = 0; i < 10; i++)
	{
		if (letter == columns[i] || letter == columns[i] - 32)
		{
			return i;
		}
	}

}


bool free_check(int player[10][10], int num_start, int let_start, int num_end, int let_end) {

	for (size_t i = num_start; i <= num_end; i++)
	{
		for (size_t j = let_start; j <= let_end; j++)
		{
			if (player[i][j] != 0) {
				return false;
			}
		}
	}

	return true;
}
