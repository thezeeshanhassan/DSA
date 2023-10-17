#include <iostream>
using namespace std;

void insertionSort(int *arr, int size);
void display(int *arr, int &size);

int main()
{
    int size = 5;
    int arr[5]{5, 3, 6, 2, 1};
    insertionSort(arr, size);
    display(arr, size);

    return 0;
}

void insertionSort(int *arr, int size)
{
    for (int i{1}; i < size; i += 1)
    {
        int j = i - 1;
        int val = arr[i];
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}

void display(int *arr, int &size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
}
