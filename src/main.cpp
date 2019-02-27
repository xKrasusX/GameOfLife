#include <cstdlib>
#include <ctime>
#include <iostream> //TODO delete this

#include "game/Board.hpp"

using namespace std; //TODO delete this

int main()
{
    srand(time(NULL));

    Board *testBoard1 = new Board();
    (*testBoard1).printBoard();
    cout << endl;

    (*testBoard1).revertBoard();
    (*testBoard1).printBoard();
    cout << endl;

    (*testBoard1).clearBoard();
    (*testBoard1).printBoard();
    cout << endl;

    (*testBoard1).randomizeBoard();
    (*testBoard1).printBoard();
    cout << endl;

    return 0;
}
