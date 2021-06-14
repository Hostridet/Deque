#include "string"
#include "Methods.h"
#include <iostream>


using namespace  std;


int deq::GetLength()
{
    int count = 0;
    for (int i = 0; i < Size; i++)
    {
       if (log[i] != -1)
       {
           count++;
       }
    }
    return count;
}
void deq::LeftShifts()
{
    int shifts = (Size - fullness) - 1;
    shifts == 0 ? shifts += 1 : shifts;
    for (int i = Size - shifts; i >= 0; i--)
    {
        log[i + shifts] = log[i];
        log[i] = -1;
        log[i] = -1;
    }
    left += shifts;
    right += shifts;
}
void deq::RightShifts()
{
    int shifts = (Size - fullness);
    shifts == 0 ? shifts += 1 : shifts;
    for (int i = shifts; i < Size; i++)
    {
        log[i - shifts] = log[i];
        log[i] = -1;
    }
    right -= shifts;
    left -= shifts;
}
deq::deq(unsigned int N)
{
    this->Size = N;
    this->left = (N/2)-1;
    this->right = (N/2);
    log = new int[N];
    for (int i = 0; i < Size + 1; i++)
    {
        log[i] = -1;
    }
    fullness = 0;
}
deq::~deq()
{
}

int deq::addBack(int Number)
{
    if (fullness == Size)
    {
        return 1;
    }
    else
    {
        if (left >= 0)
        {
            log[left] = Number;
            left--;
            fullness++;
            return 0;
        }
        else if (left < 0)
        {
            LeftShifts();
            log[left] = Number;
            left--;
            fullness++;
            return 0;
        }
    }
}
int deq::addFront(int Number)
{
    if (Size == fullness)
    {
        return 1;
    }
    else
    {
        if (right < Size)
        {
            log[right] = Number;
            right++;
            fullness++;
            return 0;
        }
        else if (right >= Size)
        {
            RightShifts();
            log[right] = Number;
            right++;
            fullness++;
            return 0;
        }
    }
}

int deq::popBack()
{
    if (fullness == 0)
    {
        return -1;
    }
    else
    {
        int temp = log[left + 1];
        left++;
        log[left] = -1;
        fullness--;
        return temp;
    }

}

int deq::popFront()
{
    if (fullness == 0)
    {
        return -1;
    }
    else
    {
        int temp = log[right - 1];
        right--;
        log[right] = -1;
        fullness--;
        return temp;
    }
}
int deq::Copy(const deq deque1)
{
    fullness = deque1.fullness;
    right = deque1.right;
    left = deque1.left;
    Size = deque1.Size;
    if (fullness != 0)
    {
        for (int i = 0; i < deque1.Size; i++)
        {
            log[i] = deque1.log[i];
        }
    }
}
deq& deq::operator= (const deq& deque)
{
    if (Size == deque.Size)
    {
        log = deque.log;
        left = deque.left;
        right = deque.right;
        fullness = deque.fullness;
    }
    else if (deque.Size > Size)
    {
        fullness = 0;
        for (int i = 0; i < Size; ++i)
        {
            if (deque.log[i] >= 0)
            {
                fullness++;
                log[i] = deque.log[i];
            }
            else
            {
                log[i] = -1;
            }
        }
        left = -1;
        for (int i = 0; i < Size; ++i)
        {
            if (log[i] >= 0)
            {
                break;
            }
            else
            {
                left = i;
            }
        }
        right = Size;
        for (int i = Size - 1; i >= 0; --i)
        {
            if (log[i] >= 0)
            {
                break;
            }
            else
            {
                right = i;
            }
        }
    }
    else if (Size > deque.Size)
    {
        fullness = deque.fullness;
        for (int i = 0; i < Size; ++i)
        {
            if (i < deque.Size)
            {
                log[i] = deque.log[i];
            }
            else
            {
                log[i] = -1;
            }
        }
        left = -1;
        for (int i = 0; i < Size; ++i)
        {
            if (log[i] >= 0)
            {
                break;
            }
            else
            {
                left = i;
            }
        }
        right = Size;
        for (int i = Size - 1; i >= 0; --i)
        {
            if (log[i] >= 0)
            {
                break;
            }
            else
            {
                right = i;
            }
        }
    }
    return *this;
}