#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(vector<double> &arr)
{
    // Find the maximum element in the array
    double max_num = *max_element(arr.begin(), arr.end());

    // Create the buckets
    vector<vector<double>> buckets(arr.size());

    // Place each element in the appropriate bucket
    for (int i = 0; i < arr.size(); i++)
    {
        int bucket_index = arr[i] * arr.size() / (max_num + 1);
        buckets[bucket_index].push_back(arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < arr.size(); i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    // Example usage
    vector<double> arr = {0.42, 0.32, 0.67, 0.84, 0.12, 0.53, 0.29, 0.67};
    bucketSort(arr);
    for (double num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
