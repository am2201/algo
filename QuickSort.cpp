#include <iostream>
#include <cstdlib>
using namespace std;
int partition(int *arr, int p, int r)
{
    int pivot = arr[p];
    int i = p - 1;
    int j = r + 1;
    while (true)
    {
        do
        {
            j--;
        } while (arr[j] > pivot);
        do
        {
            i++;
        } while (arr[i] < pivot);
        if (i < j)
            swap(arr[i], arr[j]);
        else
        {
            // swap(arr[p], arr[i - 1]);
            // return i - 1;
            return j;
        }
    }
}
// void r_partition(int *arr, int l, int h)
// {
//     srand(time(0));
//     int x = (l + (rand() % (h - l + 1)));
//     swap(arr[l], x);
//     partition(arr, x, h);
// }
void QS(int *arr, int i, int j)
{
    if (i < j)
    {
        int pivot = partition(arr, i, j);

        QS(arr, i, pivot);
        QS(arr, pivot + 1, j);
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
    QS(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}