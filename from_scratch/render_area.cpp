#include "render_area.hpp"

#include "board.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QLabel>


render_area::render_area(QWidget *parent)
    :QWidget(parent),objects(),objects_value()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    init_fig();
}

render_area::~render_area()
{
    int const N=objects.size();
    for(int k=0;k<N;++k)
    {
        delete objects[k];
        objects[k]=nullptr;
    }
}

void render_area::init_fig()
{
    /** -- Create the board -- */
    Board<int> * intBoard = new Board<int>(30, 20, 0);

    int layout = 1;             //Choix du layout
    switch(layout){
    case 1:                     //layout 1
        intBoard->set(15, 6, 1);    //obstacle
        intBoard->set(15, 7, 1);    //*
        intBoard->set(15, 8, 1);    //*
        intBoard->set(15, 9, 1);    //*
        intBoard->set(15,10, 1);    //*
        intBoard->set(15,11, 1);    //*
        intBoard->set(15,12, 1);    //*
        intBoard->set(15,13, 1);    //*
        intBoard->set(15,14, 1);    //*
        intBoard->set(15,15, 1);    //*
        intBoard->set(15,16, 1);    //*
        intBoard->set( 0, 0, 2);    //point de départ
        intBoard->set(29,19, 3);    //point d'arrivée
        break;
    case 2:                     //layout 2
        intBoard->set(10, 6, 1);    //obstacle
        intBoard->set(10, 7, 1);    //*
        intBoard->set(10, 8, 1);    //*
        intBoard->set(10, 9, 1);    //*
        intBoard->set(10,10, 1);    //*
        intBoard->set(10,11, 1);    //*
        intBoard->set(11,12, 1);    //*
        intBoard->set(12,13, 1);    //*
        intBoard->set(13,14, 1);    //*
        intBoard->set(14,15, 1);    //*
        intBoard->set(15,16, 1);    //*
        intBoard->set( 0, 0, 2);    //point de départ
        intBoard->set(29,19, 3);    //point d'arrivée
        break;
    case 3:                     //layout 3
        intBoard->set( 0, 0, 2);    //point de départ
        intBoard->set(29,19, 3);    //point d'arrivée
        break;
    case 4:                     //layout 4
        break;
    }

    int const W = intBoard->w;
    int const H = intBoard->h;
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            QRectF* rect = new QRectF(i*20,j*20,20,20);
            objects.push_back(rect);
            objects_value.push_back(intBoard->get(i,j));
        }
    }
}

void render_area::paintEvent(QPaintEvent*)
{
    std::cout<<"Init geometric figures ..."<<std::endl;

    //Initialize painter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush_gray = painter.brush();
    brush_gray.setColor(Qt::gray);
    brush_gray.setStyle(Qt::SolidPattern);

    QBrush brush_white = painter.brush();
    brush_white.setColor(Qt::white);
    brush_white.setStyle(Qt::SolidPattern);

    QBrush brush_red = painter.brush();
    brush_red.setColor(Qt::red);
    brush_red.setStyle(Qt::SolidPattern);

    QBrush brush_green = painter.brush();
    brush_green.setColor(Qt::green);
    brush_green.setStyle(Qt::SolidPattern);

    painter.setBrush(brush_gray);

    QPen pen;

    pen.setWidth(1.0);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    //* draw board *//

    int const N_object=objects.size();
    for(int k_obj=0;k_obj<N_object;++k_obj)
    {
        switch(objects_value[k_obj]){
        case 0:     /** Case vide */
           painter.setBrush(brush_white);
           break;
        case 1:     /** Case obstacle */
           painter.setBrush(brush_gray);
           break;
        case 2:     /** Case Point de départ */
           painter.setBrush(brush_red);
           break;
        case 3:     /** Case Point d'arrivée */
           painter.setBrush(brush_green);
           break;
        }
        painter.drawRect(*objects[k_obj]);
    }

}


