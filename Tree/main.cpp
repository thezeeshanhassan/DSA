#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree obj;
    obj.create();
    obj.preOrder();
    cout << endl;
    obj.levelOrder();
    obj.maxDepth();
    cout << endl;
    obj.minDepth();
    return 0;
}