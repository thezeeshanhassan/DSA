#include<iostream>
using namespace std;
int partition(int *arr,int low, int high);
void display(int *arr,int size);

int main(){
    int arr[10]{3,2,1,1,2,3,3,2,1,1};
    int index1 = partition(arr,0,9);
    display(arr,10);
    cout<<"Index is : "<<index1<<endl;
    int index2 = partition(arr,0,index1);
    display(arr,10);
    cout<<"Index is : "<<index2<<endl;

    return 0;
}

int partition(int *arr,int low, int high)
{
    int pivot = arr[high];
    int i{-1};

    for(int j{}; j < high; j += 1)
    {
        if(arr[j] <= pivot)
        {
            i += 1;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i + 1],arr[high]);
    return i + 1;
}

void display(int *arr,int size)
{
    for(int i{}; i < size; i += 1)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}