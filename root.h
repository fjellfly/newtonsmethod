#ifndef ROOT_H
#define ROOT_H

#include<vector>
#include<functional>

std::vector<double> findRoot(std::vector<double>, std::function<std::vector<double> (std::vector<double>)>, int, double, double);

#endif /* ROOT_H */