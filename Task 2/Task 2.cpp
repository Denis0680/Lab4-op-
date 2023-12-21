#include <iostream>

int main() {
	const int Max_rows = 10; // Максимальна кількість рядків
	const int Max_cols = 10; // Максимальна кількість стовпців

	int** matrix = new int* [Max_rows]; // Створення масиву вказівників на рядки

	for (int i = 0; i < Max_rows; ++i) {
		matrix[i] = new int[Max_cols]; // Створення кожного рядка
	}

	// Ініціалізація матриці
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;

	matrix[1][0] = 7;
	matrix[1][1] = 0;
	matrix[1][2] = 700;

	matrix[2][0] = 8;
	matrix[2][1] = 700;
	matrix[2][2] = 40;

	matrix[3][0] = 30;
	matrix[3][1] = 20;
	matrix[3][2] = 50;

	int rows = 4; // Кількість рядків
	int cols = 3; // Кількість стовпців

	int zerow = 0;
	for (int i = 0; i < rows; ++i) {
		bool hasZero = true;

		for (int l = 0; l < cols; ++l) {
			if (matrix[i][l] == 0) {
				hasZero = false;
				break;
			}
		}
		if (hasZero) {
			zerow++;
		}
	}
	std::cout << "rows without 0: " << zerow << '\n';

	int MaxRepeatedNum = -1; // Максимальне число, яке зустрічається більше 1 разу
	int MaxRep = 1; // Максимальна кількість повторень

	for (int i = 0; i < rows; ++i) {
		for (int l = 0; l < cols; ++l) {
			int CurrentNum = matrix[i][l];
			int CurrentRep = 1;

			for (int y = i + 1; y < rows; ++y) {
				for (int j = 0; j < cols; ++j) {
					if (matrix[y][j] == CurrentNum) {
						CurrentRep++;
					}
				}
			}
			if (CurrentRep > 1 && CurrentRep > MaxRep) {
				MaxRepeatedNum = CurrentNum;
				MaxRep = CurrentRep;
			}
		}
	}
	if (MaxRepeatedNum != -1) {
		std::cout << "max repeated number: " << MaxRepeatedNum << '\n';
	}
	else {
		std::cout << "ERROR";
	}

	// Вивільнення пам'яті
	for (int i = 0; i < Max_rows; ++i) {
		delete[] matrix[i];
	}

	delete[] matrix;

	return 0;
}
