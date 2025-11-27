module; // global module fragment(?)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

import CurrentSource;
import Resistor;

export module Netlist;

export class Netlist {
public:
    // Constructor
    // TODO: error checking
    Netlist(std::string f) :netlist_ifs{f} {
        parse_netlist();
    }
    
    // The components between nodes are also called branches
    void print_branches() {
        std::cout << "Resistors:\n";
        for (Resistor r : resistors) {
            std::cout << r << '\n';
        }

        std::cout << "Current Sources:\n";
        for (CurrentSource c : current_sources) {
            std::cout << c.value() << '\n';
        }
    }

private:
    std::ifstream netlist_ifs; // input file stream for netlist file
    std::vector<Resistor> resistors;
    std::vector<CurrentSource> current_sources;

    /*
    Parse netlist into vectors of circuit elements
    */
    void parse_netlist() {
        for (std::string line; std::getline(netlist_ifs, line); ) {
            // TODO: make better. split by whitespace
            if (line[0] == 'R') {
                resistors.push_back(Resistor(1, line[3] - '0', line[5] - '0'));
            } else if (line[0] == 'I') {
                current_sources.push_back(CurrentSource(1, line[3], line[5]));
            }
        }
    }
};
