module; // global module fragment(?)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

import CurrentSource;
import Resistor;

export module Circuit;

export class Circuit {
public:
    // Constructor
    // TODO: error checking
    Circuit(std::string f) :netlist_ifs{f} {
        parse_netlist();
    }
    
    void print_circuit() {
    }

private:
    std::ifstream netlist_ifs; // input file stream for netlist file

    /*
    Parse netlist into circuit data structure
    */
    void parse_netlist() {
        for (std::string line; std::getline(netlist_ifs, line); ) {
        }
    }
};
