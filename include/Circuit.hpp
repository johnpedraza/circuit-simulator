#pragma once

class Circuit {
public:
    Circuit(std::string);
    void print_circuit();
private:
    void parse_netlist(std::string);
};
