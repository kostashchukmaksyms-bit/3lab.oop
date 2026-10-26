#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>

// ЧАСТИНА 1: Структура та зовнішні функції

struct Part1 {
    double a;
    double b;
    double c;
};

void init(Part1& obj, double a, double b, double c) {

    obj.a = a;
    obj.b = b;
    obj.c = c;
}

void input(Part1& obj) {
    while (true) {
        std::cout << "Введіть коефіцієнти a, b, c через пробіл (наприклад: 1 -3 2): ";
        if (std::cin >> obj.a >> obj.b >> obj.c) {
            if (obj.a == 0) {
                std::cout << "Помилка! Коефіціент 'a' не може дорівнювати 0, оскільки це квадратне рівняння\n";
            }else {
            break;
        }
        } else {
            std::cout << "Помилка! Ви ввели некоректні дані (слово або символ). Будь ласка, введіть числа!\n";
            std::cin.clear(); // Скидаємо стан помилки cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void output(const Part1& obj) {
    std::cout << "y = " << obj.a << "x^2 + " << obj.b << "x + " << obj.c << std::endl;
}

char* toPChar(const Part1& obj) {
    char* str = new char[100];
    std::sprintf(str, "y = %.2fx^2 + %.2fx + %.2f", obj.a, obj.b, obj.c);
    return str;
}

void shift(Part1& obj) {
    obj.c += 1.0;
}

void odd(const Part1& obj) {
    if (obj.b == 0) {
        std::cout << "Функція є парною." << std::endl;
    } else {
        std::cout << "Функція ні парна, ні непарна." << std::endl;
    }
}

void roots(const Part1& obj) {
    if (obj.a == 0) {
        if (obj.b != 0) {
            std::cout << "Корінь: x = " << -obj.c / obj.b << std::endl;
        } else {
            std::cout << (obj.c == 0 ? "Безліч коренів." : "Коренів немає.") << std::endl;
        }
        return;
    }

    double D = obj.b * obj.b - 4 * obj.a * obj.c;
    if (D > 0) {
        double x1 = (-obj.b + std::sqrt(D)) / (2 * obj.a);
        double x2 = (-obj.b - std::sqrt(D)) / (2 * obj.a);
        std::cout << "Корені: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (D == 0) {
        std::cout << "Один корінь: x = " << -obj.b / (2 * obj.a) << std::endl;
    } else {
        std::cout << "Дійсних коренів немає (D < 0)." << std::endl;
    }
}

void printVertex(const Part1& obj) {
    if (obj.a == 0) {
        std::cout << "Вершина відсутня (a = 0)." << std::endl;
        return;
    }
    double xv = -obj.b / (2 * obj.a);
    double yv = obj.a * xv * xv + obj.b * xv + obj.c;
    std::cout << "Вершина параболи: (" << xv << ", " << yv << ")" << std::endl;
}

void printIntersectionPointsCount(const Part1& obj) {
    if (obj.a == 0) {
        std::cout << "Кількість точок перетину з OX: " << (obj.b != 0 ? 1 : 0) << std::endl;
        return;
    }
    double D = obj.b * obj.b - 4 * obj.a * obj.c;
    if (D > 0) std::cout << "Кількість точок перетину з OX: 2" << std::endl;
    else if (D == 0) std::cout << "Кількість точок перетину з OX: 1" << std::endl;
    else std::cout << "Кількість точок перетину з OX: 0" << std::endl;
}

// main()

int main() {
    // 1. ЧАСТИНА 1 (Структура)
    std::cout << "=== ЧАСТИНА 1 (Структура) ===" << std::endl;
    Part1 p1;
    input(p1);

    std::cout << "Виведення вашої функції: ";
    output(p1);

    char* str1 = toPChar(p1);
    std::cout << "Рядок toPChar(): " << str1 << std::endl;
    delete[] str1;

    shift(p1);
    std::cout << "Після shift() (+1 вгору): ";
    output(p1);

    odd(p1);
    roots(p1);
    printVertex(p1);
    printIntersectionPointsCount(p1);

        return 0;
}
