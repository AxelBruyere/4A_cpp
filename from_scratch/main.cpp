#include <QApplication>
#include "window.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    window fenetre;
    fenetre.show();

    return app.exec();
}
    /*// Programme existant
    Board<int> * intBoard = new Board<int>(3, 4, 0);
    
    // 0 0 0
    // 0 0 0
    // 0 0 0
    // 0 0 0
    
    intBoard->set(0, 0, 1);
    intBoard->set(1, 2, 2);
    intBoard->set(2, 3, 3);
    
    // 1 0 0
    // 0 0 0
    // 0 2 0
    // 0 0 3
    
    
    // 3 way of printing
    
    // 1. template
    print(intBoard);
    
    cout << endl;
    
    // 2. in struct
    intBoard->print();
    
    cout << endl;
    
    // 3. direct
    for (int y = 0; y < intBoard->h; y++) {
        for (int x = 0; x < intBoard->w; x++) {
            cout << intBoard->get(x, y) << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    
    ///////////////////////////////////////////////////////
    
    Board<char> * charBoard = new Board<char>(3, 4, ' ');
    
    //
    //
    //
    //
    
    charBoard->set(0, 0, 'O');
    charBoard->set(1, 2, 'O');
    charBoard->set(2, 3, 'O');
    
    // O
    //
    //   O
    //     O
    
    print(charBoard);
    
    ///////////////////////////////////////////////////////
    
    Board<string> * strBoard = new Board<string>(3, 4, ".");
    
    //
    //
    //
    //
    
    strBoard->set(0, 0, "X");
    strBoard->set(1, 2, "X");
    strBoard->set(2, 3, "X");
    
    // X
    //
    //   X
    //     X
    
    print(strBoard);
    
    ///////////////////////////////////////////////////////
    
    // copy board
    
    cout << "copy board before" <<  endl;
    
    Board<int> * copiedBoard = new Board<int>(intBoard->w, intBoard->h, 0);
    copiedBoard->print();
    
    cout << "copy board after" <<  endl;
    
    copy(intBoard->board.begin(), intBoard->board.end(), copiedBoard->board.begin());
    copiedBoard->print();
    
    // check board
    cout << "checkboard" <<  endl;
    intBoard->set(0, 0, 1);
    intBoard->set(0, 1, 1);
    intBoard->set(1, 0, 1);
    intBoard->set(1, 1, 1);
    intBoard->print();
    cout <<  endl;
    Board<bool> * checkBoard = new Board<bool>(intBoard->w, intBoard->h, false);
    for (int y = 0; y < (intBoard->h - 1); y++) {
        for (int x = 0; x < (intBoard->w - 1); x++) {
            if (intBoard->get(x, y) == 0) {
                continue;
            }
            if (intBoard->get(x+1, y) == 1
                && intBoard->get(x, y+1) == 1
                && intBoard->get(x+1, y+1) == 1) {
                checkBoard->set(x, y, true);
                checkBoard->set(x+1, y, true);
                checkBoard->set(x, y+1, true);
                checkBoard->set(x+1, y+1, true);
            }
        }
    }
    checkBoard->print();
    cout << endl;
    
    // remove dupli
    cout << "remove dupli of intBoard" <<  endl;
    for (int y = 0; y < checkBoard->h; y++) {
        for (int x = 0; x < checkBoard->w; x++) {
            if (checkBoard->get(x, y) == true) {
                intBoard->set(x, y, 0);
            }
        }
    }
    intBoard->print();
    cout << endl;
    
    // down blocks
    cout << "down intBoard" <<  endl;
    for (int x = 0; x < intBoard->w; x++) {
        deque<int> buffer;
        buffer.assign(intBoard->h, 0);
        for (int y = 0; y < intBoard->h; y++) {
            if (intBoard->get(x, y) != 0) {
                buffer.push_front(intBoard->get(x, y)); // insert front, count = height + 1
                buffer.pop_back(); // count = height
            }
        }
        for (int y = 0; y < intBoard->h; y++) {
            intBoard->set(x, y, buffer.back());
            buffer.pop_back();
        }
    }
    intBoard->print();
    cout << endl;
    
    
    return 0;*/
