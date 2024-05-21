#include "main.h"
#include "dataBase/dataBase.h"
#include <iostream>
using namespace std;
int Food::count = 0;
int is_interactive = 1;

int menu() {
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "1 - добавление продукта\t 4 - корректировка сведений" << endl;
    cout << "2 - удаление продукта\t 5 - вывод базы данных на экран" << endl;
    cout << "3 - прочитать файл\t\t 6 - сортировка базы данных" << endl;
    cout << "7 - вывод базы данных в файл\t\t" << endl;
    cout << "8 - вывести категорию\t\t" << endl;
    cout << "9 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 9" << endl;
    cout << "Введите номер команды:" << endl;
    int com;
    cin >> com;
    cin.clear();
    cin.ignore(10, '\n');
    return com;
}

