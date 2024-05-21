#ifndef APPLICATION_WEIGHTGAINDIET_H
#define APPLICATION_WEIGHTGAINDIET_H

#include <iostream>
#include "../main.h"
#include "../Diet/Diet.h"
class WeightGainDiet : public Diet {
public:
    int target_weight_gain;

    void get_target_weight_gain();

    //void createDietForGainWeight();
    void create_diet_plan();
};
