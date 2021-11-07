#include <algorithm>
#include <functional>
#include <stdexcept>
#include <math.h>

#include "jacobi.h"
#include "solve.h"
#include "root.h"

using namespace std;

/**
 * Container for results of a iteration process
 *
 * @param x Solution vector
 * @param iteration Number of iterations carried out
 */
FindRootResult::FindRootResult(vector<double> x, int iteration) {
    this->x = x;
    this->iteration = iteration;
}

/**
 * Calculate the euclidean norm of a vector
 *
 * @param v Vector under investigation
 * @return Euclidean norm
 */
double getNorm(vector<double> v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += pow(v.at(i),2);
    }
    return sqrt(sum);
}

/**
 * Calculate root of a function using newton's method
 *
 * @param initialGuess Initial guess
 * @param F Function under investigation
 * @param maxIterations Maximum number of iterations
 * @param epsilon Tolerance level (terminate iteration if result is smaller)
 * @param h Step size for the calculation of the Jacobian using finite differences
 * @return Root of the given function
 */
FindRootResult findRoot(vector<double> initialGuess, function<vector<double> (vector<double>)> F, int maxIterations, double epsilon, double h) {
    
    int dimensions = initialGuess.size();

    vector<double> x(dimensions);
    copy(initialGuess.begin(), initialGuess.end(), x.begin());

    for (int iteration = 0; iteration < maxIterations; iteration++) {
        vector<vector<double>> jacobian = getJacobian(x, F, h);
        vector<double> deltaX;
        try {
            deltaX = solve(jacobian, F(x));
        }
        catch(invalid_argument &e) {
            throw invalid_argument("Upper triangle Jacobians are supported only");
        }
        transform(x.begin(), x.end(), deltaX.begin(), x.begin(), minus<double>());

        // Check whether the solution is good enough
        double norm = getNorm(F(x));
        if (norm < epsilon) {
            FindRootResult findRootResult(x, iteration);
            return findRootResult;
        }
    }

    FindRootResult findRootResult(x, maxIterations);
    return findRootResult;
}
