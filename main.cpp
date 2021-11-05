#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <functional>
#include <iterator>

#include "root.h"

using namespace std;

string vectorToString(vector<double> v) {
    ostringstream oss;
    copy(v.begin(), v.end() - 1, ostream_iterator<double>(oss, ", "));
    oss << v.back();
    return oss.str();
}

int main() {
    function<vector<double> (vector<double>)> F = [](vector<double> x) {
        vector<double> vec(x.size());
        vec.at(0) = x.at(0) / x.at(1) + x.at(2) / x.at(0);
        vec.at(1) = 0.5 * pow(x.at(1), 3) - 250 * x.at(1) * x.at(2) - 75000 * pow(x.at(2), 2);
        vec.at(2) = exp(-x.at(2)) + x.at(2) * exp(1);

        return vec;
    };

    vector<double> initialGuess({10, 100, 0});
    const double h = pow(10, -6);
    double epsilon = pow(10, -6);
    int maxIterations = 100;

    vector<double> result = findRoot(initialGuess, F, maxIterations, epsilon, h);
    
    cout << "(" << vectorToString(result) << ")" << endl;

    return 0;
}