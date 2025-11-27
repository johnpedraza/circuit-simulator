#include <ostream>
#include "Resistor.hpp"

Resistor::Resistor(double i, int f, int t) :val{i}, from{f}, to{t} {}

double Resistor::value() const {
    return val;
}

std::ostream& operator<<(std::ostream& os, const Resistor& obj) {
    os << "Resistor(val: " << obj.val << ", from: " << obj.from << ", to: " << obj.to << ")";
    return os; // Return the ostream reference for chaining
}
