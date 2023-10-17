#include <iostream>
using namespace std;

void swap(int &el1, int &el2)
{
    int temp = el1;
    el1 = el2;
    el2 = temp;
}

void bubbleSort(int *arr, int &size)
{
    int count{};
    for (int i{}; i < size - 1; i++)
    {
        count = 0;
        for (int j{}; j < size - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
                count = 1;
            }
        }
        if (count == 0)
        {
            break;
        }
    }
}

void display(int *arr, int &size)
{
    for (int idx{}; idx < size; idx += 1)
    {
        cout << arr[idx] << ' ';
    }
}

int main()
{
    int size = 5;
    int arr[5]{1, 5, 3, 2, 1};
    bubbleSort(arr, size);
    display(arr, size);

    return 0;
}