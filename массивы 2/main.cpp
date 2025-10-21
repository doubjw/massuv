#include <iostream>
#include <ctime>
#include <Windows.h>

void task1()
{
    std::cout << "Задача№1\n";

    const int size = 10;
    int arr[size];

    srand(time(0));

    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    std::cout << "Минимальный элемент: " << min << "\n";
    std::cout << "Максимальный элемент: " << max << "\n";
    std::cout << "\n";
}

void task2() 
{
    std::cout << "\nЗадача№2\n";

    const int size = 10;
    int arr[size];

    int range_min, range_max, user_value;

    std::cout << "Введите минимальное значение диапазона: ";
    std::cin >> range_min;
    std::cout << "Введите максимальное значение диапазона: ";
    std::cin >> range_max;
    std::cout << "Введите значение для сравнения: ";
    std::cin >> user_value;

    srand(time(0));

    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = range_min + rand() % (range_max - range_min + 1);
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < user_value) {
            sum += arr[i];
        }
    }

    std::cout << "Сумма элементов меньше " << user_value << ": " << sum << "\n";
    std::cout << "\n";
}

void task3() 
{
    std::cout << "\nЗадача№3\n";

    const int months = 12;
    double profit[months];
    std::string month_names[months] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};

    std::cout << "Введите прибыль фирмы за 12 месяцев:" << "\n";
    for (int i = 0; i < months; i++) {
        std::cout << month_names[i] << ": ";
        std::cin >> profit[i];
    }

    int start_month, end_month;
    std::cout << "Введите начальный месяц диапазона (1-12): ";
    std::cin >> start_month;
    std::cout << "Введите конечный месяц диапазона (1-12): ";
    std::cin >> end_month;

    start_month--;
    end_month--;

    if (start_month < 0 || start_month >= months ||
        end_month < 0 || end_month >= months ||
        start_month > end_month) {
        std::cout << "Ошибка: неверный диапазон месяцев!" << "\n";
        return;
    }

    int min_month = start_month;
    int max_month = start_month;

    for (int i = start_month + 1; i <= end_month; i++) {
        if (profit[i] < profit[min_month]) {
            min_month = i;
        }
        if (profit[i] > profit[max_month]) {
            max_month = i;
        }
    }

    std::cout << "В диапазоне с " << month_names[start_month] << " по " << month_names[end_month] << ":" << "\n";
    std::cout << "Минимальная прибыль в " << month_names[min_month] << ": " << profit[min_month] << "\n";
    std::cout << "Максимальная прибыль в " << month_names[max_month] << ": " << profit[max_month] << "\n";
    std::cout << "\n";
}

int main() 
{
    setlocale(LC_ALL, "ru");

    task1();
    task2();
    task3();

    return 0;
}