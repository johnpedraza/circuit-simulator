#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Sparse>

#include "Circuit.hpp"
#include "Resistor.hpp"

// Constructor
Circuit::Circuit(std::string netlist_filepath) {
    parse_netlist(netlist_filepath);
}

/* 
Print the circuit!
*/
void Circuit::print_circuit() {
    Resistor dummy_r = Resistor(100, 101, 102);
    std::cout << dummy_r << '\n';
}

/*
Parse netlist into circuit data structure
*/
void Circuit::parse_netlist(std::string netlist_filepath) {
    // input file stream for netlist (initializing with '=' won't work)
    std::ifstream netlist_ifs {netlist_filepath};

    for (std::string line; std::getline(netlist_ifs, line); ) {
        std::cout << line << '\n';
    }
}
