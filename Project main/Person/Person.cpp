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

