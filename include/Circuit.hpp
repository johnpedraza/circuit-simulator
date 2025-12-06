#pragma once
#include <vector>

struct Component {
    int id;
    std::string name;
    std::vector<int> terminals;
    double value;
};

class Circuit {
public:
    Circuit(std::string);
    void print_circuit();
private:
    void parse_netlist(std::string);
    std::vector<std::vector<int>> adjacency_list;
    std::vector<Component> components;
};
