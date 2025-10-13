#ifndef MODEL_H
#define MODEL_H

#include <iostream>

using std::ostream;
using std::istream;

namespace carconfig {

enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model {
private:
    char* name;
    int power;
    Engine engine;
    float basePrice;
    void copyName(const char* src);
public:
    // constructors and destructor
    Model();
    Model(const char* name, int power, Engine engine, float basePrice);
    Model(const Model& other);
    Model& operator=(const Model& other);
    ~Model();

    // getters
    const char* getName() const;
    int getPower() const;
    Engine getEngine() const;
    float getBasePrice() const;

    // setters
    void setName(const char* newName);
    void setPower(int p);
    void setEngine(Engine e);
    void setBasePrice(float price);

    // display
    void display() const;
    // stream operators
    friend ostream& operator<<(ostream& os, const Model& m);
    friend istream& operator>>(istream& is, Model& m);

};

} // namespace carconfig

#endif // MODEL_H
