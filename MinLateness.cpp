#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job
{
    int duration, deadline;
};

bool compare(Job a, Job b)
{
    return a.deadline < b.deadline;
}

int minimizingLateness(vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare);
    int n = jobs.size();
    int lateness = 0, current_time = 0;
    for (int i = 0; i < n; i++)
    {
        current_time += jobs[i].duration;
        lateness = max(lateness, current_time - jobs[i].deadline);
    }
    return lateness;
}

int main()
{
    vector<Job> jobs = {{3, 4}, {1, 2}, {4, 4}, {2, 3}, {5, 6}};
    int minLateness = minimizingLateness(jobs);
    cout << "Minimum lateness: " << minLateness << endl;
    return 0;
}
