#include "cities.h"

#include<algorithm>
Cities::Cities()
{
    distribution = std::uniform_int_distribution<int>(0,500);
}

Cities::~Cities()
{

}

void Cities::newCities(size_t numCities)
{
    cities.clear(); //Clear Cities if exist

    cities.reserve(numCities);
    for(; numCities > 0; numCities--)
    {
        cities.push_back(std::pair<int,int>(distribution(generator), distribution(generator)));
    }
}

QVector<QPoint> Cities::getCitiesPoints()
{
    QVector<QPoint> points;

    for(size_t i = 0; i < cities.size(); ++i)
    {
        points.push_back(QPoint(cities.at(i).first, cities.at(i).second));
    }

    return points; //deepcopy i hope?
}

