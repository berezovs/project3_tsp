#include <iostream>
#include <vector>
#include "CityGraph.hpp"
#include "Permutation.hpp"
#include "Timer.hpp"

int main() {

    // CityGraph *g = new CityGraph();
    // g->loadGraph("distances.txt");
    // g->printGraph();
    // std::vector<double> cities = {0,1,2,5,0};
    // std::cout<<g->calculateCostOfATour(cities);
    int length = 8;
     Permutation p(length); 
     p.initS(length);
     int total = p.fact(length);
     Timer t;
     t.startTimer();
     for(int i = 0; i < total; i++)  
     {
       p.printS();
       p.perm1();
     }
     t.stopTimer();
     std::cout<<"Elapsed time: "<<t.getElapsedTimeInMilliseconds()<<std::endl;

    return 0;
}