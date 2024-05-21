#ifndef APPLICATION_PERSON_H
#define APPLICATION_PERSON_H
class Person {
private:
    char* name;
    char gender;
    double height;
    double weight;
    std::string DietType;
public:
    Person( char* name, char gender, double height, double weight, std::string DietType);
    /*
    Person() {
        name = new char[100];
    }
     */
    Person();

    Person(const Person &other);
    void get_user_data();
    ~Person();
    //char analyze_weight();
    char *GetName() const;
    char GetGender() const;
    double GetHeight() const;
    double GetWeight() const;
    std::string GetDietType() const;
    void SetName(char *name);
    void SetGender(char gender);
    void SetHeight(double height);
    void SetWeight(double weight);
    void SetDietType(double DietType);
    void checkWeightStatus();
    bool is_overweight() {
        return (weight > 0.75 * height);
    }

    bool is_underweight() {
        return (weight < 0.5 * height);
    }

    static void trackProgress(const Person &user);
};

/*
class Person {
public:
    char* name;
    char gender;
    int height;
    int weight;

    Person() {
        name = new char[100];
    }


    ~Person() {
        delete[] name;
    }

    void get_data() {
        cout << "Enter Name:";
        cin >> name;
        cout << "Enter Gender (M/F/O):";
        cin >> gender;
        cout << "Enter Height:";
        cin >> height;
        cout << "Enter Weight:";
        cin >> weight;
    }

    bool is_overweight() {
        return (weight > 0.75 * height);
    }

    bool is_underweight() {
        return (weight < 0.5 * height);
    }
*/



#endif
