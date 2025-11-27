export module CurrentSource;

export class CurrentSource {
public:
    double val = 1.0; // current, in amps

    /* 
    Nodes (wires) that CurrentSource is attached to.
    -1 means unconnected / floating
    */
    int from = -1;
    int to = -1;

    CurrentSource(double i, int f, int t) :val{i}, from{f}, to{t} {}

    double value() const {return val; }
};
