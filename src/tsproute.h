#ifndef TSPROUTE_H
#define TSPROUTE_H

#include <QVector>

class TSPRoute
{
public:
    QVector<int> route;

    TSPRoute();
    ~TSPRoute();

    void init(size_t length);
};

#endif // TSPROUTE_H
