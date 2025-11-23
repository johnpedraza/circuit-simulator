#include <iostream>
import CurrentSource;
import NetlistParser;

int main() {
    NetlistParser p = NetlistParser("netlist.txt");
    p.print_branches();

    CurrentSource c = CurrentSource(3.5, 1, 2);
    std::cout << c.value() << " amps\n";
}
