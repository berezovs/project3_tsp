/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: TSPAlgorithms.cpp
  Assignment number:Project 3-DS&AII

 
***************************************************************/

#include "TSPAlgorithms.hpp"
#include "CityGraph.hpp"
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <random>
#include <iostream>

TSPAlgorithms::TSPAlgorithms()
{
}

double TSPAlgorithms::runBruteForce(int numCities, CityGraph graph)
{

    double currentCost=0.0, bestCost=0.0;
    this->generateFirstTour(numCities);
    
    std::vector<double> temp(this->tour);
    temp.push_back(0);
    temp.insert(temp.begin(), 0);
    bestCost = graph.calculateCostOfATour(temp);

    do
    {
        std::vector<double> temp(this->tour);
        temp.push_back(0);
        temp.insert(temp.begin(), 0);
        currentCost = graph.calculateCostOfATour(temp);
        if (currentCost < bestCost)
            bestCost = currentCost;
    } while (std::next_permutation(this->tour.begin(), this->tour.end()));

    this->tour.clear();
    return bestCost;
}

double TSPAlgorithms::runGenetic(int numCities, int generations, int percent, CityGraph graph, int numOfPermutations)
{

    std::map<double, std::vector<double>> tours;
    this->generateFirstTour(numCities);

    std::default_random_engine rng = std::default_random_engine{};

    for (int i = 0; i < generations; i++)
    {

        generatePermutations(tours, this->tour, graph, numOfPermutations);
        mutateTours(tours, graph, percent, rng);
    }
    this->tour.clear();
    return (tours.begin())->first;
}

void TSPAlgorithms::generatePermutations(std::map<double, std::vector<double>> &tours, std::vector<double> &currentTour, CityGraph graph, int numPerms)
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

void TSPAlgorithms::mutateTours(std::map<double, std::vector<double>> &tours, CityGraph graph, int percent, std::default_random_engine rng)
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
        temp.push_back(0);
        temp.insert(temp.begin(), 0);

        double currentCost = graph.calculateCostOfATour(temp);
        tours.insert(std::pair<double, std::vector<double>>(currentCost, tempTours.top()));
        tempTours.pop();
    }
}

void TSPAlgorithms::generateFirstTour(int cities)
{
    for (int i = 1; i <= cities; i++)

    {
        this->tour.push_back(i);
    }
}
