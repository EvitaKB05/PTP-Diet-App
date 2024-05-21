#include <cstring>
#include <iostream>
#include "Person.h"
Person::Person( char* name, char gender, double height, double weight, std::string DietType) {
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
    this->gender = gender;
    this->height = height;
    this->weight = weight;
    this-> DietType= DietType;
}
Person::Person() {
    this->name=new char[10];
    this->gender='o';
    this-> height=0;
    this->weight=0;
    this-> DietType = '-';
}
Person::Person(const Person &other){
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
    this->gender=other.GetGender();
    this->height=other.GetHeight();
    this->weight=other.GetWeight();
    this->DietType=other.GetDietType();
}
Person::~Person() {
    delete[] name;
}

char* Person::GetName() const {
    return name;
}

char Person::GetGender() const {
    return gender;
}

double Person::GetHeight() const {
    return height;
}

double Person::GetWeight() const {
    return weight;
}
std::string Person::GetDietType() const {
    return DietType;
}
void Person::SetGender(char gender) { //+-
    this->gender=gender;
}

void Person::SetHeight(double height) { //+
    this->height = height;
}

void Person::SetWeight(double weight) { //+
    this->weight = weight;
}
/*
void Person::SetDietType(std::string DietType) {
    this-> DietType= DietType;
}
*/
void Person::get_user_data() { // Перекинуть чтобы в мейне можно было вводить
    //std::cout<<name<<gender<<height<<weight<<std::endl;
    std::cout << "Please, enter your name:";
    std::cin >> name;
    std::cout << "Please, enter your gender(m/f/o): ";
    std::cin >> gender;
    std::cout << "Please, enter your height(in cm): ";
    std::cin >> height;
    std::cout << "Please, enter your weight(in kg): ";
    std::cin >> weight;
    std::cout << "Please, enter type of your target diet(Loss/Healthy/Gain): ";
    std::cin >> DietType;
}
void Person::checkWeightStatus() {
    float weightPercentage = static_cast<float>(weight) / height * 100;
    if (weightPercentage >= 55) {
        std::cout << "Sadly, you are fat :( " << std::endl;
    } else if (weightPercentage <= 45) {
        std::cout << "Sadly, you are skinny :( " << std::endl;
    }
    else if ((weightPercentage > 45) && (weightPercentage < 55)) {
        std::cout << "Wow! You have healthy weight! :) " << std::endl;
    }
}
void Person::trackProgress(const Person &user) {
    std::cout << "Enter diet period (days): ";
    std::string period;
    std::cin >> period;
    std::cout << "Enter diet type (L - Loose, M - Maintenance, G - Gain):: ";
    std::string dietType;
    std::cin >> dietType;
    std::cout << "Enter targer weight (kg): ";
    int targetWeight;
    std::cin >> targetWeight;
    std::cout << "Enter option (1 - Loose, 2 - Maintenance, 3 - Gain):: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            std::cout << "Enter weight lost: ";
            int weightLost;
            std::cin >> weightLost;
            std::cout << "Your start weight: ";
            std::cout << user.weight << std::endl;
            std::cout << "Your current weight: ";
            double currentWeight = user.weight - weightLost;
            std::cout << currentWeight << std::endl;;
            if (currentWeight != targetWeight) {
                std::cout << "Вы не справились со своей целью сбросить вес или перестарались с набором веса."
                          << std::endl;
            } else std::cout << "Вы справились со своей целью cсбросить вес." << std::endl;
        }
            break;
        case 2: {
            std::cout << "Enter weight change: ";
            int weightChange;
            std::cin >> weightChange;
            std::cout << "Your start weight: ";
            std::cout << user.weight << std::endl;
            std::cout << "Your current weight: ";
            double currentWeight2 = user.weight - weightChange;
            std::cout << currentWeight2 << std::endl;
            if (currentWeight2 != targetWeight) {
                std::cout << "Вы не справились со своей целью поддерживать вес." << std::endl;
            } else std::cout << "Вы справились со своей целью поддерживать вес." << std::endl;
        }
            break;

        case 3: {
            std::cout << "Enter weight gain change: ";
            int weightGain;
            std::cin >> weightGain;
            std::cout << "Your start weight: ";
            std::cout << user.weight << std::endl;
            std::cout << "Your current weight: ";
            double currentWeight3 = user.weight + weightGain;
            std::cout << currentWeight3 << std::endl;
            if (currentWeight3 < targetWeight) {
                std::cout << "Вы не справились со своей целью набрать вес." << std::endl;
            } else std::cout << "Вы справились со своей целью набрать вес." << std::endl;
        }
            break;

        default:
            std::cout << "Wrong choice!" << std::endl;
    }


}
