#include <algorithm>
#include <functional>
#include <stdexcept>
#include <math.h>

#include "jacobi.h"
#include "solve.h"
#include "root.h"

using namespace std;

FindRootResult::FindRootResult(vector<double> x, int iteration) {
    this->x = x;
    this->iteration = iteration;
}

double getNorm(vector<double> v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += pow(v.at(i),2);
    }
    return sqrt(sum);
}

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
            throw invalid_argument("Upper triangle jacobians are supported only");
        }
        transform(x.begin(), x.end(), deltaX.begin(), x.begin(), minus<double>());

        double norm = getNorm(F(x));
        if (norm < epsilon) {
            FindRootResult findRootResult(x, iteration);
            return findRootResult;
        }
    }

    FindRootResult findRootResult(x, maxIterations);
    return findRootResult;
}
