/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: TSPAlgorithms.hpp
  Assignment number:Project 3-DS&AII

 
***************************************************************/
#ifndef TSP_ALGORITHMS_H
#define TSP_ALGORITHMS_H
#include <map>
#include <vector>
#include <random>
#include "CityGraph.hpp"
class TSPAlgorithms
{
public:
    TSPAlgorithms();
    double runBruteForce(int numCities, CityGraph graph);
    double runGenetic(int numCities, int generations, int percent, CityGraph graph, int numOfPermutations);

private:
    void generatePermutations(std::map<double, std::vector<double>> &tours, std::vector<double> &currentTour, CityGraph graph, int numPerms);
    void mutateTours(std::map<double, std::vector<double>> &tours, CityGraph graph, int percent, std::default_random_engine rng);
    void generateFirstTour(int cities);

    std::vector<double> tour;
};
#endif