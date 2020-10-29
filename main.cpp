#include <iostream>
#include <vector>
#include "CityGraph.hpp"
#include "Timer.hpp"
#include "tsp_algorithms.hpp"

int main()
{
    CityGraph g;
    g.loadGraph("distances.txt");
    Timer c;
    double cost;
    c.startTimer();
    cost = tsp_algorithms::brute_force::runBruteForce(10, g);
    c.stopTimer();
    std::cout << c.getElapsedTimeInMilliseconds() << std::endl;
    std::cout << "Cost(Brute Force): " << cost << std::endl;

    c.startTimer();
    std::cout << "Cost(Genetic): " << tsp_algorithms::genetic::runGenetic(10, 80, 70, g) << std::endl;
    c.stopTimer();
    std::cout << c.getElapsedTimeInMilliseconds() << std::endl;

    return 0;
}
