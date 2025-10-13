#ifndef OPTION_H
#define OPTION_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

namespace carconfig {

class Option {
private:
    string code; // 4-char code
    string label;
    float price;
public:
    Option();
    Option(const string& code, const string& label, float price);
    Option(const Option& other);
    ~Option();

    // getters
    string getCode() const;
    string getLabel() const;
    float getPrice() const;

    // setters
    void setCode(const string& c);
    void setLabel(const string& l);
    void setPrice(float p);

    void display() const;
    // stream operators
    friend ostream& operator<<(ostream& os, const Option& o);
    friend istream& operator>>(istream& is, Option& o);

    // decrement operators: pre and post
    Option& operator--();    // pre
    Option operator--(int);  // post
};

} // namespace carconfig

#endif // OPTION_H
