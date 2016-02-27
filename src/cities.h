#ifndef CITIES_H
#define CITIES_H

#include <QVector>
#include <QPoint>

#include <random>
class Cities
{
public:
    QVector<std::pair<int,int> > cities;

    Cities();
    ~Cities();

    void newCities(size_t numCities);

    QVector<QPoint> getCitiesPoints();

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

};

#endif // CITIES_H
