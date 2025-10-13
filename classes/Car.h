#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "Model.h"
#include "Option.h"

using std::string;
using std::ostream;

namespace carconfig {

class Car {
private:
    string name;
    Model model;
    Option* options[5];
    void initOptions();
public:
    Car();
    Car(const string& name, const Model& model);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    // getters/setters
    string getName() const;
    Model& getModel();
    const Model& getModel() const;
    void setName(const string& n);
    void setModel(const Model& m);

    // options management
    void addOption(const Option& option);
    void removeOption(const string& code);

    float getPrice() const;
    void display() const;

    // operators
    Car operator+(const Option& option) const; // return new Car with option added
    Car operator-(const Option& option) const; // return new Car with option removed by code
    Car operator-(const string& code) const;

    bool operator<(const Car& other) const;
    bool operator>(const Car& other) const;
    bool operator==(const Car& other) const;

    Option* operator[](int index);
    const Option* operator[](int index) const;

    friend ostream& operator<<(ostream& os, const Car& c);
};

// free operator to allow Option + Car
Car operator+(const Option& opt, const Car& car);

} // namespace carconfig

#endif // CAR_H
