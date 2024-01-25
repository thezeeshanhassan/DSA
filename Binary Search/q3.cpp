#include<iostream>
using namespace std;

int binarySearch(int *arr,int,int);

int main()
{
    return 0;
    cout<<"hello";
}

int binarySearch(int *arr,int size,int key)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(key == arr[mid] && key < arr[mid + 1])
        {
            return mid + 1;
        }

        else if(key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

    }
    if(start == size)
    {
        return -1;
    }
    return start + 1;

}