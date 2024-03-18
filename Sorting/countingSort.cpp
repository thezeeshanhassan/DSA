#include <iostream>
using namespace std;

void display(int *, int &);
void countingSort(int *, int *,int &);

int main()
{
    int size{10};
    int arr[size]{5, 5, 5, 6, 4, 4, 3, 18, 2, 10};
    display(arr,size);
     int *outputArr = new int[size];
     countingSort(arr,outputArr,size);
     display(outputArr,size);
}

void countingSort(int *arr,int *outputArr, int &size)
{
    int max{};
    for (int i{1}; i < size; i += 1)
    {
        if (arr[i] > arr[max])
        {
            max = i;
        }
    }

    int *dummyArr = new int[arr[max] + 1];

    for (int i{}; i < arr[max] + 1; i += 1)
    {
        dummyArr[i] = 0;
    }

    for (int i{}; i < size; i += 1)
    {
        dummyArr[arr[i]] += 1;
    }

    for (int i{1}; i < arr[max] + 1; i += 1)
    {
        dummyArr[i] += dummyArr[i - 1];
    }

    for(int i{size - 1}; i >= 0; i -= 1)
    {
        outputArr[dummyArr[arr[i]] - 1] = arr[i];
        dummyArr[arr[i]] -= 1;
    }
}

void display(int *arr, int &size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}