#include <iostream>
#include <vector>
#include "CityGraph.hpp"

int main() {

    CityGraph *g = new CityGraph();
    g->loadGraph("distances.txt");
    g->printGraph();
    std::vector<double> cities = {0,1,2,5,0};
    std::cout<<g->calculateCostOfATour(cities);
    return 0;
}