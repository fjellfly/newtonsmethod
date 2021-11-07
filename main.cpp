#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <functional>
#include <iterator>

#include "root.h"

using namespace std;

/**
 * Create string representation of a vector
 *
 * @param v Vector
 * @return String
 */
string vectorToString(vector<double> v) {
    ostringstream oss;
    copy(v.begin(), v.end() - 1, ostream_iterator<double>(oss, ", "));
    oss << v.back();
    return oss.str();
}

int main() {
    // Function under investigation
    function<vector<double> (vector<double>)> F = [](vector<double> x) {
        vector<double> vec(x.size());
        vec.at(0) = x.at(0) / x.at(1) + x.at(2) / x.at(0);
        vec.at(1) = 0.5 * pow(x.at(1), 3) - 250 * x.at(1) * x.at(2) - 75000 * pow(x.at(2), 2);
        vec.at(2) = exp(-x.at(2)) + x.at(2) * exp(1);

        return vec;
    };

    vector<double> initialGuess({10, 100, 0}); // Initial guess
    const double h = pow(10, -6); // Step size for calculation of the Jacobian using finite differences
    double epsilon = pow(10, -6); // Tolerance level. Terminate iteration if norm of solution is smaller.
    int maxIterations = 100; // Maximum number of iterations

    // Calculate root of function using Newton's Method
    FindRootResult result = findRoot(initialGuess, F, maxIterations, epsilon, h);

    cout << "F({" << vectorToString(result.x) << "}) = {"<< vectorToString(F(result.x)) << "}" << endl;
    cout << "Solution found after " << result.iteration << " iterations" << endl;

    return 0;
}