#ifndef APPLICATION_WEIGHTLOSSDIET_H
#define APPLICATION_WEIGHTLOSSDIET_H

#include <iostream>
#include "../main.h"
#include "../Diet/Diet.h"
/*
class WeightLossDiet : public Diet {
private:
    int target_weight_loss;
public:
    void get_target_weight_loss();
    void create_diet_plan();
};
*/
class WeightLossDiet : public Diet {
public:
    void get_diet_plan(){
        std::cout << " Diet for Weight Loss" << std::endl;
        get_meal_data("Breakfast");
        get_meal_data("Lunch");
        get_meal_data("Dinner");
    }


#endif //APPLICATION_WEIGHTLOSSDIET_H

