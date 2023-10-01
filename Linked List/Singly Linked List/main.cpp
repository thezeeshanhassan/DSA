#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    ListADT list;
    list.appenedNode(2);
    list.appenedNode(3);
    list.appenedNode(4);
    list.insertNode(1);
    list.insertNode(5);
    list.insertNode(3);
    list.insertNode(1);
    list.display();
    list.deleteNode(1);
    list.deleteNode(3);
    cout << endl;
    list.display();
    cout << endl;
    cout << "Reversed Linked List is : " << endl;
    list.reverse();
    list.display();

    return 0;
}