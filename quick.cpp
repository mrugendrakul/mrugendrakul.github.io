#include <iostream>
using namespace std;

int partion(int arr[], int low, int high);
void print(int a[], int n);

void quick(int arr[], int low, int high)
{
    if (high > low)
    {
        int j = partion(arr, low, high);
        quick(arr, low, j - 1);
        quick(arr, j + 1, high);
    }
}

int partion(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i, j;
    i = low + 1;
    j = high;
    int temp=0;
        int tem=0;

    //cout <<"here 1 :"<<arr[j]<<endl;
    while (i <= j)
    {
        if (arr[i] < pivot )
        {
            i++;
        }
        if (arr[j] > pivot)
        {
            j--;
        }
        if (i<=j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    tem = arr[low];
    arr[low] = arr[j];
    arr[j] = tem;

    print(arr, high);
    cout<<endl;
    return j;
}

void print(int a[], int n)
{
    for (int i; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int arrr[6] = {10, 7, 8, 9, 1, 5};
    print(arrr, 6);
    quick(arrr,0,5);
    print(arrr,6);
}
