#include "tsp.h"
#include <QDebug>
#include <cmath>
#include <algorithm>
TSP::TSP()
{

}

TSP::~TSP()
{

}

void TSP::init(size_t numCities)
{
    it= 0;
    tspCities.newCities(numCities);
    route.init(numCities);

    distribution = std::uniform_int_distribution<int>(0, numCities-1);

    realDistribution = std::uniform_real_distribution<double>(0, 1);

    heat = 0.5;

    map.clear();
    mapRoute.clear();
}

int TSP::routeLength(TSPRoute &route)
{
    int length = 0;

    for(int i = 0; i < route.route.length(); ++i)
    {
        int num = route.route.at(i);
        int num2 = route.route.at((i+1)%(route.route.length()));

        length += (tspCities.cities.at(num).first-tspCities.cities.at(num2).first)*(tspCities.cities.at(num).first-tspCities.cities.at(num2).first)+
                (tspCities.cities.at(num).second-tspCities.cities.at(num2).second)*(tspCities.cities.at(num).second-tspCities.cities.at(num2).second);

    }

    return length;
}

void TSP::step()
{
    ++it;
    heat *= 0.999999;
    TSPRoute newRoute;
    newRoute.route = route.route;

    for(int i = 0; i < distribution(generator)%3; i++)
    {
        int x = distribution(generator);
        int y = distribution(generator);

        std::swap(newRoute.route[x], newRoute.route[y]);
    }

    if(realDistribution(generator) < heat*0.0001 || routeLength(newRoute) < routeLength(route))
    {
        route.route = newRoute.route;
    }

}
