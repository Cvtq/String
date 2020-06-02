#pragma once
#include "string.h"

int find(String string, String sub, size_t startIndex) {

	// ������������ ��������� ������
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
			cout << "��������� " << sub << " � ������ " << string << " ���������� � " << start << " ��� ������ �� " << startIndex << " ������� � ������" << endl;
		}
		else {
			cout << "��������� " << sub << " � ������ " << string << " ��� ������ �� " << startIndex << " �� ����������"<< endl;
		}

		return start;
	}
}