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
    Circuit(std::string netlist_filepath) {
        parse_netlist(netlist_filepath);
    }
    
    void print_circuit() {
    }

private:
    /*
    Parse netlist into circuit data structure
    */
    void parse_netlist(std::string netlist_filepath) {
        // input file stream for netlist (initializing with '=' won't work)
        std::ifstream netlist_ifs {netlist_filepath};

        for (std::string line; std::getline(netlist_ifs, line); ) {
            std::cout << line << '\n';
        }
    }
};
