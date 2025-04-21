#include <iostream>
#include <iomanip>
#include <limits>
#include "Modules/Sumar.h"

using namespace std;

void depositCalculation() {
    double depositAmount;
    int termMonths;

    cout << "Задача  № 9.1" << endl;
    cout << "Програма для обрахунку суми щомісячних виплат депозиту" << endl;

    cout << "Введіть суму депозиту (грн.): ";
    cin >> depositAmount;
    cout << "Введіть строк дії угоди (місяців): ";
    cin >> termMonths;

    if (termMonths <= 0 || depositAmount <= 0) {
        cout << "Некоректні вхідні дані. Сума депозиту та строк угоди повинні бути додатними." << endl;
        return;
    }

    double annualRate = (termMonths <= 6) ? 16.0 : 18.0;
    double monthlyRate = annualRate / 12.0 / 100.0;
    double monthlyInterest = depositAmount * monthlyRate;
    double totalInterest = monthlyInterest * termMonths;

    cout << fixed << setprecision(2);
    cout << "Сума щомісячних виплат відсотків: " << monthlyInterest << " грн." << endl;
    cout << "Загальна сума відсотків за весь строк: " << totalInterest << " грн." << endl;
}

int getBeaufortScale(double windSpeed) {
    if (windSpeed < 0.3) return 0;
    else if (windSpeed <= 1.5) return 1;
    else if (windSpeed <= 3.3) return 2;
    else if (windSpeed <= 5.4) return 3;
    else if (windSpeed <= 7.9) return 4;
    else if (windSpeed <= 10.7) return 5;
    else if (windSpeed <= 13.8) return 6;
    else if (windSpeed <= 17.1) return 7;
    else if (windSpeed <= 20.7) return 8;
    else if (windSpeed <= 24.4) return 9;
    else if (windSpeed <= 28.4) return 10;
    else if (windSpeed <= 32.6) return 11;
    else return 12;
}

void windSpeedBeaufort() {
    cout << "Задача № 9.2" << endl;
    cout << "Програма для обрахунку швидкості вітру в балах Бофорта в січні за масивом середніх даних" << endl;

    double windSpeeds[31] = {
        2.5, 3.8, 4.2, 5.1, 6.0, 7.2, 4.8, 3.5, 2.8, 5.5,
        6.3, 8.1, 9.0, 7.5, 4.0, 3.2, 2.9, 5.8, 6.5, 7.0,
        8.5, 9.2, 10.5, 11.0, 8.8, 7.3, 6.2, 5.0, 4.5, 3.9,
        2.7
    };

    string beaufortDescriptions[13] = {
        "Безвітря. Дим піднімається вертикально.",
        "Дим гнеться, прапори не обертаються.",
        "Рух повітря відчувається обличчям. Листя шелестить. Прапори обертаються.",
        "Тріпоче листя, хитаються дрібні гілки. Маленькі прапори.",
        "Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу.",
        "Хитаються великі гілки. На воді з’являються хвилі.",
        "Хитаються великі гілки.",
        "Хитаються невеликі стовбури дерев. На морі з’являються хвилі, пінитися.",
        "Ламаються гілки дерев, важко йти проти вітру.",
        "Гілки руйнуються. Зриває покрівлі, руйнує димарі.",
        "Гілки руйнуються. Дерева вириваються з корінням.",
        "Великі руйнування.",
        "Призводить до суттєвих руйнувань."
    };

    double maxWindSpeed = windSpeeds[0];
    int maxBeaufort = getBeaufortScale(windSpeeds[0]);
    int maxWindSpeedDay = 1;

    cout << "Денні швидкості вітру за січень 2025 року:\n";
    for (int day = 0; day < 31; day++) {
        int beaufort = getBeaufortScale(windSpeeds[day]);
        cout << day + 1 << " січня: Швидкість вітру " << windSpeeds[day]
             << " м/с, Шкала Бофорта " << beaufort << "\n";

        if (windSpeeds[day] > maxWindSpeed) {
            maxWindSpeed = windSpeeds[day];
            maxBeaufort = beaufort;
            maxWindSpeedDay = day + 1;
        }
    }

    cout << "\nНайбільша зафіксована швидкість вітру: " << maxWindSpeed
         << " м/с, Шкала Бофорта " << maxBeaufort << "\n";
    cout << "Це сталося " << maxWindSpeedDay << " січня.\n";
    cout << "Опис: " << beaufortDescriptions[maxBeaufort] << "\n";
}

void binaryCount() {
    cout << "Задача № 9.3" << endl;
    cout << "Програма для підрахунку двійкових нулів або одиниць залежно від біта D13" << endl;

    long long number;
    cout << "Введіть натуральне число (від 0 до 9008000): ";
    cin >> number;

    if (number < 0 || number > 9008000) {
        cout << "Некоректне число. Число повинно бути в межах від 0 до 9008000." << endl;
        return;
    }

    bool isD13Set = (number & (1LL << 13)) != 0;

    int zeros = 0, ones = 0;
    for (int i = 0; i < 32; i++) {
        if (number & (1LL << i)) {
            ones++;
        } else {
            zeros++;
        }
    }

    int result = isD13Set ? ones : zeros;
    cout << "Біт D13 дорівнює " << (isD13Set ? "1" : "0") << ".\n";
    cout << "Результат: " << (isD13Set ? "кількість двійкових одиниць: " : "кількість двійкових нулів: ")
         << result << "\n";
}

void calculation() {
    cout << "Обчислення функції s_calculation(x, y, z)" << endl;
    cout << "Введіть значення x: ";
    double x;
    cin >> x;
    cout << "Введіть значення y: ";
    double y;
    cin >> y;
    cout << "Введіть значення z: ";
    double z;
    cin >> z;

    cout << fixed << setprecision(2);
    cout << "Результат обчислення s_calculation(" << x << ", " << y << ", " << z << "): " << s_calculation(x, y, z) << endl;
}

int main() {
    system("chcp 65001 > nul");

    char choice, exitChoice;
    do {
        cout << "\nВиберіть задачу для виконання:\n";
        cout << "k - Обчислення функції s_calculation()\n";
        cout << "h - Задача 9.1 (обчислення депозиту)\n";
        cout << "g - Задача 9.2 (швидкість вітру за шкалою Бофорта)\n";
        cout << "f - Задача 9.3 (підрахунок двійкових нулів/одиниць)\n";
        cout << "Введіть символ: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 'k':
                calculation();
                break;
            case 'h':
                depositCalculation();
                break;
            case 'g':
                windSpeedBeaufort();
                break;
            case 'f':
                binaryCount();
                break;
            default:
                cout << "Некоректний символ! Спробуйте ще раз.\a" << endl;
                break;
        }

        cout << "\nВведіть 'd', 'D' або 'с' для виходу, або будь-який інший символ для продовження: ";
        cin >> exitChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (exitChoice != 'd' && exitChoice != 'D' && exitChoice != 'с');

    cout << "Програма завершена." << endl;
    return 0;
}
