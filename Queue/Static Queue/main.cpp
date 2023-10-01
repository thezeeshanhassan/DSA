#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    int capacity{5};
    queueADT queue(capacity);

    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);
    queue.enQueue(6);
    queue.display();
    cout << endl;
    cout << queue.deQueue() << ' ';
    cout << queue.deQueue() << ' ';
    cout << queue.deQueue() << ' ';
    cout << queue.deQueue() << ' ';
    cout << queue.deQueue() << ' ';
    queue.clear();

    return 0;
}