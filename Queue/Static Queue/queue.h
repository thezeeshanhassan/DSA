#ifndef queue_h
#define queue_h

class queueADT
{
public:
    queueADT(int &);
    void enQueue(int);
    int deQueue();
    bool isFull() const;
    bool isEmpty() const;
    int size() const;
    void display() const;
    ~queueADT();
    void clear();

private:
    int *queueArray;
    int capacity;
    int count;
    int front;
    int rare;
};

#endif
