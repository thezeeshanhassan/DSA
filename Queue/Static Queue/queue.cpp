#include <iostream>
#include "queue.h"

using namespace std;

queueADT::queueADT(int &cap) : rare(-1), front(-1), count(0), capacity(cap)
{
    queueArray = new int[cap];
}
queueADT::~queueADT()
{
    delete[] queueArray;
}

void queueADT::enQueue(int num)
{
    if (isFull())
    {
        cout << "Queue is Full\n";
    }
    else
    {
        rare = (rare + 1) % capacity;
        queueArray[rare] = num;
        count += 1;
    }
}

int queueADT::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return 0;
    }
    else
    {
        front = (front + 1) % capacity;
        int value = queueArray[front];
        count -= 1;
        return value;
    }
}

bool queueADT::isEmpty() const
{
    // count == 0 ? true : false;
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool queueADT::isFull() const
{
    // count == capacity ? true : false;
    if (count == capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int queueADT::size() const
{
    return count;
}

void queueADT::display() const
{
    for (int traverse{}; traverse < capacity; traverse += 1)
    {
        cout << queueArray[traverse] << " ";
    }
}

// clear sets the front and rear indices, and sets numItems to 0.
void queueADT::clear()
{
    front = -1;
    rare = -1;
    count = 0;
}