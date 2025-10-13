#include "Car.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using std::cout;
using std::endl;

using namespace carconfig;


void Car::initOptions() {
    for (int i = 0; i < 5; ++i) options[i] = nullptr;
}

Car::Car()
    : name(""), model(), options{nullptr,nullptr,nullptr,nullptr,nullptr}
{
    cout << "Car::Default constructor" << endl;
}

Car::Car(const string& name, const Model& model)
    : name(name), model(model)
{
    initOptions();
    cout << "Car::Init constructor" << endl;
}

Car::Car(const Car& other)
    : name(other.name), model(other.model)
{
    cout << "Car::Copy constructor" << endl;
    for (int i = 0; i < 5; ++i) {
        if (other.options[i]) {
            options[i] = new Option(*other.options[i]);
        } else {
            options[i] = nullptr;
        }
    }
}

Car& Car::operator=(const Car& other) {
    if (this == &other) {
        return *this;
    }
    name = other.name;
    model = other.model;
    // delete existing options
    for (int i = 0; i < 5; ++i) {
        delete options[i];
        options[i] = nullptr;
    }
    for (int i = 0; i < 5; ++i) {
        if (other.options[i]) {
            options[i] = new Option(*other.options[i]);
        } else {
            options[i] = nullptr;
        }
    }
    return *this;
}

Car::~Car() {
    cout << "Car::Destructor" << endl;
    for (int i = 0; i < 5; ++i) {
        delete options[i];
        options[i] = nullptr;
    }
}

string Car::getName() const { return name; }
Model& Car::getModel() { return model; }
const Model& Car::getModel() const { return model; }

void Car::setName(const string& n) { name = n; }
void Car::setModel(const Model& m) { model = m; }

void Car::addOption(const Option& option) {
    for (int i = 0; i < 5; ++i) {
        if (options[i] == nullptr) {
            options[i] = new Option(option);
            return;
        }
    }
    cout << "No space to add option" << endl;
}

Car Car::operator+(const Option& option) const {
    Car result(*this);
    result.addOption(option);
    return result;
}

Car Car::operator-(const Option& option) const {
    Car result(*this);
    result.removeOption(option.getCode());
    return result;
}

Car Car::operator-(const string& code) const {
    Car result(*this);
    result.removeOption(code);
    return result;
}

bool Car::operator<(const Car& other) const { return getPrice() < other.getPrice(); }
bool Car::operator>(const Car& other) const { return getPrice() > other.getPrice(); }
bool Car::operator==(const Car& other) const { return getPrice() == other.getPrice(); }

Option* Car::operator[](int index) {
    if (index < 0 || index >= 5) {
        return nullptr;
    }
    return options[index];
}

const Option* Car::operator[](int index) const {
    if (index < 0 || index >= 5) {
        return nullptr;
    }
    return options[index];
}

namespace carconfig {

using std::string;
using std::cout;
using std::endl;
using std::ostream;

ostream& operator<<(ostream& os, const Car& c) {
    os << "Car: " << c.name << "\n";
    os << c.model << "\n";
    os << "Options:";
    for (int i = 0; i < 5; ++i) {
        if (c.options[i]) {
            os << "\n - " << *c.options[i];
        }
    }
    os << "\nTotal price: " << c.getPrice() << " euros";
    return os;
}

// allow Option + Car
Car operator+(const Option& opt, const Car& car) {
    Car result(car);
    result.addOption(opt);
    return result;
}

} // namespace carconfig

void Car::removeOption(const string& code) {
    for (int i = 0; i < 5; ++i) {
        if (options[i] && options[i]->getCode() == code) {
            delete options[i];
            options[i] = nullptr;
            return;
        }
    }
}

float Car::getPrice() const {
    float total = model.getBasePrice();
    for (int i = 0; i < 5; ++i) {
        if (options[i]) {
            total += options[i]->getPrice();
        }
    }
    return total;
}

void Car::display() const {
    cout << "Car::display() ->" << endl;
    cout << " Name  : " << name << endl;
    cout << " Model : " << endl;
    model.display();
    cout << " Options:" << endl;
    for (int i = 0; i < 5; ++i) {
        if (options[i]) {
            cout << "  - ";
            options[i]->display();
        }
    }
    cout << " Total price : " << getPrice() << " euros" << endl;
}
