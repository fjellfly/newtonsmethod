#include "jacobi.h"

#include <iterator>

using namespace std;

/**
 * Calculate the Jacobian of a given function for a
 * given position using finite differences
 *
 * @param x Position for which the Jacobian should be calculated
 * @param F Function under investigation
 * @param h Step size for calculating finite difference
 * @return Jacobian
 */
vector<vector<double>> getJacobian(vector<double> x, function<vector<double> (vector<double>)> F, double h) {
    const int n = x.size();
    vector<vector<double>> jacobian(n, std::vector<double>(n, 0));
    
    // Iterate rows of matrix
    for (int j = 0; j < n; j++) {
        
        vector<double> xPlusH;
        copy(x.begin(), x.end(), back_inserter(xPlusH));
        xPlusH.at(j) += h;
        
        // Iterate columns
        for (int i = 0; i < n; i++) {
            jacobian.at(i).at(j) = (F(xPlusH).at(i) - F(x).at(i)) / h;
        }
    }
    
    return jacobian;
}