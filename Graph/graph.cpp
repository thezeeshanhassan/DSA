#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    string color;
    Node(int val)
    {
        data = val;
        next = nullptr;
        color = "White";
    }
};

class Graph{
    public:

    int totalNumberofV;
    Node **adjList;

    Graph(int val){
        totalNumberofV = val;
        adjList = new Node*[totalNumberofV];
        for(int i{}; i < totalNumberofV; i += 1)
        {
            adjList[i] = nullptr;
        }
    }
    void createGraph(int src, int des)
    {
        //// For Directed
        Node *newNode = new Node(des);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        //// If UnDirected
        newNode = new Node(src);
        newNode->next = adjList[des];
        adjList[des] = newNode; 
    }

    void printGraph()
    {
        for(int i{1}; i < totalNumberofV; i += 1)
        {
            cout<< i <<" = ";
            Node *ptr = adjList[i];
            while(ptr)
            {
                cout<<ptr->data<<' '<<ptr->color<<' ';
                ptr = ptr->next;
            }
            cout<<endl;
        }
    }

    void BFS(Node* src)
    {
        Node* u = src;
        u->color = "Grey";
        queue<Node*> q;
        q.push(u);
        cout<<u->data<<' ';

        while(!q.empty())
        {
            u = q.front();
            q.pop();
            Node *temp = u->next;
            while(temp) 
            {
                if(temp->color == "White")
                {
                    temp->color = "Grey";
                    q.push(temp);
                    cout<<temp->data<<' ';
                }
                temp = temp->next;
            }
            u->color = "Black";
        }

    }
     void BFSfunction()
    {
        for(int i{1}; i < totalNumberofV; i += 1)
        {
            Node *ptr = adjList[i];
            BFS(ptr);
        }
    }
};

int main() {
    Graph obj(6);
    obj.createGraph(1,2);
    obj.createGraph(1,5);
    obj.createGraph(2,5);
    obj.createGraph(2,4);
    obj.createGraph(2,3);
    obj.createGraph(3,4);
    obj.createGraph(4,5);
    obj.printGraph();
    obj.BFSfunction();

}
