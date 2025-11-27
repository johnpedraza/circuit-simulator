#include <iostream>
import Circuit;

int main() {
    Circuit n = Circuit("netlist.txt");
    n.print_circuit();
}
