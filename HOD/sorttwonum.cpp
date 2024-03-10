<<<<<<< HEAD
#include<iostream>
using namespace std;

void sortTwoNum(int *,int);
void display(const int *,int);

int main()
{
    int arr[10] = {0,0,0,0,1,1,1,1,0,0};
    sortTwoNum(arr,10);
    display(arr,10);

    return 0;
}

void sortTwoNum(int *arr,int size)
{
    int start{};
    bool flag{false};
    
    for(int i{1}; i < size; i += 1)
    {
        if(arr[i] < arr[start])
        {
            swap(arr[i],arr[start]);
            start += 1;
            flag = true;
        }
    }

    if(flag == false)
    {
        int num = arr[start];
        int high{size - 1};
        for(int i{}; i < size; i += 1)
        {
            if(arr[start] == num)
            {
                start += 1;        
            }
            if(arr[high] > num)
            {
                high -= 1;
            }
            else if(arr[start] > arr[high])
            {
                swap(arr[start],arr[high]);
                start += 1;
                high -= 1;
            } 
        }
    }



    // int pivot = arr[size - 1];
    // int low{};
    // int i{low - 1};

    // for(int j{}; j < size - 2; j += 1)
    // {
    //     if(arr[j] < pivot)
    //     {

    //     }
    // }
}

void display(const int *arr,int size)
{
    for(int i{}; i < size; i += 1)
    {
        cout<<arr[i]<< ' ';
=======
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
>>>>>>> 98851456a5f96a9581d2e936c36b54332a3f2c51
    }
}