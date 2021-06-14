#include <iostream>
#include "Methods.h"

using namespace std;

int main() {

    deq deque (15);




    for (int i = 0; i <=6 ; i++) {
        deque.addBack(i);
  //      deque.addFront(i*10);
    }
    cout << deque;
    cout << deque.GetLength() << endl;

    int k = deque.popFront();
    cout << deque;
    deque.addBack(k);
    cout << deque;

    deque.addBack(deque.popFront());
    cout << deque;




    for (int i = 0; i <= 10; i++)
    {
        deque.addFront(deque.popFront());
    }

    cout << deque;
    cout << deque.GetLength() << endl;

    for (int i = 0; i <= deque.GetLength() /2; i++)
    {  int k=deque.popBack();
        deque.addFront(k*10);
        deque.addFront(k*10);
        cout << deque;
        cout << deque.GetLength() << endl;
    }
    cout << deque;

 /*   for (int i = 0; i <= 4; i++)
    {
        deque.popFront();
    }
    cout << deque;
    for (int i = 0; i <= 4; i++)
    {
        deque.addBack(i);
    }
    cout << deque;
    /*
    for (int i = 0; i <= 7; i++)
    {
        deque.addFront(i);
    }
    cout << deque;
    cout << deque.GetLength() << endl;


    deq deque1 = deq(5);
    deque1.addBack(4);

    //Присваивание
    deque1 = deque;
    cout << deque1;
    cout << deque1.GetLength() << endl;

    //копирование
    deq deque3 = deq(2);
    deque3.Copy(deque1);
    cout << deque3;

*/
    return 0;
}
