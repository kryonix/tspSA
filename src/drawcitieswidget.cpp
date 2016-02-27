#include "drawcitieswidget.h"
#include"tsp.h"

#include <QDebug>
DrawCitiesWidget::DrawCitiesWidget(QWidget *parent) : QWidget(parent)
{
    tsp = 0;
}

DrawCitiesWidget::~DrawCitiesWidget()
{

}

void DrawCitiesWidget::paintEvent(QPaintEvent *event)
{
    if(tsp == 0) return;

    QVector<QPoint> points = tsp->tspCities.getCitiesPoints();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for(int i = 0; i < points.size();i++)
    {
        painter.drawRect(QRect(points.at(i),QSize(6, 6)));
    }

    painter.setPen(Qt::red);



    for(int i = 0; i < tsp->route.route.size(); ++i)
    {
        int city1 = tsp->route.route.at(i);
        int city2 = tsp->route.route.at((i+1)%tsp->route.route.size());

        painter.drawLine(points.at(city1)+QPoint(3, 3), points.at(city2)+QPoint(3,3));
    }

    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawText(10, 10, QString("It: %1 \t Length: %2").arg(tsp->it).arg(tsp->routeLength(tsp->route)));
}

