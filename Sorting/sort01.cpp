#include <iostream>
using namespace std;

void sortArry(int *arr, int);
void display(int *arr, int);

int main()
{
    int arr[7] = {1, 0, 0, 1, 1, 1, 0};
    sortArry(arr, 7);
    display(arr, 7);
}

void sortArry(int *arr, int size)
{
    int low{};
    int mid{};
    int high{size - 1};

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low += 1;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high -= 1;
        }
        mid += 1;
    }
}

void display(int *arr, int size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
}