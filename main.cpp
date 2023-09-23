#include <iostream>
#include <string>
#include <sstream>
#include "Rational.h"

int main() {
    std::string input;

    std::cout << "Введите две дроби и операцию в формате 'a/b x c/d', где x - операция (+, -, *, /): ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string fraction1, fraction2, operation;

    // Разбиваем строку на две дроби и операцию
    if (!(iss >> fraction1 >> operation >> fraction2)) {
        std::cout << "Некорректный ввод!" << std::endl;
        return 1;
    }

    // Извлекаем числитель и знаменатель из первой дроби
    std::istringstream iss1(fraction1);
    int numerator1, denominator1;
    char slash1;
    if (!(iss1 >> numerator1 >> slash1 >> denominator1) || slash1 != '/') {
        std::cout << "Некорректный ввод для первой дроби!" << std::endl;
        return 1;
    }

    // Извлекаем числитель и знаменатель из второй дроби
    std::istringstream iss2(fraction2);
    int numerator2, denominator2;
    char slash2;
    if (!(iss2 >> numerator2 >> slash2 >> denominator2) || slash2 != '/') {
        std::cout << "Некорректный ввод для второй дроби!" << std::endl;
        return 1;
    }

    Rational r1(numerator1, denominator1);
    Rational r2(numerator2, denominator2);

    Rational result;
    if (operation == "+") {
        result = r1 + r2;
    } else if (operation == "-") {
        result = r1 - r2;
    } else if (operation == "*") {
        result = r1 * r2;
    } else if (operation == "/") {
        result = r1 / r2;
    } else {
        std::cout << "Некорректная операция!" << std::endl;
        return 1;
    }

    std::cout << "Результат: " << result << std::endl;

    return 0;
}