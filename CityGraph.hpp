#ifndef CITYGRAPH_H
#define CITYGRAPH_H
#include <vector>
#include <string>
class CityGraph
{
public:
    CityGraph();
    void loadGraph(std::string filename);
    double calculateCostOfATour(std::vector<double> &cities);
    void printGraph();

private:
    std::vector<std::vector<double>> cityGraph;
    static const int MAX_NUMBER_OF_COLS = 20;
};
#endif