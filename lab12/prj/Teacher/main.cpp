#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <windows.h>
#include <cmath>

using namespace std;

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
            throw invalid_argument("Помилка: Радіус має бути позитивним числом.");
        }
    }

    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            throw invalid_argument("Помилка: Висота має бути позитивним числом.");
        }
    }

    void setLavaPercentage(double lavaPerc) {
        if (lavaPerc >= 0 && lavaPerc <= 100) {
            lavaPercentage = lavaPerc;
        } else {
            throw invalid_argument("Помилка: Відсоток лави має бути в діапазоні від 0 до 100.");
        }
    }

private:
    void validateInputs(double r, double h, double lavaPerc) {
        if (r <= 0 || h <= 0) {
            throw invalid_argument("Помилка: Радіус та висота мають бути позитивними числами.");
        }
        if (lavaPerc < 0 || lavaPerc > 100) {
            throw invalid_argument("Помилка: Відсоток лави має бути в діапазоні від 0 до 100.");
        }
    }
};

void runTestSuite() {
    SetConsoleOutputCP(CP_UTF8);
    system("chcp 65001 > nul");

    ifstream testFile("TestSuite.txt");
    ofstream resultsFile("TestResults.txt");

    if (!testFile.is_open()) {
        cerr << "Помилка: файл тестів не знайдено." << endl;
        MessageBeep(MB_ICONERROR);
        return;
    }

    string line;
    while (getline(testFile, line)) {
        istringstream iss(line);
        int testNumber, functionNumber;
        double value;
        string expectedResult;

        iss >> testNumber >> functionNumber >> value;
        getline(iss, expectedResult);
        expectedResult.erase(0, expectedResult.find_first_not_of(" \t\n\r\f\v"));

        ClassLab12_Sumar lamp(5.0, 10.0, 30.0);

        try {
            switch (functionNumber) {
                case 1: {
                    ostringstream oss;
                    oss << "Об'єм лампи: " << lamp.calculateVolume();
                    if (oss.str() == expectedResult) {
                        resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                    } else {
                        resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                    }
                    break;
                }
                case 2: {
                    ostringstream oss;
                    oss << "Об'єм лави: " << lamp.getLavaVolume();
                    if (oss.str() == expectedResult) {
                        resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                    } else {
                        resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                    }
                    break;
                }
                case 3: {
                    ostringstream oss;
                    oss << "Об'єм рідини: " << lamp.getLiquidVolume();
                    if (oss.str() == expectedResult) {
                        resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                    } else {
                        resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                    }
                    break;
                }
                case 4: {
                    try {
                        lamp.setRadius(value);
                        ostringstream oss;
                        oss << "Поточні параметри лампи: Радіус: " << lamp.getRadius() << " Висота: " << lamp.getHeight() << " Відсоток лави: " << lamp.getLavaPercentage();
                        if (oss.str() == expectedResult) {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                        } else {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                        }
                    } catch (const invalid_argument& e) {
                        if (string(e.what()) == expectedResult) {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << e.what() << "\n";
                        } else {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << e.what() << "\n";
                        }
                    }
                    break;
                }
                case 5: {
                    try {
                        lamp.setHeight(value);
                        ostringstream oss;
                        oss << "Поточні параметри лампи: Радіус: " << lamp.getRadius() << " Висота: " << lamp.getHeight() << " Відсоток лави: " << lamp.getLavaPercentage();
                        if (oss.str() == expectedResult) {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                        } else {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                        }
                    } catch (const invalid_argument& e) {
                        if (string(e.what()) == expectedResult) {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << e.what() << "\n";
                        } else {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << e.what() << "\n";
                        }
                    }
                    break;
                }
                case 6: {
                    try {
                        lamp.setLavaPercentage(value);
                        ostringstream oss;
                        oss << "Поточні параметри лампи: Радіус: " << lamp.getRadius() << " Висота: " << lamp.getHeight() << " Відсоток лави: " << lamp.getLavaPercentage();
                        if (oss.str() == expectedResult) {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                        } else {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << oss.str() << "\n";
                        }
                    } catch (const invalid_argument& e) {
                        if (string(e.what()) == expectedResult) {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": PASSED, очікувалося: " << expectedResult << ", отримано: " << e.what() << "\n";
                        } else {
                            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, очікувалося: " << expectedResult << ", отримано: " << e.what() << "\n";
                        }
                    }
                    break;
                }
                default:
                    resultsFile << "Невідомий вибір функції: " << functionNumber << "\n";
            }
        } catch (const exception& e) {
            resultsFile << "Тест " << testNumber << " з функцією " << functionNumber << " та значенням " << value << ": FAILED, помилка: " << e.what() << "\n";
        }
    }

    testFile.close();
    resultsFile.close();
}

int main() {
    runTestSuite();
    cout << "Тести завершено." << endl;
    system("pause");
    return 0;
}
