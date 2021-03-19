#pragma once

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template <typename T>
struct Board {
    int w;
    int h;
    vector<T> board;
    
    Board(int _w, int _h, T _v) : w(_w), h(_h) {
        board.assign(w * h, _v);
    }
    
    T get(int _w, int _h) {
        return board[_h * w + _w];
    }
    
    void set(int _w, int _h, T newValue) {
        board[_h * w + _w] = newValue;
    }
    
    void print() {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cout << get(x, y) << " ";
            }
            cout << endl;
        }
    }
};

template <typename T>
void print(Board<T> *board) {
    for (int y = 0; y < board->h; y++) {
        for (int x = 0; x < board->w; x++) {
            cout << board->get(x, y) << " ";
        }
        cout << endl;
    }
}

#endif