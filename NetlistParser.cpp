module; // global module fragment(?)

#include <iostream>
#include <fstream>
#include <string>

export module NetlistParser;

/*
Parse a given netlist text file
*/
export class NetlistParser {
public:
    std::ifstream netlist_ifs;

    // Constructor
    // TODO: error checking
    NetlistParser(std::string f) :netlist_ifs{f} {}

    void print_branches() {
        for (std::string line; std::getline(netlist_ifs, line);) {
            std::cout << line << '\n';
        }
    }
};
