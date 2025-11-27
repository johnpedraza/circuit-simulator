module;

#include <ostream>

export module Resistor;

export class Resistor {
public:
    double val = 1.0; // resistance, in ohms

    /* 
    Nodes (wires) that Resistor is attached to.
    -1 means unconnected / floating
    */
    int from = -1;
    int to = -1;

    Resistor(double i, int f, int t) :val{i}, from{f}, to{t} {}

    double value() const {return val; }

    friend std::ostream& operator<<(std::ostream& os, const Resistor& obj);
};

std::ostream& operator<<(std::ostream& os, const Resistor& obj) {
    os << "Resistor(val: " << obj.val << ", from: " << obj.from << ", to: " << obj.to << ")";
    return os; // Return the ostream reference for chaining
}
