#include <iostream>
using namespace std;
#define MIN -999999;

int m(int arr[], int n)
{
    int m = arr[0];
    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }
    return m;
}

void CS(int arr[], int n)
{
    int max = m(arr, n);
    int f[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        f[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        f[i] += f[i - 1];
    }
    int out[n];
    for (int i = n - 1; i >= 0; i--)
    {
        out[--f[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }
}

int main()
{
    int arr[] = {1, 4, 3, 5, 2};
    CS(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}