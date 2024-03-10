#include <iostream>
using namespace std;

void display(int *arr, int size);
void countingSort(int *arr, int size);

int main()
{
    int arr[10]{5, 5, 5, 6, 4, 4, 3, 18, 2, 10};
    countingSort(arr, 10);
}

void countingSort(int *arr, int size)
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

    int *outputArr = new int[size];
    for(int i{size - 1}; i >= 0; i -= 1)
    {
        outputArr[dummyArr[arr[i]] - 1] = arr[i];
        dummyArr[arr[i]] -= 1;
    }
    display(outputArr,size);
}

void display(int *arr, int size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}