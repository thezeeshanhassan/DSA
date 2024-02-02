// Write functions in C++ to solve the following problems.
// These problems are, in a sense, related to Binary Search algorithm done in the class. 
// ALso show  that the Time Complexity is O(logn) in each case.

#include<iostream>
using namespace std;

int binarySearch(int *arr, int size, int key);

int main()
{
    int arr[6] = {1, 2, 4, 5, 5, 6};
    cout<<binarySearch(arr,6,2)<<endl;
    cout<<binarySearch(arr,6,3)<<endl;
    cout<<binarySearch(arr,6,5)<<endl;
    cout<<binarySearch(arr,6,7)<<endl;

    return 0;
}

int binarySearch(int *arr,int size,int key)
{
    int start{0};
    int end{size - 1};

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if(key == arr[mid] && key != arr[mid - 1] && mid > -1)
        {
            return mid;
        }

        else if(key == arr[mid - 1] || key < arr[mid])
        {
            end = mid - 1;
        }
        
        else 
        {
            start = mid + 1;
        }
    }

    return start;
}