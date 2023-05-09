#include <iostream>
using namespace std;
int *merge(int *arr, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    int *b = new int[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            b[k] = arr[i++];
        else
            b[k] = arr[j++];
        k++;
    }
    while (j <= r)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    j = l;
    for (int a = 0; a < r - l + 1; a++)
    {
        arr[j++] = b[a];
    }
    return arr;
    delete[] b;
}
void MS(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        MS(arr, l, mid);
        MS(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int *arr = new int[5];
    cout << "Enter the Elements :" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    MS(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}