#include "board_drawer.hpp"

void draw(QPainter& painter, Board<int> const& board)
{
    int const W = board.w;
    int const H = board.h;
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            painter.drawRect(i*10,j*10,10,10);
        }
    }
};
