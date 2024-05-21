#ifndef APPLICATION_WEIGHTGAINDIET_H
#define APPLICATION_WEIGHTGAINDIET_H

#include <iostream>
#include "../main.h"
#include "../Diet/Diet.h"
class WeightGainDiet : public Diet {
public:
    void get_diet_plan() override {
        std::cout << " Diet for Weight Gain" << std::endl;
        get_meal_data("Breakfast");
        get_meal_data("Lunch");
        get_meal_data("Dinner");
    }

    //static void createDietForGainWeight();

private:
    void get_meal_data(const char* meal_name) {
        std::cout << meal_name << ":" << std::endl;
        // ... получение информации о продуктах
    }

};

#endif //APPLICATION_WEIGHTGAINDIET_H

