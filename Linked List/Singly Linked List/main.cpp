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
    list.reverse();
    list.display();
    cout << endl;
    list.reverse();
    list.display();
    cout << endl;
    list.insertNode(1);
    list.insertNode(3);
    list.insertNode(5);
    list.display();
    cout << endl;
    list.deleteDuplicateInSortedList();
    list.display();
    cout << endl;
    if (list.isSorted())
    {
        cout << "List is Sorted";
    }
    else
    {
        cout << "List is Not Sorted";
    }
    return 0;
}