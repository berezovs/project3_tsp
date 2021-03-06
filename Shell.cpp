/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: Shell.cpp
  Assignment number:Project 3-DS&AII

 
***************************************************************/
#include <iostream>
#include "Shell.hpp"
#include "TSPAlgorithms.hpp"
#include "CityGraph.hpp"
#include "Timer.hpp"

Shell::Shell()
{
}

void Shell::run()
{
  const int MIN = 0;
  const int MAX = 100;
  const int MIN_CITIES = 0;
  const int MAX_CITIES = 20;
  int numCities = 0, numTours = 0, numGenerations = 0, percentMutations = 0;

  //takes user input 
  while (numCities <= MIN_CITIES || numCities >= MAX_CITIES)
  {
    std::cout << "Enter number of cities to run(1-20): ";
    std::cin >> numCities;
    std::cin.clear();
  }

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

  //initializes appropriate classes and calls the necessary methods to run algortihms and measure their performance
  std::cout << "Running the algorithm...\n";
  CityGraph g;
  Timer c;
  TSPAlgorithms tsp;
  g.loadGraph("distances.txt");

  double cost;
  c.startTimer();
  cost = tsp.runBruteForce(numCities, g);
  c.stopTimer();

  std::cout << "Number of cities run: " << numCities << std::endl;
  std::cout << "Time the brute force algorithm took: " << c.getFormattedTime() << std::endl;
  std::cout << "Cost(Brute Force): " << cost << std::endl;

  c.startTimer();
  cost = tsp.runGenetic(numCities, numGenerations, percentMutations, g, numTours);
  c.stopTimer();
  std::cout << "\nTime the genetic algorithm took: " << c.getFormattedTime() << std::endl;
  std::cout << "Cost(Genetic): " << cost << std::endl;
  std::cout << "Percent of optimal: " << tsp.percentOfOptimal() << std::endl;
}