#include "Option.h"

namespace carconfig {

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::ostream;
using std::istream;

Option::Option()
    : code(""), label(""), price(0.0f)
{
    cout << "Option::Default constructor" << endl;
}

Option::Option(const string& code, const string& label, float price)
    : code(code), label(label), price(price)
{
    cout << "Option::Init constructor" << endl;
}

Option::Option(const Option& other)
    : code(other.code), label(other.label), price(other.price)
{
    cout << "Option::Copy constructor" << endl;
}

Option::~Option() {
    cout << "Option::Destructor" << endl;
}

string Option::getCode() const { return code; }
string Option::getLabel() const { return label; }
float Option::getPrice() const { return price; }

void Option::setCode(const string& c) { code = c; }
void Option::setLabel(const string& l) { label = l; }
void Option::setPrice(float p) { price = p; }

void Option::display() const {
    cout << "Option::display() ->" << endl;
    cout << " Code : " << code << endl;
    cout << " Label: " << label << endl;
    cout << " Price: " << price << " euros" << endl;
}

    ostream& operator<<(ostream& os, const Option& o) {
        os << "[" << o.code << "] " << o.label << " (" << o.price << " euros)";
        return os;
    }

    istream& operator>>(istream& is, Option& o) {
        string c, l;
        float p;
        cout << " Code : ";
        is >> c;
        is.ignore();
        cout << " Label: ";
        getline(is, l);
        cout << " Price: ";
        is >> p;
        o.code = c; o.label = l; o.price = p;
        return is;
    }

    // pre-decrement: reduce price by 50 and return reference
    Option& Option::operator--() {
        price -= 50.0f;
        return *this;
    }

    // post-decrement: return old value
    Option Option::operator--(int) {
        Option old = *this;
        price -= 50.0f;
        return old;
    }

    } // namespace carconfig
