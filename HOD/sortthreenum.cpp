
#include <iostream>
using namespace std;

void sortThreeNum(int *, int);
void display(int *, int);
int partition(int *, int, int);

int main()
{
    int arr[10]{9};
    sortThreeNum(arr, 1);
    display(arr, 1);
}

int partition(int *arr, int low, int high)
{
    int i{-1};
    int pivot{arr[high]};
    for (int j{}; j < high; j += 1)
    {
        if (arr[j] <= pivot)
        {
            i += 1;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void sortThreeNum(int *arr, int size)
{ 
    int maxIdx{};
    int secondMax{-1};
    int minIdx{};

    for (int i{1}; i < size; i += 1)
    {
        if (arr[i] > arr[maxIdx])
        {
            secondMax = maxIdx;
            maxIdx = i;
        }
        else if (arr[i] < arr[maxIdx])
        {
            if (secondMax == -1 || arr[i] > arr[secondMax])
                secondMax = i;
        }
    }

    if(secondMax == -1) return;

    swap(arr[secondMax], arr[size - 1]);
    int p = partition(arr, 0, size - 1);

    for (int i{}; i < size; i += 1)
    {
        if (arr[i] < arr[minIdx])
        {
            minIdx = i;
        }
    }
    swap(arr[p], arr[minIdx]);
    int q = partition(arr, 0, p);
}

void display(int *arr, int size)
{
    for (int i{}; i < size; i += 1)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
