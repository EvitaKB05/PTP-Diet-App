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

