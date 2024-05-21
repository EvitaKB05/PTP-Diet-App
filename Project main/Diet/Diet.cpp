#include "Diet.h"
/*
#include <iostream>
using namespace std;
void createDiet() {
    // Выбор периода диеты
    int dietPeriod;
    cout << "Какой период диеты вы хотите составить? (1 - неделя, 2 - месяц): ";
    cin >> dietPeriod;

    // Выбор типа диеты
    int dietType;
    cout << "Какой тип диеты вы хотите составить? (1 - для недостаточного веса, 2 - для избыточного веса, 3 - для поддержания здорового веса): ";
    cin >> dietType;

    // Получение данных от пользователя
    double targetWeight;
    double weightChange;
    cout << "Введите ваш целевой вес: ";
    cin >> targetWeight;
    if (dietType == 1) {
        cout << "Введите, сколько вы хотите набрать (кг): ";
    }
    else if (dietType == 2) {
        cout << "Введите, сколько вы хотите сбросить (кг): ";
    }
    cin >> weightChange;

    // Создание меню диеты
    createMealPlan(breakfast, "Завтрак");
    createMealPlan(lunch, "Обед");
    createMealPlan(dinner, "Ужин");

    // Вывод плана диеты
    cout << "\nПлан диеты:\n";
    cout << "Завтрак:\n";
    printMealPlan(breakfast);
    cout << "Обед:\n";
    printMealPlan(lunch);
    cout << "Ужин:\n";
    printMealPlan(dinner);
}

private:
// Создание плана для одного приема пищи
void createMealPlan(vector<Product>& meal, const string& mealName) {
    // Выбор способа составления плана
    int planMethod;
    cout << "Как вы хотите составить " << mealName << "? (1 - самостоятельно, 2 - с помощью базы данных): ";
    cin >> planMethod;

    if (planMethod == 1) {
        // Составление плана самостоятельно
        createMealPlanManually(meal, mealName);
    }
    else if (planMethod == 2) {
        // Составление плана с помощью базы данных
        createMealPlanUsingDatabase(meal, mealName);
    }
    else {
        cerr << "Неверный выбор.\n";
    }
}

// Составление плана самостоятельно
void createMealPlanManually(vector<Product>& meal, const string& mealName) {
    string productName;
    double quantity;
    char continueChoice;

    do {
        cout << "Введите название продукта для " << mealName << ": ";
        cin >> productName;
        cout << "Введите количество продукта (г): ";
        cin >> quantity;
        Product product = productDatabase.getProductByName(productName);
        product.protein *= quantity / 100;
        product.fat *= quantity / 100;
        product.carbohydrates *= quantity / 100;
        product.energy *= quantity / 100;
        meal.push_back(product);

        cout << "Добавить ещё продукт? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y');
}

// Составление плана с помощью базы данных
void createMealPlanUsingDatabase(vector<Product>& meal, const string& mealName) {
    int databaseChoice;
    cout << "Как вы хотите использовать базу данных? (1 - вывести всю базу, 2 - вывести по категориям): ";
    cin >> databaseChoice;

    if (databaseChoice == 1) {
        // Вывод всей базы данных
        productDatabase.printDatabase();
    }
    else if (databaseChoice == 2) {
        // Вывод базы данных по категориям
        vector<string> categories;
        int numCategories;
        cout << "Сколько категорий вы хотите выбрать? ";
        cin >> numCategories;
        for (int i = 0; i < numCategories; ++i) {
            string category;
            cout << "Введите категорию " << i + 1 << ": ";
            cin >> category;
            categories.push_back(category);
        }
        productDatabase.printDatabaseByCategory(categories);
    }
    else {
        cerr << "Неверный выбор.\n";
        return;
    }

    string productName;
    double quantity;
    char continueChoice;

    do {
        cout << "Введите название продукта для " << mealName << ": ";
        cin >> productName;
        cout << "Введите количество продукта (г): ";
        cin >> quantity;
        Product product = productDatabase.getProductByName(productName);
        product.protein *= quantity / 100;
        product.fat *= quantity / 100;
        product.carbohydrates *= quantity / 100;
        product.energy *= quantity / 100;
        meal.push_back(product);

        cout << "Добавить ещё продукт? (y/n): ";
        cin >> continueChoice;
    } while (continueChoice == 'y');
}

// Вывод плана для одного приема пищи
void printMealPlan(const vector<Product>& meal) {
    cout << "Название продукта | Белки (г) | Жиры (г) | Углеводы (г) | Калории (ккал)\n";
    for (const auto& product : meal) {
        cout << product.name << " | " << fixed << setprecision(1) << product.protein << " | " << fixed << setprecision(1) << product.fat << " | " << fixed << setprecision(1) << product.carbohydrates << " | " << fixed << setprecision(0) << product.energy << endl;
    }
    cout << "------------------------------------------------------------\n";
}
*/
