#include <iostream>
using namespace std;

void preorder(int arr[], int n, int i)
{
    if (i >= n)
    {
        return;
    }
    cout << arr[i] << " ";
    preorder(arr, n, 2 * i + 1);
    preorder(arr, n, 2 * i + 2);
}

void postorder(int arr[], int n, int i)
{
    if (i >= n)
    {
        return;
    }
    postorder(arr, n, 2 * i + 1);
    postorder(arr, n, 2 * i + 2);
    cout << arr[i] << " ";
}

void inorder(int arr[], int n, int i)
{
    if (i >= n)
    {
        return;
    }
    inorder(arr, n, 2 * i + 1);
    cout << arr[i] << " ";
    inorder(arr, n, 2 * i + 2);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Preorder traversal: ";
    preorder(arr, n, 0);
    cout << endl;
    return 0;
}
