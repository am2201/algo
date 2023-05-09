#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int randomPartition(int arr[], int left, int right)
{
    srand(time(nullptr));
    int pivotIndex = rand() % (right - left + 1) + left;
    swap(arr[pivotIndex], arr[right]);
    return partition(arr, left, right);
}

int randomizedSelect(int arr[], int left, int right, int k)
{
    if (left == right)
    {
        return arr[left];
    }
    int q = randomPartition(arr, left, right);
    int pos = q - left + 1;
    if (pos == k)
    {
        return arr[q];
    }
    else if (pos > k)
    {
        return randomizedSelect(arr, left, q - 1, k);
    }
    else
    {
        return randomizedSelect(arr, q + 1, right, k - pos);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int kthSmallest = randomizedSelect(arr, 0, n - 1, k);
    cout << "K-th smallest element is: " << kthSmallest << endl;
    return 0;
}
