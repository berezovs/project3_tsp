#include "tsp_algorithms.hpp"
#include "CityGraph.hpp"
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <iostream>

double tsp_algorithms::brute_force::runBruteForce(int cities, CityGraph graph)
{
    std::vector<double> tour;
    double currentCost, bestCost;
    for (size_t i = 0; i < cities; i++)

    {
        tour.push_back(i);
    }

    bestCost = graph.calculateCostOfATour(tour);
    do
    {
        currentCost = graph.calculateCostOfATour(tour);
        if (currentCost < bestCost)
            bestCost = currentCost;
    } while (std::next_permutation(tour.begin(), tour.end()));
    return bestCost;
}

double tsp_algorithms::genetic::runGenetic(int numCities, int generations, int percent, CityGraph graph)
{
    int numOfPermutations = numCities * numCities;
    double currentResult, bestResult;
    std::map<double, std::vector<double>> elites;
    int counter = generations;
    std::vector<double> tour;

    for (int i = 0; i < numCities; i++)
    {
        tour.push_back(i);
    }

    for (int i = 0; i < numOfPermutations; i++)
    {

        std::next_permutation(tour.begin(), tour.end());
        double currentCost = graph.calculateCostOfATour(tour);
        elites.insert(std::pair<double, std::vector<double>>(currentCost, tour));
    }
    std::map<double, std::vector<double>>::iterator from = elites.begin();
    ++from;
    ++from;
    std::cout << "Size of map: " << elites.size() << std::endl;
    elites.erase(from, elites.end());

    std::cout << "Size of map: " << elites.size() << std::endl;
    return (elites.begin())->first;
}
