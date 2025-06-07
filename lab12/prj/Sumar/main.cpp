#include <iostream>
#include <cmath>
#include <stdexcept>
#include <windows.h>

class ClassLab12_Sumar {
private:
    double radius;
    double height;
    double lavaPercentage;

public:
    ClassLab12_Sumar(double r, double h, double lavaPerc)
        : radius(r), height(h), lavaPercentage(lavaPerc) {
        validateInputs(r, h, lavaPerc);
    }

    double getRadius() const { return radius; }
    double getHeight() const { return height; }
    double getLavaPercentage() const { return lavaPercentage; }

    double calculateVolume() const {
        double baseArea = M_PI * radius * radius;
        return baseArea * height;
    }

    double getLavaVolume() const {
        return calculateVolume() * lavaPercentage / 100.0;
    }

    double getLiquidVolume() const {
        return calculateVolume() - getLavaVolume();
    }

    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            throw std::invalid_argument("Радіус має бути позитивним числом.");
        }
    }

    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            throw std::invalid_argument("Висота має бути позитивним числом.");
        }
    }

    void setLavaPercentage(double lavaPerc) {
        if (lavaPerc >= 0 && lavaPerc <= 100) {
            lavaPercentage = lavaPerc;
        } else {
            throw std::invalid_argument("Відсоток лави має бути в діапазоні від 0 до 100.");
        }
    }

private:
    void validateInputs(double r, double h, double lavaPerc) {
        if (r <= 0 || h <= 0) {
            throw std::invalid_argument("Радіус та висота мають бути позитивними числами.");
        }
        if (lavaPerc < 0 || lavaPerc > 100) {
            throw std::invalid_argument("Відсоток лави має бути в діапазоні від 0 до 100.");
        }
    }
};

void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Показати об'єм лампи\n";
    std::cout << "2. Показати об'єм лави\n";
    std::cout << "3. Показати об'єм рідини\n";
    std::cout << "4. Змінити радіус\n";
    std::cout << "5. Змінити висоту\n";
    std::cout << "6. Змінити відсоток лави\n";
    std::cout << "7. Вийти\n";
    std::cout << "Оберіть опцію: ";
}

void displayCurrentParameters(const ClassLab12_Sumar& lamp) {
    std::cout << "Поточні параметри лампи:\n";
    std::cout << "Радіус: " << lamp.getRadius() << "\n";
    std::cout << "Висота: " << lamp.getHeight() << "\n";
    std::cout << "Відсоток лави: " << lamp.getLavaPercentage() << "\n";
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "Автор: Ілля Сумар\n";
    std::cout << "Формула для обчислення об'єму циліндра: V = π * r^2 * h\n\n";

    ClassLab12_Sumar lamp(5.0, 10.0, 30.0);
    displayCurrentParameters(lamp);

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Об'єм лампи: " << lamp.calculateVolume() << std::endl;
                    break;
                case 2:
                    std::cout << "Об'єм лави: " << lamp.getLavaVolume() << std::endl;
                    break;
                case 3:
                    std::cout << "Об'єм рідини: " << lamp.getLiquidVolume() << std::endl;
                    break;
                case 4: {
                    double r;
                    std::cout << "Введіть новий радіус: ";
                    std::cin >> r;
                    lamp.setRadius(r);
                    displayCurrentParameters(lamp);
                    break;
                }
                case 5: {
                    double h;
                    std::cout << "Введіть нову висоту: ";
                    std::cin >> h;
                    lamp.setHeight(h);
                    displayCurrentParameters(lamp);
                    break;
                }
                case 6: {
                    double lavaPerc;
                    std::cout << "Введіть новий відсоток лави: ";
                    std::cin >> lavaPerc;
                    lamp.setLavaPercentage(lavaPerc);
                    displayCurrentParameters(lamp);
                    break;
                }
                case 7:
                    std::cout << "Вихід..." << std::endl;
                    break;
                default:
                    std::cout << "Невірний вибір, спробуйте ще раз." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Помилка: " << e.what() << std::endl;
            // Програма продовжує роботу після виведення повідомлення про помилку
        }
    } while (choice != 7);

    return 0;
}
