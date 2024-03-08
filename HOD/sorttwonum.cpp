#include <iostream>
using namespace std;

void sortTwoNum(int *, int);
void display(const int *, int);

int main()
{
    int arr[3]{0, 1, 0};
    display(arr, 3);
    sortTwoNum(arr, 3);
    cout << endl;
    display(arr, 3);
}

void sortTwoNum(int *arr, int size)
{
    int min{arr[0]};

    for (int i{1}; i < size; i += 1)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int i{-1};

    for (int j{0}; j < size; j += 1)
    {
        if (arr[j] == min)
        {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
}

void display(const int *arr, int size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
}