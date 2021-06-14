#include "string"
#include <iostream>
#pragma once

using namespace std;

class deq
{;
private:
    int Size;
    int left;
    int right;
    int* log;
    int fullness;
public:
    explicit deq(unsigned int N = 10);
    ~deq();
    void RightShifts();
    void LeftShifts();
    int addFront(int Number);
    int addBack(int Number);
    int popFront();
    int popBack();
    int GetLength();
    int Copy(const deq deque1);
    deq& operator= (const deq& deque);
    friend std::ostream& operator<< (std::ostream &out, const deq &deque)
    {
        out << "Deque is" << std::endl;
        out << "| ";
        for (int i = 0; i < deque.Size; ++i)
        {
            if (deque.log[i] != -1) {
                out << deque.log[i] << " | ";
            }

        }
        out << std::endl;

        return out;
    }



};