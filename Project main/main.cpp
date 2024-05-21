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

int interactive(){
    const char* filename1 = "BD_Diet.txt";
    const char* filename2 = "BD_Diet_res.txt";
    int n = 0;
    int size;
    ifstream fin(filename1, ios::in | ios::binary);
    fin >> size;
    fin.close();
    Food* arr = new Food[size];
    while(true){
        switch(menu()){
            case 1:
                arr = Food::add(arr, n, size, is_interactive); break;
            case 2:
                arr = Food::remove(arr, n, size, is_interactive); break;
            case 3:
                Food::read_dbase(filename1, arr, n); break;
            case 4:
                Food::edit(arr, n, is_interactive); break;
            case 5:
                Food::print_dbase(arr, n); break;
            case 6:
                Food::sort_dbase(arr, n); break;
            case 7:
                Food::write_dbase(filename2, arr, n); break;
            case 9:
                delete[] arr;
                return 0;
        }
    }
    return 0;
}

void createDietForOverweight() {
    char breakfast[50], lunch[50], dinner[50];
    std::cout << "Enter breakfast plan for losing weight: ";
    std::cin >> breakfast;
    std::cout << "Enter lunch plan for losing weight: ";
    std::cin >> lunch;
    std::cout << "Enter dinner plan for losing weight: ";
    std::cin >> dinner;

    std::cout << "Diet plan for losing weight created:\nBreakfast: " << breakfast << "\nLunch: " << lunch << "\nDinner: " << dinner << std::endl;
}

void createDietForUnderweight() {
    char breakfast[50], lunch[50], dinner[50];
    std::cout << "Enter breakfast plan for gaining weight: ";
    std::cin >> breakfast;
    std::cout << "Enter lunch plan for gaining weight: ";
    std::cin >> lunch;
    std::cout << "Enter dinner plan for gaining weight: ";
    std::cin >> dinner;

    std::cout << "Diet plan for gaining weight created:\nBreakfast: " << breakfast << "\nLunch: " << lunch << "\nDinner: " << dinner << std::endl;
}


