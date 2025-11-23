export module CurrentSource;

export class CurrentSource {
public:
    double val; // current, in amps
    int from;   // "from" node
    int to;     // "to" node

    CurrentSource(double i, int f, int t) :val{i}, from{f}, to{t} {}

    double value() const {return val; }
};
