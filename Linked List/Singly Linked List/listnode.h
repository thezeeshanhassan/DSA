#ifndef listnode_h
#define listnode_h

class ListNode
{
    friend class ListADT;
    int data;
    ListNode *next;
};

#endif