#include <iostream>
#include "Circuit.hpp"

int main() {
    Circuit n = Circuit("netlist.txt");
    n.print_circuit();
}
