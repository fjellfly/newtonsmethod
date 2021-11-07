#ifndef ROOT_H
#define ROOT_H

#include<vector>
#include<functional>

struct FindRootResult {
    FindRootResult(std::vector<double>, int);
    int iteration;
    std::vector<double> x;
};

FindRootResult findRoot(std::vector<double>, std::function<std::vector<double> (std::vector<double>)>, int, double, double);
double getNorm(std::vector<double>);

#endif /* ROOT_H */