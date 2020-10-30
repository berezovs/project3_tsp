#include "tsp_algorithms.hpp"
#include "CityGraph.hpp"
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <stack>
#include <algorithm>
#include <random>
#include <iostream>

double tsp_algorithms::brute_force::runBruteForce(int cities, CityGraph graph)
{

    std::vector<double> tour;

    double currentCost, bestCost;
    for (int i = 1; i <= cities; i++)

    {
        tour.push_back(i);
    }

    bestCost = graph.calculateCostOfATour(tour);

    do
    {
        std::vector<double> temp(tour);
        temp.push_back(0);
        temp.insert(temp.begin(),0);
        currentCost = graph.calculateCostOfATour(temp);
        if (currentCost < bestCost)
            bestCost = currentCost;
    } while (std::next_permutation(tour.begin(), tour.end()));
    return bestCost;
}

double tsp_algorithms::genetic::runGenetic(int numCities, int generations, int percent, CityGraph graph, int numOfPermutations)
{


    std::map<double, std::vector<double>> tours;
    std::vector<double> tour;
    std::default_random_engine rng = std::default_random_engine{};

    for (int i = 1; i <= numCities; i++)
    {
        tour.push_back(i);
    }

    for (int i = 0; i < generations; i++)
    {

        generatePermutations(tours, tour, graph, numOfPermutations);
        mutateTours(tours, graph, percent, rng);
    }

    return (tours.begin())->first;
}

void tsp_algorithms::genetic::generatePermutations(std::map<double, std::vector<double>> &tours, std::vector<double> &currentTour, CityGraph graph, int numPerms)
{

    for (int i = 0; i < numPerms; i++)
    {
        std::next_permutation(currentTour.begin(), currentTour.end());
        std::vector<double> temp(currentTour);
        double currentCost;
        //push the first value to the end of temp as the last destination in the trip
        temp.push_back(0);
        temp.insert(temp.begin(), 0);
        currentCost = graph.calculateCostOfATour(temp);
        tours.insert(std::pair<double, std::vector<double>>(currentCost, currentTour));
    }
}

void tsp_algorithms::genetic::mutateTours(std::map<double, std::vector<double>> &tours, CityGraph graph, int percent, std::default_random_engine rng)
{
    std::stack<std::vector<double>> tempTours;
    double ratio = (double)percent / (double)100;
    int numOfToursToMutate = tours.size() * ratio;

    auto it = tours.begin();
    for (int i = 0; i < numOfToursToMutate; i++)
    {
        std::vector<double> temp(it->second);
        std::shuffle(std::begin(temp), std::end(temp), rng);
        tempTours.push(temp);
        it++;
    }
    auto from = tours.begin();
    it++;
    it++;

    tours.erase(from, tours.end());

    while (!tempTours.empty())
    {
        std::vector<double> temp(tempTours.top());
        temp.push_back(temp.at(0));
        double currentCost = graph.calculateCostOfATour(temp);
        tours.insert(std::pair<double, std::vector<double>>(currentCost, tempTours.top()));
        tempTours.pop();
    }
}
