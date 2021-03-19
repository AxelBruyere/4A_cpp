#pragma once

#ifndef BOARD_DRAWER_H
#define BOARD_DRAWER_H

#include "board.hpp"
#include <QPainter>
#include <QRectF>

class QPainter;

void draw(QPainter& painter, Board<int> const& board);


#endif // BOARD_DRAWER_H
