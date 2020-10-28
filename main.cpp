#include <iostream>
#include <vector>
#include "CityGraph.hpp"
#include "Permutation.hpp"

int main() {

    // CityGraph *g = new CityGraph();
    // g->loadGraph("distances.txt");
    // g->printGraph();
    // std::vector<double> cities = {0,1,2,5,0};
    // std::cout<<g->calculateCostOfATour(cities);
    int length = 5;
     Permutation p(length); 
     p.initS(length);
     int total = p.fact(length);
     for(int i = 0; i < total; i++)  
     {
       p.printS();
       p.perm1();
     }

    return 0;
}