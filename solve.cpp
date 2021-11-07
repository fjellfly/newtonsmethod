#include <stdexcept>

#include "solve.h"

using namespace std;

/**
 * Solve matrix equation
 *
 * It's expected that the given matrix is a upper triangle n x n matrix.
 * Therefore backward substitution can be applied.
 *
 * m * solution = target
 *
 * @param matrix Upper triangular n x n matrix
 * @param target Vector containing the expected result of the matrix equation
 * @return Solution vector of the matrix equation
 */
vector<double> solve(vector<vector<double>> matrix, vector<double> target) {
    vector<double> solution(target.size());

    // Iterate rows of matrix, start at the bottom
    for (int i = target.size() - 1; i >= 0; i--) {

        double numerator = target.at(i);

        // Iterate columns
        for (int j = 0; j < i; j++) {
            if(matrix.at(i).at(j) != 0) {
                throw std::invalid_argument("Input matrix isn't an upper triangle n x n matrix");
            }
        }
        for (int j = i + 1; j < target.size(); j++) {
            numerator -= matrix.at(i).at(j) * solution.at(j);
        }
        solution.at(i) = numerator / matrix.at(i).at(i);
    }
    
    return solution;
}

