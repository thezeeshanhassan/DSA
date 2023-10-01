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
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        // newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void ListADT::insertNode(int data)
{

    ListNode *newNode = new ListNode();
    newNode->data = data;

    ListNode *ptr;
    ListNode *previousNode = nullptr;
    // If Linked List is Empty Insert Node at Head
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    // OtherWise Insert In Sorted Order
    else
    {
        ptr = head;
        previousNode = nullptr;

        while (ptr != nullptr && ptr->data < data)
        {
            previousNode = ptr;
            ptr = ptr->next;
        }

        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = ptr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = ptr;
        }
    }
}

void ListADT::deleteNode(int position)
{
    if (!head)
    {
        return;
    }

    else if (position == 1)
    {
        ListNode *ptr = head;
        head = ptr->next;
        delete ptr;
    }

    else
    {
        ListNode *ptr = head;
        ListNode *q = nullptr;
        for (int traverse{}; traverse < position - 1; traverse += 1)
        {
            q = ptr;
            ptr = ptr->next;
        }
        q->next = ptr->next;
        delete ptr;
    }
}

void ListADT::display() const
{
    ListNode *ptr = head;
    while (ptr)
    {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
}

void ListADT::reverse()
{
    ListNode *ptr = head;
    ListNode *prev = nullptr;
    ListNode *current = nullptr;

    while (ptr)
    {
        current = prev;
        prev = ptr;
        ptr = ptr->next;

        prev->next = current;
    }
    head = prev;
}