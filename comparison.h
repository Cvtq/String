#pragma once
#include "string.h"

int find(String string, String sub, size_t startIndex) {

	// Некорректный стартовый индекс
	if (startIndex > string.len() - 1) {
		return -1;
	}

	{
		int start = -1, end = -1;
		bool found = false;
		for (size_t i = startIndex; i < string.len() - sub.len() - 1; i++) {						

			if (string(i) == sub(0)) {

				found = true;

				for (size_t j = 1; j < sub.len() - 1; j++) {
					if (string(i + j) == sub(j)) {
						found = true;
					}
					else {
						found = false;
						i = i + j;
						break;
					}
				}

				if (found) {
					start = i;
					end = i + sub.len() - 1;
					break;
				}
			}
		}		

		if (found) {
			cout << "Подстрока " << sub << " в строке " << string << " начинается с " << start << " при поиске от " << startIndex << " символа в строке" << endl;
		}
		else {
			cout << "Подстрока " << sub << " в строке " << string << " при поиске от " << startIndex << " не содержится"<< endl;
		}

		return start;
	}
}