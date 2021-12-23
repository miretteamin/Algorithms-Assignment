#include <iostream>
#include <time.h>
#include <unistd.h>
#include "SkipList.h"
using namespace std;

int main()
{
    srand(getpid());
    SkipList s;
    s.insertN(5);
    s.insertN(2);
    s.insertN(7);
    s.insertN(30);
    s.printSkip();
    s.printSkipA();
    s.printLayer(3);
    s.insertN(5);
    cout <<s.searchN(2) << endl;
    cout <<s.searchN(30)<< endl;
    cout <<s.searchN(7)<< endl;
    cout <<s.searchN(15)<< endl;
    cout <<s.searchN(5)<< endl;
    s.deleteN(7);
    s.deleteN(12);
    cout << "After delete" <<endl;
    s.printSkip();
    return 0;
}
