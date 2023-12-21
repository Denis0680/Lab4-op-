#include <iostream>
#include <iomanip>

const int MAX_WORKERS = 10;  // Максимальна кількість працівників
const int MAX_NAME_LENGTH = 50;  // Максимальна довжина прізвища та ініціалів
const int MAX_POS_LENGTH = 50;  // Максимальна довжина посади

struct WORKER {
    char NAME[MAX_NAME_LENGTH];
    char POS[MAX_POS_LENGTH];
    int YEAR;
    int MONTH;
};

void inputWorkers(WORKER TABL[], int N) {
    for (int i = 0; i < N; ++i) {
        std::cout << "Enter data for the employee #" << i + 1 << ":\n";
        std::cout << "Surname and initials: ";
        std::cin.getline(TABL[i].NAME, MAX_NAME_LENGTH);

        std::cout << "position: ";
        std::cin.getline(TABL[i].POS, MAX_POS_LENGTH);

        std::cout << "Year of employment: ";
        std::cin >> TABL[i].YEAR;

        std::cout << "Month of employment: ";
        std::cin >> TABL[i].MONTH;

        std::cin.ignore();  // Очищення буфера введення
    }
}

// Функція для впорядкування записів в алфавітному порядку
void sortWorkers(WORKER TABL[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (strcmp(TABL[j].NAME, TABL[j + 1].NAME) > 0) {
                // Обмін елементів, якщо потрібно впорядкувати
                std::swap(TABL[j], TABL[j + 1]);
            }
        }
    }
}

// Функція для виведення прізвищ працівників, стаж роботи яких перевищує задане значення
void printExperiencedWorkers(WORKER TABL[], int N, int experienceThreshold) {
    bool found = false;

    std::cout << "\nSurnames of employees with more than" << experienceThreshold << " years of experience:\n";

    for (int i = 0; i < N; ++i) {
        int currentYear = 2023;  
        int experience = currentYear - TABL[i].YEAR;

        if (experience > experienceThreshold) {
            found = true;
            std::cout << TABL[i].NAME << " (experience: " << experience << " years)\n";
        }
    }

    if (!found) {
        std::cout << "There are no employees with the specified length of experience.\n";
    }
}

int main() {
    int N;
    std::cout << "Number of workers: ";
    std::cin >> N;

    std::cin.ignore();  

    WORKER TABL[MAX_WORKERS];

    // Введення даних
    inputWorkers(TABL, N);

    // Впорядкування за алфавітом
    sortWorkers(TABL, N);

    // Виведення впорядкованих даних
    std::cout << "\nOrdered list of employees:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << std::setw(2) << i + 1 << ". " << TABL[i].NAME << " (" << TABL[i].POS << ")\n";
    }

    // Виведення працівників із заданим стажем
    int experienceThreshold;
    std::cout << "\nEnter experience to find employees with more expirience: ";
    std::cin >> experienceThreshold;

    printExperiencedWorkers(TABL, N, experienceThreshold);

    return 0;
}
