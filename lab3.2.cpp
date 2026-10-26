#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>

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

// ЧАСТИНА 2: Клас

class Part2 {
private:
    Part1 object;

public:
    void init(double a, double b, double c);
    void input();
    void output() const;
    char* toPChar() const;

    Part1 getStruct() const;
    void setStruct(const Part1& s);

    double getA() const;
    double getB() const;
    double getC() const;

    void setA(double a);
    void setB(double b);
    void setC(double c);
};

void Part2::init(double a, double b, double c) {
    object.a = a;
    object.b = b;
    object.c = c;
}

void Part2::input() {
    while (true) {
        std::cout << "Введіть коефіцієнти a, b, c через пробіл (a не може дорівнювати 0): ";
        if (std::cin >> object.a >> object.b >> object.c) {
            if (object.a == 0) {
                std::cout << "Помилка! Коефіцієнт 'a' не може дорівнювати 0, оскільки функція має бути квадратичною!\n";
            } else {
                break; // Усе введено коректно і a != 0 — виходимо з циклу
            }
        } else {
            std::cout << "Помилка! Ви ввели некоректні дані (букви/символи). Введіть саме числа!\n";
            std::cin.clear(); // Скидаємо прапорець помилки cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаємо буфер
        }
    }
}

void Part2::output() const {
    std::cout << "y = " << object.a << "x^2 + " << object.b << "x + " << object.c << std::endl;
}

char* Part2::toPChar() const {
    char* str = new char[100];
    std::sprintf(str, "y = %.2fx^2 + %.2fx + %.2f", object.a, object.b, object.c);
    return str;
}

Part1 Part2::getStruct() const { return object; }
void Part2::setStruct(const Part1& s) { object = s; }

double Part2::getA() const { return object.a; }
double Part2::getB() const { return object.b; }
double Part2::getC() const { return object.c; }

void Part2::setA(double a) { object.a = a; }
void Part2::setB(double b) { object.b = b; }
void Part2::setC(double c) { object.c = c; }

// Сторонні функції
void shift(Part2& obj) {
    obj.setC(obj.getC() + 1.0);
}

void odd(const Part2& obj) {
    if (obj.getB() == 0) {
        std::cout << "Функція є парною." << std::endl;
    } else {
        std::cout << "Функція ні парна, ні непарна." << std::endl;
    }
}

void roots(const Part2& obj) {
    double a = obj.getA();
    double b = obj.getB();
    double c = obj.getC();

    if (a == 0) {
        if (b != 0) std::cout << "Корінь: x = " << -c / b << std::endl;
        else std::cout << "Коренів немає." << std::endl;
        return;
    }

    double D = b * b - 4 * a * c;
    if (D > 0) {
        double x1 = (-b + std::sqrt(D)) / (2 * a);
        double x2 = (-b - std::sqrt(D)) / (2 * a);
        std::cout << "Корені: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (D == 0) {
        std::cout << "Один корінь: x = " << -b / (2 * a) << std::endl;
    } else {
        std::cout << "Дійсних коренів немає." << std::endl;
    }
}

void printVertex(const Part2& obj) {
    double a = obj.getA(), b = obj.getB(), c = obj.getC();
    if (a == 0) {
        std::cout << "Вершина відсутня (a = 0)." << std::endl;
        return;
    }
    double xv = -b / (2 * a);
    double yv = a * xv * xv + b * xv + c;
    std::cout << "Вершина: (" << xv << ", " << yv << ")" << std::endl;
}

void printIntersectionPointsCount(const Part2& obj) {
    double a = obj.getA(), b = obj.getB(), c = obj.getC();
    if (a == 0) {
        std::cout << "Кількість точок перетину з OX: " << (b != 0 ? 1 : 0) << std::endl;
        return;
    }
    double D = b * b - 4 * a * c;
    if (D > 0) std::cout << "Кількість точок перетину з OX: 2" << std::endl;
    else if (D == 0) std::cout << "Кількість точок перетину з OX: 1" << std::endl;
    else std::cout << "Кількість точок перетину з OX: 0" << std::endl;
}

// main()

int main() {

// 2. ЧАСТИНА 2 (Клас)
    std::cout << "\n=== ЧАСТИНА 2 (Клас) ===" << std::endl;
    Part2 p2;
    p2.input();

    std::cout << "Виведення вашої функції: ";
    p2.output();

    char* str2 = p2.toPChar();
    std::cout << "Рядок toPChar(): " << str2 << std::endl;
    delete[] str2;

    shift(p2);
    std::cout << "Після shift() (+1 вгору): ";
    p2.output();

    odd(p2);
    roots(p2);
    printVertex(p2);
    printIntersectionPointsCount(p2);

    return 0;
}