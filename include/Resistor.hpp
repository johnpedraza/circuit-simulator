#pragma once

class Resistor {
public:
    Resistor(double, int, int);
    double value() const;
    friend std::ostream& operator<<(std::ostream& os, const Resistor& obj);
private:
    double val;
    int from;
    int to;
};
