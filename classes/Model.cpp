#include "Model.h"
#include <iostream>
#include <cstring>

using namespace carconfig;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::ostream;
using std::istream;

void Model::copyName(const char *src)
{
    if (src == nullptr) {
        name = nullptr;
        return;
    }
    size_t len = strlen(src) + 1;
    name = new char[len];
    strcpy(name, src);
}

Model::Model()
    : name(nullptr), power(0), engine(Petrol), basePrice(0.0f)
{
    cout << "Model::Default constructor" << endl;
}

Model::Model(const char *name, int power, Engine engine, float basePrice)
    : name(nullptr), power(power), engine(engine), basePrice(basePrice)
{
    cout << "Model::Init constructor" << endl;
    copyName(name);
}

Model::Model(const Model &other)
    : name(nullptr), power(other.power), engine(other.engine), basePrice(other.basePrice)
{
    cout << "Model::Copy constructor" << endl;
    copyName(other.name);
}

Model &Model::operator=(const Model &other)
{
    if (this == &other)
        return *this;
    power = other.power;
    engine = other.engine;
    basePrice = other.basePrice;
    delete[] name;
    name = nullptr;
    copyName(other.name);
    return *this;
}

Model::~Model()
{
    cout << "Model::Destructor" << endl;
    delete[] name;
}

const char *Model::getName() const { return name; }
int Model::getPower() const { return power; }
Engine Model::getEngine() const { return engine; }
float Model::getBasePrice() const { return basePrice; }

void Model::setName(const char *newName)
{
    delete[] name;
    copyName(newName);
}
void Model::setPower(int p) { power = p; }
void Model::setEngine(Engine e) { engine = e; }
void Model::setBasePrice(float price) { basePrice = price; }

void Model::display() const
{
    cout << "Model::display() ->" << endl;
    const char* displayName;
    if (name != nullptr) {
        displayName = name;
    } else {
        displayName = "(null)";
    }
    cout << " Name        : " << displayName << endl;
    cout << " Power       : " << power << " Ch" << endl;
    cout << " Engine      : " << engine << endl;
    cout << " Base price  : " << basePrice << " euros" << endl;
}

namespace carconfig {

ostream& operator<<(ostream& os, const Model& m) {
    const char* nm;
    if (m.name != nullptr) {
        nm = m.name;
    } else {
        nm = "(null)";
    }
    os << "[" << nm << "] " << m.power << "ch " << m.basePrice << "euros";
    return os;
}

istream& operator>>(istream& is, Model& m) {
    string sname;
    int p;
    int e;
    float price;
    cout << " Name: ";
    getline(is, sname);
    cout << " Power: ";
    is >> p;
    cout << " Engine (0=Petrol,1=Diesel,2=Electric,3=Hybrid): ";
    is >> e;
    cout << " Base price: ";
    is >> price;
    // assign
    m.setName(sname.c_str());
    m.setPower(p);
    m.setEngine(static_cast<Engine>(e));
    m.setBasePrice(price);
    is.ignore();
    return is;
}

} // namespace carconfig
