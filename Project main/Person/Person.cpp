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

