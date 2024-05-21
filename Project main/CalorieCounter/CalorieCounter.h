#ifndef APPLICATION_CALORIECOUNTER_H
#define APPLICATION_CALORIECOUNTER_H

#include <iostream>
/*
class CalorieCounter {
public:
    //void count_calories();
    int count_calories() {
        int total_calories = 0;
        // ... получение информации о продуктах и подсчет калорий
        return total_calories;
    }
};
 */ //Non manual realisation
class CalorieCounter {
public:
    int count_calories_by_yourself() {
        // ... получение информации о продуктах и подсчет калорий
        int totalCalories = 0;
        int calories;
        char food[50];

        do {
            std::cout << "Enter food item (type 'f' to finish): ";
            std::cin >> food;
            if (strcmp(food, "f") != 0) {
                std::cout << "Enter calories for " << food << ": ";
                std::cin >> calories;
                totalCalories += calories;
            }
        } while (strcmp(food, "f") != 0);

        std::cout << "Total calories consumed: " << totalCalories << " kcal" << std::endl;

        return totalCalories;
    }
    int count_calories_with_DataBase() {
        int total_calories = 0;
        // ... получение информации о продуктах и подсчет калорий


        return total_calories;
    }
};

#endif //APPLICATION_CALORIECOUNTER_H
