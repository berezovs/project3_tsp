#ifndef TSP_ALGORITHMS_H
#define TSP_ALGORITHMS_H
#include "CityGraph.hpp"
namespace tsp_algorithms
{
    namespace brute_force
    {
        double runBruteForce(int cities, CityGraph graph);
    
    } // namespace brute_force

    namespace genetic
    {
        double runGenetic(int numCities, int generations, int percent, CityGraph graph);
    }
}; // namespace tsp_algortihms
#endif