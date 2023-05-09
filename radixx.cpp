#include <bits/stdc++.h>
using namespace std;

int mostdig(int arr[], int n)
{
    int m = 0;
    string k;
    for (int i = 0; i < n; i++)
    {
        k = to_string(arr[i]);
        m = max(m, (int)k.size());
    }
    return m;
}

void CS(int arr[], int n, int x)
{
    int f[10] = {0};
    for (int i = 0; i < n; i++)
    {
        f[(arr[i] / (int)pow(10, x)) % 10]++;
    }
    for (int i = 0; i <= 9; i++)
    {
        cout << f[i] << " . ";
        f[i] += f[i - 1];
    }
    int out[n];
    for (int i = n - 1; i >= 0; i--)
    {
        // int index = arr[i]/
        out[f[(arr[i] / (int)pow(10, x)) % 10] - 1] = arr[i];
        // f[(arr[i] / (int)pow(10, x)) % 10]--;
        cout << out[f[(arr[i] / (int)pow(10, x)) % 10] - 1] << " ";
        f[(arr[i] / (int)pow(10, x)) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }
}

void RS(int arr[], int n)
{
    int maxx = mostdig(arr, n);
    int c = 0;
    while (c < maxx)
    {
        cout << c << "  " << maxx << "\n";
        CS(arr, n, c);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        c++;
    }
}

int main()
{
    int arr[] = {3197, 1023, 1059, 2015, 8827, 6523, 4236};
    RS(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}