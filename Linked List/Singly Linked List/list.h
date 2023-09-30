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

private:
    ListNode *head;
};
#endif