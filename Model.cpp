#include "Model.h"
#include <cstring>

void Model::copyName(const char* src) {
    if (src == nullptr) {
        name = nullptr;
        return;
    }
    size_t len = std::strlen(src) + 1;
    name = new char[len];
    std::strcpy(name, src);
}

Model::Model()
    : name(nullptr), power(0), engine(Petrol), basePrice(0.0f)
{
    std::cout << "Model::Default constructor" << std::endl;
}

Model::Model(const char* name, int power, Engine engine, float basePrice)
    : name(nullptr), power(power), engine(engine), basePrice(basePrice)
{
    std::cout << "Model::Init constructor" << std::endl;
    copyName(name);
}

Model::Model(const Model& other)
    : name(nullptr), power(other.power), engine(other.engine), basePrice(other.basePrice)
{
    std::cout << "Model::Copy constructor" << std::endl;
    copyName(other.name);
}

Model::~Model() {
    std::cout << "Model::Destructor" << std::endl;
    delete [] name;
}

const char* Model::getName() const { return name; }
int Model::getPower() const { return power; }
Engine Model::getEngine() const { return engine; }
float Model::getBasePrice() const { return basePrice; }

void Model::setName(const char* newName) {
    delete [] name;
    copyName(newName);
}
void Model::setPower(int p) { power = p; }
void Model::setEngine(Engine e) { engine = e; }
void Model::setBasePrice(float price) { basePrice = price; }

void Model::display() const {
    std::cout << "Model::display() ->" << std::endl;
    std::cout << " Name        : " << (name ? name : "(null)") << std::endl;
    std::cout << " Power       : " << power << " Ch" << std::endl;
    std::cout << " Engine      : " << engine << std::endl;
    std::cout << " Base price  : " << basePrice << " euros" << std::endl;
}
