#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <deque>
#include "CityGraph.hpp"

CityGraph::CityGraph()
{
}

void CityGraph::loadGraph(std::string filename)
{
    std::ifstream in(filename);

    if (in.is_open())

    {
        double number;
        int column = 0, row = 0;
        std::vector<double> vector;
        while (in >> number)
        {
            if (row == column)
            {
                vector.push_back(0);
                column++;
            }
            vector.push_back(number);
            column++;

            if (column == MAX_NUMBER_OF_COLS)
            {
                row++;
                column = 0;
                this->cityGraph.push_back(vector);
                vector.clear();
                continue;
            }
        }
        vector.push_back(0);
        this->cityGraph.push_back(vector);
    }
    else
    {
        std::cerr << "Error: Couldn't load file " + filename << std::endl;
    }

    in.close();
}

double CityGraph::calculateCostOfATour(std::vector<double> &cities)
{
    int from, to;

    double totalCost = 0.0;
    for (size_t i = 0; i < cities.size() - 1; i++)
    {

        from = cities.at(i);
        to = cities.at(i + 1);
        totalCost += this->cityGraph.at(from).at(to);
    }
    return totalCost;
}

void CityGraph::printGraph()
{
    std::cout << "Height: " << this->cityGraph.size() << std::endl;
    std::cout << "Length: " << this->cityGraph.at(0).size() << std::endl;
    std::cout << MAX_NUMBER_OF_COLS << std::endl;
    for (size_t i = 0; i < this->cityGraph.size(); i++)
    {
        for (size_t j = 0; j < this->cityGraph.at(i).size(); j++)
        {
            std::cout << this->cityGraph.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}
