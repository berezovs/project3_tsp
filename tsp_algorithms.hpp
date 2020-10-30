#ifndef TSP_ALGORITHMS_H
#define TSP_ALGORITHMS_H
#include <map>
#include <vector>
#include <random>
#include "CityGraph.hpp"
namespace tsp_algorithms
{
    namespace brute_force
    {
        double runBruteForce(int cities, CityGraph graph);

    } // namespace brute_force

    namespace genetic
    {
        
        double runGenetic(int numCities, int generations, int percent, CityGraph graph, int numOfPermutations);
        void generatePermutations(std::map<double, std::vector<double>> &tours, std::vector<double> &currentTour, CityGraph graph, int numPerms);
        void mutateTours(std::map<double, std::vector<double>> &tours, CityGraph graph, int percent, std::default_random_engine rng);
    } // namespace genetic
};    // namespace tsp_algorithms
#endif