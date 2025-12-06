#include <iostream>
#include "Circuit.hpp"
#include <emscripten.h>

Circuit circuit = Circuit("netlist.txt");

int main() {
    std::cout << "Called from main()\n";
    return 0;
}

#define EXTERN extern "C"

EXTERN EMSCRIPTEN_KEEPALIVE
void printCircuit() {
    circuit.print_circuit();
}
