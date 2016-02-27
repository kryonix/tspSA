#ifndef DRAWCITIESWIDGET_H
#define DRAWCITIESWIDGET_H

#include <QWidget>

#include <QVector>
#include <QPoint>
#include <QPainter>
#include <QPaintEvent>

class TSP;
class DrawCitiesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawCitiesWidget(QWidget *parent = 0);
    ~DrawCitiesWidget();

    TSP* tsp;
signals:

public slots:
    void paintEvent(QPaintEvent *event);
};

#endif // DRAWCITIESWIDGET_H
