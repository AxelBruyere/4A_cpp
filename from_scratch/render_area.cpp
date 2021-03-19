#include "render_area.hpp"

#include "board_drawer.hpp"
#include "board.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QLabel>


render_area::render_area(QWidget *parent)
    :QWidget(parent),objects(),point_sets()
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
    //create the board
    Board<int> * intBoard = new Board<int>(30, 20, 0);

    int const W = intBoard->w;
    int const H = intBoard->h;
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            QRectF* rect = new QRectF(i*20,j*20,20,20);
            objects.push_back(rect);
            //delete rect;
            //rect=nullptr;
        }
    }
}

void render_area::paintEvent(QPaintEvent*)
{
    std::cout<<"Init geometric figures ..."<<std::endl;

    //Initialize painter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;

    pen.setWidth(1.0);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    //draw board
    //add all objects in generic container
    point_sets.resize(objects.size());
    int const N_object=objects.size();
    for(int k_obj=0;k_obj<N_object;++k_obj)
    {
        painter.drawRect(*objects[k_obj]);
    }

}
