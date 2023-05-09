#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= n && arr[largest] < arr[l])
    {
        largest = l;
    }
    if (r <= n && arr[largest] < arr[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n/2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
}

void HS(int arr[], int n)
{
    for (int i = n; i >= 1; i--)
    {
        swap(arr[i], arr[1]);
        heapify(arr, i - 1, 1);
    }
}
int main()
{
    int arr[] = {0, 1, 4, 3, 5, 2};
    buildHeap(arr, 5);
    HS(arr, 5);
    cout << "Array :";
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}