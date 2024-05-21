#include "dataBase.h"

std::vector<std::string> foodCategoriesNames = { "Other", "Milks", "Meats", "Cans", "Vegetables", "Mushrooms", "Fruits",
                                                 "Eggs", "Nuts", "Fish", "FishProducts", "FishCans",	"Oils", "Bread", "Sweets", "Juices" };

DataBase::DataBase()
{
    catalog.clear();
    getDataBase();
    printDataBase();
}

void DataBase::printDataBase()
{
    for (auto& product : catalog)
        std::cout << product.name << ' ' << product.proteins << ' ' << product.fats << ' ' << product.carbs << ' ' <<
                  product.energy << std::endl;
}

void DataBase::getDataBase()
{
    std::ifstream dataBase;
    //dataBase.open("../../../microDataBase.txt", std::ios::in);
    dataBase.open("BD_Diet.txt", std::ios::in);
    if (!dataBase.is_open())
        std::cout << "can't find file" << std::endl;
    std::string line, name, proteins, fats, carbs, energy;
    int separatorsIndex[4] = {0, 0, 0, 0}, j;
    foodCategories category = foodCategories::Other;
    while (std::getline(dataBase, line)) {
        const auto pos = std::find(foodCategoriesNames.begin(), foodCategoriesNames.end(), line);
        if (pos != foodCategoriesNames.end()) {
            category = static_cast<foodCategories>(pos - foodCategoriesNames.begin());
            continue;
        }
        j = 3;
        for(int i = line.length() - 1; i >= 0 && j >= 0; i--)
            if (line[i] == ' ') {
                separatorsIndex[j] = i;
                j--;
            }
        name = line.substr(0, separatorsIndex[0]);
        proteins = line.substr(separatorsIndex[0] + 1, separatorsIndex[1] - separatorsIndex[0]);
        fats = line.substr(separatorsIndex[1] + 1, separatorsIndex[2] - separatorsIndex[1]);
        carbs = line.substr(separatorsIndex[2] + 1, separatorsIndex[3] - separatorsIndex[2]);
        energy = line.substr(separatorsIndex[3] + 1, line.length() - separatorsIndex[3]);
        // Food  tempFood(name, std::stod(proteins), std::stod(fats), std::stod(carbs), std::stod(energy), category);
        // catalog.push_back(tempFood);
    }
}
Food::Food()
{
    count++;
    id = count;
    name = new char[10];
    name[0] = '\0';
    proteins = 0;
    fats = 0;
    carbs = 0;
    energy=0;
}
Food::Food(const Food& arr){
    name = new char [strlen(arr.name) + 1];
    strncpy(name, arr.name, strlen(arr.name) + 1);
    proteins = arr.proteins;
    fats = arr.fats;
    carbs = arr.carbs;
    energy = arr.energy;
}
Food::Food(const char* name, double proteins, double fats, double carbs, double energy){
    this->name = new char [strlen(name)+1];
    strcpy(this->name, name);
    this->proteins=proteins;
    this->fats=fats;
    this->carbs=carbs;
    this->energy=energy;
}
