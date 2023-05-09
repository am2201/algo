#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval
{
    int start, end;
};

bool compare(Interval a, Interval b)
{
    return a.end < b.end;
}

int intervalScheduling(vector<Interval> &intervals)
{
    sort(intervals.begin(), intervals.end(), compare);
    int n = intervals.size();
    int count = 0, last_end = 0;
    for (int i = 0; i < n; i++)
    {
        if (intervals[i].start >= last_end)
        {
            count++;
            last_end = intervals[i].end;
        }
    }
    return count;
}

int main()
{
    vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {5, 7}, {6, 8}, {8, 10}};
    int maxIntervals = intervalScheduling(intervals);
    cout << "Maximum number of intervals: " << maxIntervals << endl;
    return 0;
}
