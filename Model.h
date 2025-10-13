#ifndef MODEL_H
#define MODEL_H

#include <iostream>

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
};

#endif // MODEL_H
