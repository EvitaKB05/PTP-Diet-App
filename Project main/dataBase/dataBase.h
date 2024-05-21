#include <string>
#include <fstream>
#include <vector>
#include <iostream>

enum class foodCategories {Other, Milks, Meats, Cans, Vegetables, Mushrooms, Fruits, Eggs, Nuts, Fish, FishProducts, FishCans,
    Oils, Bread, Sweets, Juices};

extern std::vector<std::string> foodCategoriesNames;

class DataBase;



class Food{
private:
    char* name;//поменять char* на string!!!!!!!!!!!!!!!!!
    //int diameter -> proteins
    //int life -> fats;
    //int satellite; -> carbs;
    // *** -> energy
    double proteins;
    double fats;
    double carbs;
    double energy;
    foodCategories category;
    friend class DataBase;
    static int count;
    int id;

public:
    // Food() : name(""), proteins(0), fats(0), carbs(0), energy(0), category(foodCategories::Other) {};
    Food(/*std::string*/ char* n, double p, double f, double cars, double e, foodCategories cat) : name(n), proteins(p), fats(f), carbs(cars),
                                                                                                   energy(e), category(cat) {};
    friend std::ostream& operator<<(std::ostream &, const Food &);
    friend std::istream &operator>>(std::istream &, Food &);
    bool operator < (const Food &);
    bool operator == (const Food &);
    void operator = (const Food &);
    std::string getsizeame(){
        return name;
    };
    double get_proteins(){
        return proteins;
    };
    double get_fats(){
        return fats;
    };
    double get_carbs(){
        return carbs;
    };
    double get_energy(){
        return energy;
    };
    void set_name(const char* name){
        delete[] this->name;
        this->name = new char[std::strlen(name) + 1];
        strcpy(this->name, name);
    }


    void set_proteins(double proteins){
        this->proteins=proteins;
    }
    void set_fats(double fats){
        this->fats=fats;
    }
    void set_carbs(double carbs){
        this->carbs=carbs;
    }
    void set_energy(double energy){
        this->energy=energy;
    }

    
};





