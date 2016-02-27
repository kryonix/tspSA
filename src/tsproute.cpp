#include "tsproute.h"

#include <algorithm>
#include <random>

TSPRoute::TSPRoute()
{

}

TSPRoute::~TSPRoute()
{

}

void TSPRoute::init(size_t length)
{
    route.clear();
    route.reserve(length);

    for(int i = 0; i < length; i++)
    {
        route.push_back(i);
    }

    std::default_random_engine generator;

    std::random_shuffle(route.begin(),route.end());
}
