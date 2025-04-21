#include <iostream>
#include <iomanip>
#include <cmath>
#include "Functions.h"

using namespace std;

// Test for depositCalculation (Task 9.1)
void testDepositCalculation() {
    cout << "Тестування depositCalculation (Задача 9.1)\n";

    // Test 1: Normal case (depositAmount = 1000, termMonths = 3)
    DepositResult result1 = depositCalculation(1000.0, 3);
    cout << "Тест #1: depositAmount = 1000, termMonths = 3\n";
    cout << "Очікуваний monthlyInterest: 13.33, totalInterest: 40.00\n";
    cout << "Результат: monthlyInterest = " << result1.monthlyInterest << ", totalInterest = " << result1.totalInterest << "\n";
    if (result1.valid && abs(result1.monthlyInterest - 13.33) < 0.01 && abs(result1.totalInterest - 40.00) < 0.01) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    // Test 2: Invalid case (depositAmount = -100, termMonths = 3)
    DepositResult result2 = depositCalculation(-100.0, 3);
    cout << "Тест #2: depositAmount = -100, termMonths = 3\n";
    cout << "Очікується: невалідний результат\n";
    cout << "Результат: " << (result2.valid ? "валідний" : "невалідний") << "\n";
    if (!result2.valid) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    cout << "-------------------------\n";
}

// Test for getBeaufortScale (Task 9.2 helper)
void testGetBeaufortScale() {
    cout << "Тестування getBeaufortScale (допоміжна фуsнкція для Задачі 9.2)\n";

    // Test 1: Wind speed 2.5 (should return 2)
    int result1 = getBeaufortScale(2.5);
    cout << "Тест #1: windSpeed = 2.5\n";
    cout << "Очікуваний результат: 2\n";
    cout << "Результат: " << result1 << "\n";
    if (result1 == 2) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    // Test 2: Wind speed 35.0 (should return 12)
    int result2 = getBeaufortScale(35.0);
    cout << "Тест #2: windSpeed = 35.0\n";
    cout << "Очікуваний результат: 12\n";
    cout << "Результат: " << result2 << "\n";
    if (result2 == 12) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    cout << "-------------------------\n";
}

// Test for windSpeedBeaufort (Task 9.2)
void testWindSpeedBeaufort() {
    cout << "Тестування windSpeedBeaufort (Задача 9.2)\n";

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

    WindSpeedResult result = windSpeedBeaufort(windSpeeds, beaufortDescriptions);
    cout << "Тест #1: Використання масиву windSpeeds\n";
    cout << "Очікуваний maxWindSpeed: 11.0, maxBeaufort: 6, maxWindSpeedDay: 24\n";
    cout << "Результат: maxWindSpeed = " << result.maxWindSpeed << ", maxBeaufort = " << result.maxBeaufort << ", maxWindSpeedDay = " << result.maxWindSpeedDay << "\n";
    if (result.valid && abs(result.maxWindSpeed - 11.0) < 0.01 && result.maxBeaufort == 6 && result.maxWindSpeedDay == 24) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    cout << "-------------------------\n";
}

// Test for binaryCount (Task 9.3)
void testBinaryCount() {
    cout << "Тестування binaryCount (Задача 9.3)\n";

    // Test 1: Number 8192 (D13 is set, should count ones)
    BinaryCountResult result1 = binaryCount(8192);
    cout << "Тест #1: number = 8192\n";
    cout << "Очікуваний результат: isD13Set = true, result = 1 (кількість одиниць)\n";
    cout << "Результат: isD13Set = " << (result1.isD13Set ? "true" : "false") << ", result = " << result1.result << "\n";
    if (result1.valid && result1.isD13Set && result1.result == 1) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    // Test 2: Invalid number (number > 9008000)
    BinaryCountResult result2 = binaryCount(9008001);
    cout << "Тест #2: number = 9008001\n";
    cout << "Очікується: невалідний результат\n";
    cout << "Результат: " << (result2.valid ? "валідний" : "невалідний") << "\n";
    if (!result2.valid) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    cout << "-------------------------\n";
}

// Test for calculation (Task 9.4)
void testCalculation() {
    cout << "Тестування calculation (Задача 9.4)\n";

    // Test 1: Normal case (x = 1, y = 2, z = 3)
    double result1 = calculation(1.0, 2.0, 3.0);
    cout << "Тест #1: x = 1, y = 2, z = 3\n";
    cout << "Очікуваний результат: -5.48\n";
    cout << "Результат: " << result1 << "\n";
    if (abs(result1 - (-5.48)) < 0.01) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    // Test 2: Zero values (should return 0 due to invalid denominator)
    double result2 = calculation(0.0, 0.0, 0.0);
    cout << "Тест #2: x = 0, y = 0, z = 0\n";
    cout << "Очікуваний результат: 0.00\n";
    cout << "Результат: " << result2 << "\n";
    if (abs(result2 - 0.0) < 0.01) {
        cout << "Тест пройдено!\n";
    } else {
        cout << "Тест не пройдено!\n";
    }

    cout << "-------------------------\n";
}

int main() {
    system("chcp 65001 > nul");
    cout << "Запуск TestDriver для всіх функцій\n\n";

    testDepositCalculation();
    testGetBeaufortScale();
    testWindSpeedBeaufort();
    testBinaryCount();
    testCalculation();

    cout << "Тестування завершено.\n";
    system("pause");
    return 0;
}
