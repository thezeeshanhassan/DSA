#include <iostream>
using namespace std;

void display(int *arr, int &size);
void selectionSort(int *arr, int &size);

int main()
{
    int size = 5;
    int arr[5]{1, 5, 3, 2, 4};
    selectionSort(arr, size);
    display(arr, size);
}

void display(int *arr, int &size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
}
void selectionSort(int *arr, int &size)
{
    int k{};
    for (int i{}; i < size; i += 1)
    {
        for (int j = k = i; j < size; j += 1)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}