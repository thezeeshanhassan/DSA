#include <iostream>
using namespace std;

void display(int *arr, int size);
void countingSort(int *arr, int size);

int main()
{
    int arr[11]{5, 5, 5, 5, 4, 4, 4, 3, 2, 2, 10};
    countingSort(arr, 11);
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

    display(dummyArr, arr[max] + 1);

    for (int i{}; i < size; i += 1)
    {
        dummyArr[arr[i]] += 1;
    }
    display(dummyArr, arr[max] + 1);

    for (int i{1}; i < arr[max] + 1; i += 1)
    {
        dummyArr[i - 1] += dummyArr[i];
    }
    display(dummyArr, arr[max] + 1);
}

void display(int *arr, int size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}