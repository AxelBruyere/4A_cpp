#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>

#include "board.hpp"
#include "vec2.hpp"

//forward declaration of QLabel
class QLabel;

class render_area : public QWidget
{
    Q_OBJECT

public:
    render_area(QWidget *parent = 0);
    ~render_area();

    void init_fig();

protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);

private: //attributes

    /** Storage for all the geometrical objects */
    std::vector<QRectF *> objects;
    // /** Storage for all the discrete vertices of the objets that we use to draw them */
    // std::vector<std::vector<vec2> > point_sets;
    /** Storage for all the geometrical objects value */
    std::vector<int> objects_value;

};

#endif // RENDER_AREA_HPP
