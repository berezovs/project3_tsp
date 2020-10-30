#include <iostream>
#include "Shell.hpp"
#include "tsp_algorithms.hpp"
#include "CityGraph.hpp"
#include "Timer.hpp"

Shell::Shell()
{
}

void Shell::run()
{
    const int MIN = 0;
    const int MAX = 100;
    int numCities = 0, numTours = 0, numGenerations = 0, percentMutations = 0;

    std::cout << "Enter number of cities to run: ";
    std::cin >> numCities;

    std::cout << "Enter number of tours in a generation: ";
    std::cin >> numTours;

    std::cout << "Enter the number of generations to simulate: ";
    std::cin >> numGenerations;

    while (percentMutations <= MIN || percentMutations >= MAX)
    {
        std::cout << "Enter the percent of tours to be mutated(0-100): ";
        std::cin >> percentMutations;
        std::cin.clear();
    }

    std::cout << "Starting the algorithm...\n";
    CityGraph g;
    g.loadGraph("distances.txt");
    Timer c;
    double cost;
    c.startTimer();
    cost = tsp_algorithms::brute_force::runBruteForce(numCities, g);
    c.stopTimer();
    std::cout << "Time the brute force algorithm took: " << c.getFormattedTime() << std::endl;
    std::cout << "Cost(Brute Force): " << cost << std::endl;

    c.startTimer();
    cost = tsp_algorithms::genetic::runGenetic(numCities, numGenerations, percentMutations, g, numTours);
    c.stopTimer();
    std::cout << "\nTime the genetic algorithm took: " << c.getFormattedTime() << std::endl;
    std::cout << "Cost(Genetic): " << cost << std::endl;
}