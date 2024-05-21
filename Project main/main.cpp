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
int main() {
    //DataBase data;
    Person user;
    user.get_user_data();
    //Person person("Alice", 'f', 165, 55); // Создание объекта класса Person с инициализацией данных
    user.checkWeightStatus(); // Вызов метода checkWeightStatus() для объекта person
    //user.get_user_data();
     /* if (user.is_overweight()) {
         cout << "You are fat :( " << endl;
     }
     else if (user.is_underweight()) {
         cout << "You are skinny :( " << endl;
     }
 */
    cout << "Choose an option:" << endl;
    cout << "1. Make a Diet" << endl;
    cout << "2. Count Calories" << endl;
    cout << "3. Work with Data Base" << endl;
    cout << "4. Show my progress" << endl;
    cout << "5. Exit" << endl;

    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            Diet* diet;
            char diet_choice;

            cout << " Choose the Diet Type( G - Gaining, L-Losing):";
            cin >> diet_choice;

            if (diet_choice == 'G') {
                createDietForUnderweight();
            }
            else if (diet_choice == 'L') {
                createDietForOverweight();
            }
            else {
                cout << "Wrong choice!" << endl;
                return 1;
            }

            diet->get_diet_plan();
            //WeightGainDiet::createDietForGainWeight();
            delete diet;
            break;
        case 2:
            cout << "Choose an option:" << endl;
            cout << "1. Count calories by yourself" << endl;
            cout << "2. Count Calories with DataBase" << endl;
            int option;
            cin >> option;

            if (option == 1) {
                CalorieCounter counter;
                int total_calories = counter.count_calories_by_yourself();
                cout << " Overall Calories summary:" << total_calories << endl;
            }
            break;
        case 3:
            interactive();
            break;
        case 4:
            Person::trackProgress(user);
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong choice!" << endl;
    }


    return 0;
}

