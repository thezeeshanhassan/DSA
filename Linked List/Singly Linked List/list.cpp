#include <iostream>
#include "list.h"

using namespace std;

ListADT::ListADT() : head(nullptr){};
void ListADT::appenedNode(int data)
{
    ListNode *newNode = new ListNode();
    newNode->data = data;
    if (!head)
    {
        head = newNode;
    }
    else
    {
        ListNode *ptr = head;
        while (!ptr->next)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void ListADT::insertNode(int data)
{
    ListNode *newNode = new ListNode();
    newNode->data = data;

    if (newNode->data < head->data)
    {
        newNode->next = head->next;
        head = newNode;
    }

    else
    {
        ListNode *ptr = new ListNode();
        while (newNode->data < ptr->data)
        {

            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}
