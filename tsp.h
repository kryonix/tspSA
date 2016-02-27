#ifndef TSP_H
#define TSP_H

#include "cities.h"
#include "tsproute.h"

#include <random>
#include <QMap>
#include <QHash>

class TSP
{
private:
    QMap< QString, int > mapRoute;
    QMap< std::pair<int, int>, int > map;
public:
    int it;
    Cities tspCities;
    TSPRoute route;

    double heat;

    TSP();
    ~TSP();

    void init(size_t numCities);
    int routeLength(TSPRoute &route);
    void step();

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
    std::uniform_real_distribution<double> realDistribution;
};

#endif // TSP_H
