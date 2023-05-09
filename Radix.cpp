#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void radixSort(vector<int> &arr)
{
    // Find the maximum number in the array
    int max_num = *max_element(arr.begin(), arr.end());

    // Count the number of digits in the maximum number
    int num_digits = 0;
    while (max_num > 0)
    {
        max_num /= 10;
        num_digits++;
    }

    // Create buckets for each digit
    vector<vector<int>> buckets(10);

    // Iterate through each digit and sort the numbers into the appropriate bucket
    for (int i = 0; i < num_digits; i++)
    {
        // Place each number into the appropriate bucket based on the current digit
        for (int j = 0; j < arr.size(); j++)
        {
            int digit = (arr[j] / static_cast<int>(pow(10, i))) % 10;
            buckets[digit].push_back(arr[j]);
        }

        // Replace the original array with the sorted elements from the buckets
        int index = 0;
        for (int k = 0; k < 10; k++)
        {
            for (int l = 0; l < buckets[k].size(); l++)
            {
                arr[index++] = buckets[k][l];
            }
            buckets[k].clear();
        }
    }
}

int main()
{

    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
