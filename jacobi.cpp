#include "jacobi.h"

#include <iterator>

using namespace std;

vector<vector<double>> getJacobian(vector<double> x, function<vector<double> (vector<double>)> F, double h) {
    const int n = x.size();
    vector<vector<double>> jacobian(n, std::vector<double>(n, 0));
    
    for (int j = 0; j < n; j++) {
        
        vector<double> xPlusH;
        copy(x.begin(), x.end(), back_inserter(xPlusH));
        xPlusH.at(j) += h;
        
        for (int i = 0; i < n; i++) {
            jacobian.at(i).at(j) = (F(xPlusH).at(i) - F(x).at(i)) / h;
        }
    }
    
    return jacobian;
}