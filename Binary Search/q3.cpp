#include<iostream>
using namespace std;

int countElement(int *arr,int,int);

int main()
{
    int arr[8] = {1, 2, 2, 2, 4, 5, 5, 6};
}

int countElement(int *arr, int size, int key)
{
    int count{}
    int start{};
    int end{size -1};

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(key == arr[mid])
        {
            
        }
        if(key < arr[mid])
        {
            end = mid - 1;
        }
        else 
        {
            start += 1;
        }
    }
}