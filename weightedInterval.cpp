#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval
{
    int start, end, weight;
};

bool compare(Interval a, Interval b)
{
    return a.end < b.end;
}

int binarySearch(vector<Interval> &intervals, int index)
{
    int left = 0, right = index - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (intervals[mid].end <= intervals[index].start)
        {
            if (intervals[mid + 1].end <= intervals[index].start)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int weightedIntervalScheduling(vector<Interval> &intervals)
{
    sort(intervals.begin(), intervals.end(), compare);
    int n = intervals.size();
    vector<int> dp(n, 0);
    dp[0] = intervals[0].weight;
    for (int i = 1; i < n; i++)
    {
        int inclProfit = intervals[i].weight;
        int index = binarySearch(intervals, i);
        if (index != -1)
        {
            inclProfit += dp[index];
        }
        dp[i] = max(inclProfit, dp[i - 1]);
    }
    return dp[n - 1];
}

int main()
{
    vector<Interval> intervals = {{1, 4, 5}, {2, 5, 6}, {4, 7, 2}, {6, 8, 7}, {5, 9, 3}, {7, 10, 4}};
    int maxProfit = weightedIntervalScheduling(intervals);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
