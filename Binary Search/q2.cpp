#include<iostream>
using namespace std;

int binarySearch(int *arr, int size, int key);

int main()
{
    int arr[6] = {1, 2, 4, 5, 5, 7};
    cout<<binarySearch(arr,6,2)<<endl;
    cout<<binarySearch(arr,6,3)<<endl;
    cout<<binarySearch(arr,6,7)<<endl;
    cout<<binarySearch(arr,6,9)<<endl;

    return 0;
}

int binarySearch(int *arr,int size,int key)
{
    int start{0};
    int end{size - 1};

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(key == arr[mid] && key != arr[mid + 1] && mid < size - 1)
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
    return start ;
}