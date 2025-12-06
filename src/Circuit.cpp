#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
    std::cout << "Components:\n";
    for (Component c : components) {
        std::cout << c.name << '\n';
    }

    std::cout << "Adjacency list:\n";
    for (std::vector<int> v : adjacency_list) {
        std::cout << "from " << v[0] << " to " << v[1] << '\n';
    }
}

/*
Parse netlist into circuit data structure
*/
void Circuit::parse_netlist(std::string netlist_filepath) {
    // input file stream for netlist (initializing with '=' won't work)
    std::ifstream netlist_ifs {netlist_filepath};

    int idCounter = 0;
    for (std::string line; std::getline(netlist_ifs, line); ) {
        if (line[0] == '*') {
            continue;
        }
        std::stringstream ss(line);

        std::string word;

        std::string newName;
        std::vector<int> newTerminals;
        double newValue;
        int newId;

        ss >> word;
        newName = word;
        ss >> word;
        newTerminals.push_back(std::stoi(word));
        ss >> word;
        newTerminals.push_back(std::stoi(word));
        ss >> word;
        newValue = std::stod(word);
        newId = idCounter++;
        Component newComponent(newId, newName, newTerminals, newValue);
        components.push_back(newComponent);
        adjacency_list.push_back(newTerminals);

        /*
        while (ss >> word) {
            std::cout << word;
        }
        */
    }
}
