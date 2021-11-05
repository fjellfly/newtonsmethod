#ifndef JACOBI_H
#define JACOBI_H

#include<vector>
#include<functional>

std::vector<std::vector<double>> getJacobian(std::vector<double>, std::function<std::vector<double> (std::vector<double>)>, double);

#endif /* JACOBI_H */

