#include <iostream>
#include <windows.h>
#include <cmath>
#include <fcntl.h>
#include "Sumar.h" 

using namespace std;

void exercise8_2_1() {
    wcout << L"Розробник програми : Сумар Ілля ©\n";
}

bool exercise8_2_2() {
    wchar_t a, b;

    wcout << L"Введіть символи a і b (наприклад: 'A' 'z'): ";
    while (!(wcin >> a >> b) || !iswalpha(a) || !iswalpha(b)) {
        wcin.clear();
        wcin.ignore(10000, '\n');
        wcout << L"Помилка вводу! Спробуйте ще раз.\n";
        wcout << L"Введіть a і b: ";
    }

    bool result = towlower(a) <= towlower(b);

    wcout << L"Результат логічного рівняння: " << result << endl;

    return result;
}

void exercise8_2_3(double x, double y, double z) {
    double S;
    wcout << L"Введіть нові значення для x, y, z:\n";
    while (!(wcin >> x >> y >> z)) {
        wcin.clear();
        wcin.ignore(10000, '\n');
        wcout << L"Помилка вводу! Спробуйте ще раз.\n";
        wcout << L"Введіть x, y, z: ";
    }

    wcout << L"Десяткова система:\n";
    wcout << L"x = " << x << L", y = " << y << L", z = " << z << endl;

    wcout << L"Шістнадцяткова система:\n";
    wcout << L"x = " << hex << (int)x
          << L", y = " << hex << (int)y
          << L", z = " << hex << (int)z << endl << endl;
        wcout << dec << noshowbase;
        S = s_calculation(x, y, z);
        wcout << L"Результат S за допомогою S_calculation = " << S << endl;
          
}

void showAbout() {
    wcout << L"════════════════════════════════════════\n";
    wcout << L"            ПРОГРАМА ВАРІАНТ №8          \n";
    wcout << L"----------------------------------------\n";
    wcout << L"Ця програма містить дві задачі:\n";
    wcout << L"Перша обраховує S за допомогою x, y, z.\n";
    wcout << L"Друга має три під задачі,перша - виводить інформацію про розробника.\n";
    wcout << L"Друга виводить результат логічного рівняння (1/0)\n";
    wcout << L"Третя виводить x, y, z у десятковій і шістнадцятковій системах,\nта S за допомогою власної бібліотеки Sumar.h\n" ;
    wcout << L"----------------------------------------\n";
    wcout << L"   Розробник: Сумар Ілля\n";
    wcout << L"   Версія: 1.0\n";
    wcout << L"════════════════════════════════════════\n";
}

int main() {
    SetConsoleOutputCP(1251);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    int choice;
    double x, y, z, S;

    do {
        wcout << L"\n══════════════════════════════════\n";
        wcout << L"  Виберіть завдання:\n";
        wcout << L"  1 - Інформація про програму\n";
        wcout << L"  2 - Обрахунок S\n";
        wcout << L"  3 - Додаткові вправи\n";
        wcout << L"  0 - Вихід\n";
        wcout << L"══════════════════════════════════\n";
        wcout << L"Ваш вибір: ";
        wcin >> choice;

        if (choice == 2) {
            wcout << L"Введіть x, y, z: ";
            if (!(wcin >> x >> y >> z)) {
                wcin.clear();
                wcin.ignore(10000, '\n');
                wcout << L"Помилка вводу! Спробуйте ще раз.\n";
                continue;
            }
            double numerator = abs(pow(z, 2) * exp(x));
            double e = exp(x);
                double denominator = 12 * x + pow(y, 2) - M_PI * sqrt(z);
                double S = pow(x, 2) - pow(y, 3) + sqrt(numerator / denominator);
            wcout << L"Результат S= " << S << endl;
        }

        else if (choice == 3) {
            exercise8_2_1();
            exercise8_2_2();
            exercise8_2_3(x, y, z);
        }

        else if (choice == 1) {
            showAbout();
        }

    } while (choice != 0);

    return 0;
}
