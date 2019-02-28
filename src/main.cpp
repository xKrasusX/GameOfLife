#include <cstdlib>
#include <ctime>
#include <iostream> //TODO delete this

#include "game/Board.hpp"

using namespace std; //TODO delete this

int main()
{
    srand(time(NULL));

    Board *testBoard1 = new Board();
    (*testBoard1).changeSize(10, 10);

    (*testBoard1).revertField(5, 3);
    (*testBoard1).revertField(5, 4);
    (*testBoard1).revertField(5, 5);
    (*testBoard1).revertField(4, 5);
    (*testBoard1).revertField(3, 4);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    (*testBoard1).updateNextStep(1);
    (*testBoard1).printAll();
    cout << endl;

    return 0;
}
