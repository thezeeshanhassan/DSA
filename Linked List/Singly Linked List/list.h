#ifndef list_h
#define list_h
#include "listnode.h"

class ListADT
{
public:
    // Basic List ADT
    ListADT();
    void appenedNode(int);
    void insertNode(int);
    void deleteNode(int);
    void display() const;

    // Additional Functions in Linked List
    void reverse();
    void deleteDuplicateInSortedList();
    bool isSorted();

private:
    ListNode *head;
};
#endif