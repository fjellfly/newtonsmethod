#include "solve.h"

using namespace std;

vector<double> solve(vector<vector<double>> matrix, vector<double> targetValue) {
    vector<double> solution(targetValue.size());
    
    // Assume dimension to be 3    
    solution.at(2) = targetValue.at(2) / matrix.at(2).at(2);
    solution.at(1) = (targetValue.at(1) - matrix.at(1).at(2) * solution.at(2)) / matrix.at(1).at(1);
    solution.at(0) = (targetValue.at(0) - matrix.at(0).at(1) * solution.at(1) - matrix.at(0).at(2) * solution.at(2)) / matrix.at(0).at(0);
            
    return solution;
}

