#include <iostream>
import CurrentSource;
import Netlist;

int main() {
    Netlist p = Netlist("netlist.txt");
    p.print_branches();
}
