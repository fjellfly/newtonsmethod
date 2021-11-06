#include "solve.h"

using namespace std;

vector<double> solve(vector<vector<double>> matrix, vector<double> targetValue) {
    vector<double> solution(targetValue.size());

    // Iterate rows of matrix, start at the bottom
    for (int i = targetValue.size() - 1; i >= 0; i--) {

        double numerator = targetValue.at(i);

        // Iterate columns
        for (int j = i + 1; j < targetValue.size(); j++) {
            numerator -= matrix.at(i).at(j) * solution.at(j);
        }
        solution.at(i) = numerator / matrix.at(i).at(i);
    }
    
    return solution;
}

